#ifndef HEADER
#define HEADER

#pragma warning (disable: 4996)
#include "stdio.h"
#include <iostream>
#include <string>
#include <math.h>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;

struct Points
{
	double x;
	double y;
};

struct Time
{
	int hour;
	int minute;
};

void speed(vector <Time> v2, vector <Points> v1);
void getCycles(vector <Points> v1);
void intersection(vector <Points> v1);
void getData(string &str, struct Points *loc, struct Time *timestamps);
double direction(double pix, double piy, double pjx, double pjy, double pkx, double pky);
void crosspoint(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double *crossX, double *crossY);

#endif