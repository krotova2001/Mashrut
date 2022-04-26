//класс пассажира - элемента стэка

#pragma once
#include <string>
using namespace std;

struct Human
{
	string name; // имя
	Human(){}
	Human(string s) 
	{
		name = s;
	}
};
