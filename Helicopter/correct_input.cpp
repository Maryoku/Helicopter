#include "header.h"

void getData(string &data, struct Points *loc, struct Time *timestamps)
{ 
	regex templ("(\[0-9]+)[\.\,]([0-9]+) (\[0-9]+)[\.\,]([0-9]+) (\[0-1][0-9]|2[0-3]):(\[0-5][0-9])");
	if (!regex_match(data, templ))
	{
		printf("Error!\nCheck the input data.\n");
		exit(1); // exit with error
	}
	else
	{
		string new_x = "$1.$2";
		string new_y = "$3.$4";
		string new_hour = "$5";
		string new_minute = "$6";
		(*loc).x = atof(regex_replace(data, templ, new_x).c_str());
		(*loc).y = atof(regex_replace(data, templ, new_y).c_str());
		(*timestamps).hour = atoi(regex_replace(data, templ, new_hour).c_str());
		(*timestamps).minute = atoi(regex_replace(data, templ, new_minute).c_str());
	}
}