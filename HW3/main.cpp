/*
* Title: Heaps, Priority Queues
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 3
* Description: main
*/
#include <iostream>
#include "simulator.h"
#include "PriorityQueue.h"
#include "Request.h"
#include <string>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	//argv[0] is program name. simulator.
	string fileName = argv[1];
	string maxTimeString = argv[2];
	PriorityQueue q;
	double maxTime = atof(maxTimeString.c_str());
	int reqAmount;

	ifstream file;

	file.open(fileName, ios::in);
	file >> reqAmount;
	for (int i = 0; i < reqAmount; i++) {
		int id;
		int priority;
		int reqTime;
		int proTime;
		file >> id >> priority >> reqTime >> proTime;
		Request r(id, priority, reqTime, proTime);
		q.pqInsert(r);
	}
	
	simulator s(q, maxTime, reqAmount);
	s.simulate();
	s.printSimulation();
	
	file.close();
	return 0;
}

