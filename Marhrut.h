/*класс марщрута - трассы реализован в виде кольцевой очереди на основе динамического массива,
так как количество остановок известно заранее, марщрут определен. ¬ключает в себ€ автобусы
*/

#pragma once
#include "Bus.h"
#include <iostream>
using namespace std;

class Marshrut
{
	int count; // колчество автобусов на маршруте
	int max_count; // количество остановок на маршруте == максимальное кол-во автобусов на нем
	Bus* start; // ссылка на начало маршрута (конечна€ остановка)
public:
	Marshrut() :count{ 0 }, start{ nullptr }{} // конструктор по умолчанию
	Marshrut(int t) // конструктор с указанием длины маршрута
	{
		max_count = t;
		count = 0;
		start = new Bus[max_count];
	}

	void Add(Bus a) //добавление на маршрут
	{
		if (!Overflow())
		{
			start[count++] = a;
		}
	}

	bool Pop()
	{
		if (!Empty())
		{
			Bus temp = start[0];
			for (int i = 1; i < max_count; i++)
			{
				start[i - 1] = start[i];
			}
			start[max_count - 1] = temp;
			return true;
		}
		return false;
	}
	
	void Show() // просмотре всех остановок на маршруте
	{
		for (int i = 0; i < max_count; i++)
		{
			start[i].Show();
			cout << "\n----------\n";
		}
	}

	bool Empty() // проверка на пустоту
	{
		return (count == 0) ? true : false;
	}

	int Count() // показать количество автобусов на маршруте
	{
		return count;
	}

	bool Overflow() //проверка на заполненность
	{
		return count==max_count;
	}
	
	~Marshrut()
	{
		if(start != nullptr) delete[]start;
	}
};