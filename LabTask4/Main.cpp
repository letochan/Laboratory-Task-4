#include <iostream>
#include "Processor.h"

using namespace std;

void main()
{
	unsigned int nTacts;
	unsigned int sQueue;
	double mNewTask;
	double mCompletionTask;
	setlocale(LC_ALL, "Russian");
	cout << "������� ���������� ������: \n\t";
	cin >> nTacts;
	cout << "\n";
	cout << "������� ������ �������: \n\t";
	cin >> sQueue;
	cout << "\n";
	cout << "������� ����� ��� ��������� ����� ������: \n\t";
	cin >> mNewTask;
	cout << "\n";
	cout << "������� ����� ��� ���������� ����� ������: \n\t";
	cin >> mCompletionTask;
	cout << "\n\n";

	Processor Realize(nTacts, sQueue, mNewTask, mCompletionTask);
	setlocale(LC_ALL, "Russian");
	Realize.Process();
	Realize.Statistics();
}