#pragma once
#include "Human.h"
#include <string>
#include <iostream>
using namespace std;

class Bus
{
	Human salon[20]; // ����������� �������� - 20 ����������
	int cur; // ���������� ���������� � ������� ������ � �������� � ��� �� - ��������� �� ������ �������� ���������
public:
	Bus()
	{
		cur = -1; // �� 0, ��� ��� 0 - ��� ��� ����� ���� ���� ��������
	}
	
	void Clear() // ������� ���� �� ��������
	{
		cur -= 1;
	}
	
	bool IsFull() // �������� �� ��, ��� ������
	{
		return cur == 19 ? true : false; // ���� ������ ���������� 19, �� ����� ���������� 20
	}

	bool IsEmpty() // �������� �� ��, ��� ������
	{
		return cur == -1 ? true : false;
	}

	int Getcur()
	{
		return cur + 1;
	}

	void Push(Human P) // ������� ��������. ���� ������� �� ������, ��������� ��� � ������
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

	string Pop() // ����  ������� �� ������, ���������� ��������� � ���������� ��� ���
	{
		if (!IsEmpty())
		{
			return salon[cur].name;
			cur--;
		}
		else return "Empty";
	}

};
