/*
* Title: Heaps, Priority Queues
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 3
* Description: simulator header
*/
#pragma once
#include <string>
#include "Computer.h"
#include "PriorityQueue.h"
using namespace std;
class simulator {
public:
	simulator(PriorityQueue queue, double mT, int numofReq);
	void simulate();
	void printSimulation();
private:
	int minCompAmount;
	int wait;
	int time;
	double avgWait;
	PriorityQueue q;
	double maxTime;
	int numberOfRequests;
};