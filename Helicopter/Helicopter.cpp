#include "header.h"

int main()
{
	SetConsoleCP(1251); // russian
	SetConsoleOutputCP(1251);

	ifstream input("test2.txt");
	string data;

	vector <Points> v1;
	vector <Time> v2;

	Points loc;
	Time timestamps;

	while (!input.eof())
	{
		getline(input, data);
		getData(data, &loc, &timestamps);
		v1.push_back(loc);
		v2.push_back(timestamps);
	}

	speed(v2, v1);
	printf("\n");
	getCycles(v1);
	printf("\n");
	intersection(v1);
	printf("\n");
}

