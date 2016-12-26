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
	cout << "¬ведите количество тактов: \n\t";
	cin >> nTacts;
	cout << "\n";
	cout << "¬ведите размер очереди: \n\t";
	cin >> sQueue;
	cout << "\n";
	cout << "¬ведите порог дл€ по€влени€ новой задачи: \n\t";
	cin >> mNewTask;
	cout << "\n";
	cout << "¬ведите порог дл€ выполнени€ новой задачи: \n\t";
	cin >> mCompletionTask;
	cout << "\n\n";

	Processor Realize(nTacts, sQueue, mNewTask, mCompletionTask);
	setlocale(LC_ALL, "Russian");
	Realize.Process();
	Realize.Statistics();
}