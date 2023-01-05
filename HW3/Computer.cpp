/*
* Title: Heaps, Priority Queues
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 3
* Description: computer source
*/
#include <string>
#include <iostream>
#include "simulator.h"
using namespace std;


computer::computer() : available(1), remainingTime(0) {}

bool computer::isAvailable() {
	return available;
}

void computer::takeRequest(int processTime) {
	available = 0;
	remainingTime = processTime;
}

void computer::passTime() {
	remainingTime--;
	if (remainingTime == 0)
		available = 1;
}
 