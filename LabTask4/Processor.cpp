#include "Processor.h"
#include <ctime>
#include <iostream>

using namespace std;

Processor::Processor() : tact(0), count_completed(0), count_queue(0), count_ignored(0), count_downtime(0), work(false)
{
	count_tacts = t;
	size_queue = MaxQ;
	markNewTask = 0.5;
	markCompletionTask = 0.5;
}

Processor::Processor(unsigned int nTacts, unsigned int sQueue, double mNewTask, double mCompletionTask) : tact(0), count_completed(0), count_queue(0), count_ignored(0), count_downtime(0), work(false)
{
	if (nTacts > t || sQueue > MaxQ || mCompletionTask >= 1 || mNewTask >= 1 || nTacts < 0 || sQueue < 0 || mCompletionTask < 0 || mNewTask < 0)
		throw "Incorrect values";
	count_tacts = nTacts;
	size_queue = sQueue;
	markNewTask = mNewTask;
	markCompletionTask = mCompletionTask;
}

void Processor::Process()
{
	CQueue<unsigned int> queueTasks(size_queue);
	srand(time(0));
	for (tact; tact < count_tacts; tact++)
	{
		if (work == true)
			if ((1.0*(rand() % 10)) / 10 > markCompletionTask)
			{
				work = false;
				count_completed++;
			}
		if ((1.0*(rand() % 10)) / 10 > markNewTask)
			if (queueTasks.IsEmpty())
				if (work == false)
				{
					work = true;
					continue;
				}
				else
				{
					queueTasks.Put(tact);
					continue;
				}
			else
				if (queueTasks.IsFull())
				{
					count_ignored++;
					continue;
				}

				else
				{
					queueTasks.Put(tact);
					continue;
				}
		else
			if (work == false)
				if (queueTasks.IsEmpty())
				{
					count_downtime++;
					continue;
				}
				else
				{
					queueTasks.Get();
					work = true;
					continue;
				}
	}
	if (work == true)
		count_completed++;
	while (!queueTasks.IsEmpty())
	{
		queueTasks.Get();
		count_queue++;
	}
}

void Processor::Statistics()
{
	setlocale(LC_ALL, "Russian");
	cout << "Число выполненных задач: " << count_completed << "\n";
	cout << "Число задач в очереди:  " << count_queue << "\n";
	cout << "Число отброшенных задач:  " << count_ignored << "\n";
	cout << "Число тактов простоя:  " << count_downtime << "\n";
}