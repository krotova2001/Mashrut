/*
Задачу с маршрутками проще сделать на массивах, так как конечные размеры предметом нам известны.
СИльно помог дидактический материал.
Сам маршрут с автобусами - это циклическая очередь, маршрутки -это стэки. Пассажиры - элементы этих стэков.
*/

#include <iostream>
#include "Marhrut.h"
using namespace std;

int main()
{
    Human Bob("Bob");
    Human Fil("Fil");
    Bus A;
    A.Push(Bob);
    A.Push(Fil);
    Marshrut BB(20);
    
    BB.Add(A);
    BB.Show();
    BB.Pop();
    BB.Show();
    
}
