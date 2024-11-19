#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;

enum Spec { CS, IT, ME, PhIT, TR };

string strSpec[] = { "����'�����i �����", "I����������", "���������� �� ������i��", "�i���� �� i����������", "������� ��������" };

struct Student
{
    string lname;
    int kurs;
    Spec spec;
    int physics;
    int math;
    int informatik;
};

void Create(Student* s, int amSt) {
    int sp;
    for (int i = 0; i < amSt; i++) {
        cout << "��i�����: ";
        cin >> s[i].lname;
        cout << "����: ";
        cin >> s[i].kurs;
        cout << "����i����i��� (0 - ����'�����i �����, 1 - I����������, 2 - ���������� �� ������i��, 3 - �i���� �� i����������, 4 - ������� ��������) ";
        cin >> sp;
        s[i].spec = (Spec)sp;
        cout << "��i��� � �i����: ";
        cin >> s[i].physics;
        cout << "��i��� � ����������: ";
        cin >> s[i].math;
        cout << "��i��� � �����������: ";
        cin >> s[i].informatik;
        cout << endl;
    }
}

void Print(Student* s, int amSt)
{
    cout << "-----------------------------------------------------------------------------------------"
        << endl;
    cout << "| � |    ��i�����   | ���� |      ����i����i���     | �i���� | ���������� | ����������� |"
        << endl;
    cout << "-----------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < amSt; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << "";
        cout << "| " << setw(14) << left << s[i].lname
            << "| " << setw(5) << right << s[i].kurs
            << "| " << setw(23) << left << strSpec[s[i].spec]
            << "| " << setw(7) << s[i].physics
            << "| " << setw(11) << right << s[i].math
            << "| " << setw(7) << right << s[i].informatik;
        cout << endl;
    }
    cout << "-----------------------------------------------------------------------------------------"
        << endl;
}

double findMark(Student* p, const int N) {
    return ((p[N].math + p[N].physics + p[N].informatik) / 3.0);
}

// Գ����� �������������
void Sort(Student* p, const int N)
{
    Student tmp;
    for (int i0 = 0; i0 < N - 1; i0++)
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if ((p[i1].kurs > p[i1 + 1].kurs) ||
                (p[i1].kurs == p[i1 + 1].kurs && findMark(p, i1) < findMark(p, i1 + 1)) ||
                (p[i1].kurs == p[i1 + 1].kurs && findMark(p, i1) == findMark(p, i1 + 1) &&
                    p[i1].lname < p[i1 + 1].lname))
            {
                tmp = p[i1];
                p[i1] = p[i1 + 1];
                p[i1 + 1] = tmp;
            }
}

// �������� �������������
int* indexSort(Student* s, const int N)
{
    int* P = new int[N];
    for (int i = 0; i < N; i++)
        P[i] = i;

    for (int i0 = 0; i0 < N - 1; i0++)
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if ((s[P[i1]].kurs > s[P[i1 + 1]].kurs) ||
                (s[P[i1]].kurs == s[P[i1 + 1]].kurs && findMark(s, P[i1]) < findMark(s, P[i1 + 1])) ||
                (s[P[i1]].kurs == s[P[i1 + 1]].kurs && findMark(s, P[i1]) == findMark(s, P[i1 + 1]) &&
                    s[P[i1]].lname < s[P[i1 + 1]].lname))
            {
                int tmp = P[i1];
                P[i1] = P[i1 + 1];
                P[i1 + 1] = tmp;
            }
    return P;
}

// ��������� ��������-�������������� ������
void PrintIndexSorted(Student* s, int* P, const int N)
{
    cout << "-----------------------------------------------------------------------------------------"
        << endl;
    cout << "| � |    ��i�����   | ���� |      ����i����i���     | �i���� | ���������� | ����������� |"
        << endl;
    cout << "-----------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << "";
        cout << "| " << setw(14) << left << s[P[i]].lname
            << "| " << setw(5) << right << s[P[i]].kurs
            << "| " << setw(23) << left << strSpec[s[P[i]].spec]
            << "| " << setw(7) << s[P[i]].physics
            << "| " << setw(11) << right << s[P[i]].math
            << "| " << setw(7) << right << s[P[i]].informatik;
        cout << endl;
    }
    cout << "-----------------------------------------------------------------------------------------"
        << endl;
}

// �������� �����
int binSearch(Student* p, const int N, const string prizv, int const kurs, const double avr)
{
    for (int i = 0; i < N; i++)
    {
        if (p[i].lname == prizv && p[i].kurs == kurs && findMark(p, i) == avr) {
            return i;
        }
    }
    return -1;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int amSt;
    cout << "ʳ������ ��������: ";
    cin >> amSt;

    Student* s = new Student[amSt];
    int menuItem;
    do {
        cout << endl << endl;
        cout << "������� ��:" << endl << endl;
        cout << " [1] - �������� ����� � ���������" << endl;
        cout << " [2] - ���� ����� �� �����" << endl;
        cout << " [3] - ������� ������������� �����" << endl;
        cout << " [4] - �������� ������������� �� ���� �����" << endl;
        cout << " [5] - ������� ����� ��������" << endl;
        cout << " [0] - ����� �� ���������� ��������" << endl << endl;
        cout << "������ ��������: "; cin >> menuItem;
        cout << endl;

        switch (menuItem)
        {
        case 1:
            Create(s, amSt);
            break;
        case 2:
            Print(s, amSt);
            break;
        case 3:
            Sort(s, amSt);
            cout << "��� ������������!" << endl;
            break;
        case 4:
        {
            int* P = indexSort(s, amSt);
            PrintIndexSorted(s, P, amSt);
            delete[] P;
            break;
        }
        case 5:
        {
            string prizv;
            int kurs, avrGrade;
            cout << "������ �������: "; cin >> prizv;
            cout << "������ ����: "; cin >> kurs;
            cout << "������ ������� ������: "; cin >> avrGrade;

            int found = binSearch(s, amSt, prizv, kurs, avrGrade);
            if (found != -1)
                cout << "�������� �������� � ������� " << found + 1 << endl;
            else
                cout << "�������� �������� �� ��������" << endl;
            break;
        }
        case 0:
            break;
        }
    } while (menuItem != 0);

    delete[] s;
    return 0;
}
