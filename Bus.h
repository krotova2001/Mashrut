#pragma once
#include "Human.h"
#include <string>
#include <iostream>
using namespace std;

class Bus
{
	Human salon[20]; // вместимость автобуса - 20 пассажиров
	int cur; // количество пассажиров в текущий момент в автобусе и это же - указатель на индекс крайнего пассажира
public:
	Bus()
	{
		cur = -1; // не 0, так как 0 - это уже может быть один пассажир
	}
	
	void Clear() // высадка всех из автобуса
	{
		cur -= 1;
	}
	
	bool IsFull() // проверка на то, что полный
	{
		return cur == 19 ? true : false; // если индекс последнего 19, то всего пассажиров 20
	}

	bool IsEmpty() // проверка на то, что пустой
	{
		return cur == -1 ? true : false;
	}

	int Getcur()
	{
		return cur + 1;
	}

	void Push(Human P) // заходит пассажир. Если автобус не полный, принимаем его в массив
	{
		if (cur<19)
		{
			salon[++cur] = P;
		}
	}

	void Show()
	{
		for (int i = 0; i < cur+1; i++)
		{
			cout << salon[i].name << "; ";
		}
	}

	string Pop() // если  автобус не пустой, выкидываем пассажира и возвращаем его имя
	{
		if (!IsEmpty())
		{
			return salon[cur].name;
			cur--;
		}
		else return "Empty";
	}

};
