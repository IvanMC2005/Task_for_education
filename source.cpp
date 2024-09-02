#include <iostream>
#include <clocale>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <stdexcept>
#include "header.h"
using namespace std;
List::List(List && other) //��
{
    current_length = other.current_length;
    queuelength = other.queuelength;
    front = other.front;
    tail = other.tail;
    other.front = other.tail = nullptr;
}
List::List( List & other )//��������
{
    Data odt;
    int k = other.current_length;
    queuelength = other.queuelength;
    current_length = 0;
    front = tail = nullptr; //�������� ����������
    while(k)
    {
        odt = other.delete_elem();
        add_elem(odt);
        other.add_elem(odt);
        k--;
    }
}
List & List::operator= ( List & other) //������
{
    //if (other.Empty()) return const_cast<List &>(other);
    if (this == &other) return const_cast<List &>(other);
    Data odt;
    int k = other.current_length;
    queuelength = other.queuelength;
    while(!Empty()) delete_elem();
    while(k)
    {
        odt = other.delete_elem();
        add_elem(odt);
        other.add_elem(odt);
        k--;
    }
    return *this;
}
List & List::operator= (List && other) //��
{
    current_length = other.current_length;
    queuelength = other.queuelength;
    front = other.front;
    tail = other.tail;
    other.front = other.tail = nullptr;
    return *this;
}
List::List (int ned) //��
{
    queuelength = ned;
    current_length = 0;
    front = tail = nullptr;//�������� ����������
}
List::List()//��
{
    current_length = queuelength = 0;
    front = tail = nullptr;//�������� ����������
}
List::~List()//��
{
    cout << "���������� ������ List\n";
    if (front)
    {
        node * temp = front;
        while(front)//���� �������� ���� ��������� �������
        {
            front = front->next;
            delete temp;
            temp = front;
        }
    }
}
int List::add_elem(Data item)//��
{
    if (Full()) return 0;
    node* temp = new(nothrow) node;
    if (temp == nullptr) return 0;
    temp->data = item;
    temp->next = nullptr;
    if (front == nullptr)
    {
        front = tail = temp;
        current_length++;
        return 1;
    }
    tail->next = temp;
    tail = tail->next;
    current_length++;
    return 1;
}
Data List::delete_elem()//��
{
    if (!Empty())
    {
        Data inf = front->data;
        node * temp = front;
        front = front->next;
        delete temp;
        current_length--;
        return inf;
    }
    throw invalid_argument("������� �������� �������� ������ �������\n");
}
Data List::ndread()//��
{
    if (!Empty())
        return front->data;
    throw invalid_argument("������� ������ �������� �� ������ �������\n");
}
bool List::Full() const //��
{
    if (queuelength <= 0)
    {
        node * temp = new (nothrow) node;
        if (temp == nullptr) return true;
        delete temp;
        return false;
    }
    else
    {
        return current_length == queuelength;
    }
}
bool List::Empty() const//��
{
    return current_length == 0;
}
Massive::Massive( Massive && other)//��
{
    current_length = other.current_length;
    front = other.front;
    tail = other.tail;
    inf = other.inf;
    other.inf = nullptr;
}
Massive::Massive(Massive & other)//��
{
    Data odt;
    int k = other.current_length;
    current_length = 0;
    queuelength = other.queuelength;
    inf = new Data[queuelength];
    front = 0;
    tail = queuelength - 1;
    while(k)
    {
        odt = other.delete_elem();
        add_elem(odt);
        other.add_elem(odt);
        k--;
    }
}
Massive & Massive::operator= ( Massive & other)//��
{
    if (&other == this) return other;
    if (inf)
        delete[] inf;
    Data odt;
    int k = other.current_length;
    current_length = 0;
    queuelength = other.queuelength;
    inf = new Data[queuelength];
    front = 0;
    tail = queuelength - 1;
    while(k)
    {
        odt = other.delete_elem();
        add_elem(odt);
        other.add_elem(odt);
        k--;
    }
    return *this;
}
void Massive::operator= ( Massive && other)//��
{
    if (inf)
        delete[] inf;
    current_length = other.current_length;
    front = other.front;
    tail = other.tail;
    inf = other.inf;
    other.inf = nullptr;
}
Massive::Massive(int n)//��
{
    current_length = 0;
    queuelength = n;
    inf = new Data[queuelength];
    front = 0;
    tail = queuelength - 1;
}
Massive::~Massive()//��
{
    cout << "���������� ������ Massive";
    if (inf)
        delete[] inf;
}
int Massive::add_elem(Data item)//��
{
    if (Full()) return 0;
    tail = (tail + 1) % queuelength;
    inf[tail] = item;
    current_length++;
    return 1;
}
Data Massive::delete_elem()//��
{
    if (!Empty())
    {
        Data temp = inf[front];
        front = (front + 1) % queuelength;
        current_length--;
        return temp;
    }
    throw invalid_argument("������� �������� ������� �� ������ �������\n");
}
Data Massive::ndread()//��
{
    if (!Empty())
        return inf[front];
    throw invalid_argument("������� ������ �������� �� ������ �������\n");
}
bool Massive::Full() const//��
{
    return (tail + 2) % queuelength == front;
}
bool Massive::Empty() const//��
{
    return (tail + 1) % queuelength == front;
}
