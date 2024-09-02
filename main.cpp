#include <iostream>
#include <clocale>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <stdexcept>
#include "header.h"
#define WIDTH 21
using namespace std;
int main()
{
    setlocale(0, "rus");
    srand(time(0));
    int type, requeasts;
    char ch;
    double maxtime_idle = 0, maxtime_wait = 0, maxlength_request = 0, time_idle = 0, length_request = 0, requeast_number = 0, k = 0;
    struct_data *interface;
    cout << "����� ��������� ������ ������������? 0 - ���������, 1 - ������� ";
    cin >> type;
    if(type != 0 && type != 1)
    {
        cin.setstate(ios_base::failbit);
    }
    while(cin.fail())
    {
        cin.clear();
        while((ch = getchar()) != '\n');
        cout << "����� ��������� ������ ������������? 0 - ���������, 1 - ������� ";
        cin >> type;
        if(type != 0 && type != 1)
        {
            cin.setstate(ios_base::failbit);
        }
    }
    if (type == 0)
    {
        interface = new Massive(100);
    }
    else
    {
        interface = new List(100);
    }
    Data doc;
    for (int time{1}; time <= 360; time++)// time = 0,5 ���
    {

        if (!interface->Empty())
        {
            k = interface->Getcurrent_length();
            while(k--)//���������� �� ���� ������� � ����������� ����� �������� ��������� ������� ������� �� 1
            {
                try
                {
                    doc = interface->delete_elem();
                }
                catch(invalid_argument & ex)
                {
                    cout << ex.what() << endl;
                }
                doc.time_wait++;
                interface->add_elem(doc);
            }
        }
        if (interface->Full())
        {
            try
            {
                cout << left << setw(WIDTH) << "�������������� ������ " << interface->ndread().id;
            }
            catch(invalid_argument & ex)
            {
                cout << ex.what() << endl;
            }
            cout << "       ������� �����������" << endl;
            continue;
        }
        if (rand() % 3 == 0 && rand() % 5 == 0)//��������� �������� ������ �������
        {
            requeasts = rand() % 10 + 1;
            if (interface->Empty())
            {
                cout << left << setw(WIDTH) << "�������������� ������ " << setw(5) << requeast_number + 1;
            }
            else
            {
                try
                {
                    cout << left << setw(WIDTH) << "�������������� ������ " << setw(5) << interface->ndread().id;
                }
                catch(invalid_argument & ex)
                {
                    cout << ex.what() << endl;
                }
            }
            cout << left << setw(WIDTH - 5) << "        ��������� " << requeasts << ":" << " ";
            if (requeasts) length_request += requeasts;
            for (int i{0}; i < requeasts - 1; i++)
            {
                doc.id = ++requeast_number;
                doc.time_wait = 0;
                interface->add_elem(doc);
                cout << doc.id << ", ";
            }
            if (requeasts)
            {
                doc.id = ++requeast_number;
                doc.time_wait = 0;
                interface->add_elem(doc);
                cout << doc.id;
            }
            cout << endl;
            try
            {
                if (interface->ndread().time_wait > maxtime_wait) maxtime_wait = interface->ndread().time_wait;
            }
            catch(invalid_argument & ex)
            {
                cout << ex.what() << endl;
            }
            try
            {
                interface->delete_elem();
            }
            catch(invalid_argument & ex)
            {
                cout << ex.what() << endl;
            }
        }
        else
        {
            if (maxlength_request < length_request) maxlength_request = length_request;
                length_request = 0;
            if (!interface->Empty())
            {
                try
                {
                    cout << left << setw(WIDTH) << "�������������� ������ " << setw(5) << interface->ndread().id;
                }
                catch(invalid_argument & ex)
                {
                    cout << ex.what() << endl;
                }
                cout << left << setw(WIDTH - 5) << "        ��������� " << 0 << ":" << " ";
            }
            else
            {
                cout << left << setw(WIDTH) << "c����� �����������";
                cout << left << setw(WIDTH - 5) << "              ��������� 0" << endl;
                time_idle++;
                continue;
            }
            cout << endl;
            try
            {
                if (interface->ndread().time_wait > maxtime_wait) maxtime_wait = interface->ndread().time_wait;
            }
            catch(invalid_argument & ex)
            {
                cout << ex.what() << endl;
            }
            try
            {
                interface->delete_elem();
            }
            catch(invalid_argument & ex)
            {
                cout << ex.what() << endl;
            }
        }
        if (time_idle > maxtime_idle) maxtime_idle = time_idle;
        time_idle = 0;
    }
    cout << "������������ ����� ������� " << maxtime_idle/2 << " ��� " << " \n������������ ����� �������� " << maxlength_request
                << endl << "������������ ����� �������� ���������� ������� - " << maxtime_wait/2 << " ���" << endl;
    delete interface;
    return 0;
}
