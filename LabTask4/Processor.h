#pragma once

#include "CQueue.h"

#define t 100

class Processor
{
	unsigned int count_tacts;
	unsigned int size_queue;
	unsigned int tact;
	bool work;
	double markNewTask;
	double markCompletionTask;
	unsigned int count_completed;
	unsigned int count_ignored;
	unsigned int count_queue;	
	unsigned int count_downtime;
public:
	Processor(unsigned int nTacts, unsigned int sQueue, double mNewTask, double mCompletionTask);
	Processor();
	void Process();
	void Statistics();
};
