/*
* Title: Heaps, Priority Queues
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 3
* Description: computer header
*/
#pragma once
class computer {
public:
	computer();
	void takeRequest(int processTime);
	void passTime();
	bool isAvailable();
private:
	bool available;
	int remainingTime;

};