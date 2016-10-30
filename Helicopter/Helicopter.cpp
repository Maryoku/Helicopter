#include "header.h"

vector <Points> v1; //?
vector <Time> v2;

Points loc;
Time timestamps;

int main()
{
	SetConsoleCP(1251); // russian
	SetConsoleOutputCP(1251);

	ifstream input("test4.txt"); //ifstream
	string data;

	while (!input.eof())
	{
		getline(input, data); //getline
		getData(data);
		v1.push_back(loc);
		v2.push_back(timestamps); //push_back add new element in vector
	}

	speed(v2, v1);
	printf("\n");
	getCycles(v1);
	printf("\n");
	intersection(v1);
	printf("\n");
}

