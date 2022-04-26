/*����� �������� - ������ ���������� � ���� ��������� ������� �� ������ ������������� �������,
��� ��� ���������� ��������� �������� �������, ������� ���������. �������� � ���� ��������
*/

#pragma once
#include "Bus.h"
#include <iostream>
using namespace std;

class Marshrut
{
	int count; // ��������� ��������� �� ��������
	int max_count; // ���������� ��������� �� �������� == ������������ ���-�� ��������� �� ���
	Bus* start; // ������ �� ������ �������� (�������� ���������)
public:
	Marshrut() :count{ 0 }, start{ nullptr }{} // ����������� �� ���������
	Marshrut(int t) // ����������� � ��������� ����� ��������
	{
		max_count = t;
		count = 0;
		start = new Bus[max_count];
	}

	void Add(Bus a) //���������� �� �������
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
	
	void Show() // ��������� ���� ��������� �� ��������
	{
		for (int i = 0; i < max_count; i++)
		{
			start[i].Show();
			cout << "\n----------\n";
		}
	}

	bool Empty() // �������� �� �������
	{
		return (count == 0) ? true : false;
	}

	int Count() // �������� ���������� ��������� �� ��������
	{
		return count;
	}

	bool Overflow() //�������� �� �������������
	{
		return count==max_count;
	}
	
	~Marshrut()
	{
		if(start != nullptr) delete[]start;
	}
};