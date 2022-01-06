#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <Windows.h>


using namespace std;
//using std::cout;
//using std::endl;
//using std::string;
//using std::cin;
//using std::swap;


struct human
{
	char name[64];
	char second_name[64];
	int age;
	string number;
};

void output(human* data, int n)
{

	cout << "№\t" << "name\t" << "surname\t" << "age\t" << "phone number" << endl;
	cout << "=========================================================" << endl;
	setlocale(0, "C");
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << '\t' << data[i].name << '\t' << data[i].second_name
			<< '\t' << data[i].age << '\t' << data[i].number << endl;
	}
	setlocale(LC_ALL, "rus");
}  //cm1
void input(human* data, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "name: ";
		cin >> data[i].name;
		cout << "surname: ";
		cin >> data[i].second_name;
		cout << "age: ";
		cin >> data[i].age;
		cout << "phone number: ";
		cin >> data[i].number;
		cin.get();
		cout << endl;
	}

};
void remov(int rem, human* data, int n)
{

	for (int i = rem; i < n; i++)
	{
		data[rem - 1] = data[rem];
	}
	n = n - 1;
};
void sor(human* data, int n)
{
	human temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (int(data[i].second_name) < int(data[j].second_name))
			{
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (int(data[i].second_name) == int(data[j].second_name) && int(data[i].name) < int(data[j].name))
			{
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
}
void cou()
{
	cout << "1\t" << "-\t" << "input" << endl
		<< "2\t" << "-\t" << "output" << endl
		<< "3\t" << "-\t" << "remove" << endl
		<< "4\t" << "-\t" << "sort" << endl
		<< "5\t" << "-\t" << "exit" << endl
		<< "6\t" << "-\t" << "clear" << endl
		<< "help\t" << "-\t" << "command list" << endl;
}
int main()
{
	int n = 0;
	cout << "array size:";
	cin >> n;
	human* data = new  human[n];
	input(data, n);



	int ans = 0;
	while (ans != 1)
	{
		string l;
		cin >> l;
		int r = 0;
		if (l.size() == 4 && l == "help")
		{
			cou();
			continue;
		}
		else
		{
			if (r > 2)
			{
				cout << "really dumb XD" << endl;
				cout << "bye bye" << endl;
				exit(0);
			}
			if (l.size() != 1 && l.size() != 4)
			{
				cout << "blunt?" << endl;
				r++;
				continue;
			}
		}
		int com = int(l[0]) - 48;

		if (com == 1)
		{
			cout << "array size:";
			cin >> n;
			input(data, n);
		}
		if (com == 2)
		{
			output(data, n);
		}
		if (com == 3)
		{
			int rem;
			cout << "№ line" << endl;
			cin >> rem;
			remov(rem, data, n);
		}
		if (com == 4)
		{
			sor(data, n);
		}
		if (com == 5)
		{
			system("cls");
			ans++;

		}
		if (com == 6)
		{
			system("cls");
		}

	}
	return 0;
}