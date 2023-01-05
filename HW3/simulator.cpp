/*
* Title: Heaps, Priority Queues
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 3
* Description: simulator source
*/
#include <string>
#include <iostream>
#include "simulator.h"
#include "Request.h"
using namespace std;

simulator::simulator(PriorityQueue queue, double mT, int numofReq) : minCompAmount(0), wait(0), time(0), avgWait(0) {
	maxTime = mT;
	q = queue;
	numberOfRequests = numofReq;
}

void simulator::simulate() {
	PriorityQueue temp(q);
	do {
		computer* comps = new computer[minCompAmount++];
		while (!temp.pqIsEmpty()) {
			for (int i = 0; i < minCompAmount; i++) {
				if (comps[i].isAvailable()) {
					Request req;
					temp.pqDelete(req);
					comps[i].takeRequest(req.getProTime());
					wait = wait + (time - req.getReqTime());
				}
				else {
					comps[i].passTime();
				}
			}
			time++;
		}
		avgWait = time / numberOfRequests;
		comps = NULL;
		delete comps;
	} while (maxTime < avgWait);
}

void simulator::printSimulation() {
	cout << "Minimum number of computer required is: " << minCompAmount << endl << endl;
	cout << "Simulation with 3 computers: " << endl << endl;
	computer* comps = new computer[minCompAmount];
	PriorityQueue temp(q);
	while (!temp.pqIsEmpty()) {
		for (int i = 0; i < minCompAmount; i++) {
			if (comps[i].isAvailable()) {
				Request req;
				temp.pqDelete(req);
				comps[i].takeRequest(req.getProTime());
				wait = wait + (time - req.getReqTime());
				cout << "computer " << i << "takes request " << req.getID() << "at ms " << time << "(wait : " << wait << " ms)" << endl;
			}
			else {
				comps[i].passTime();
			}
		}
		time++;
	}
	comps = NULL;
	delete comps;
	cout << endl << "Average waiting time: " << avgWait << " minutes" << endl;
}