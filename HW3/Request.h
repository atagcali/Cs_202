#pragma once
/*
* Title: Heaps, Priority Queues
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 3
* Description: request header
*/


class Request {
public:
	Request();
	Request(int ID, int Prio, int requestTime, int processTime);
	int getID();
	int getPriority();
	int getReqTime();
	int getProTime();

private:
	int id;
	int priority;
	int reqTime;
	int proTime;
};
