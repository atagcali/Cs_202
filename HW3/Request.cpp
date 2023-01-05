/*
* Title: Heaps, Priority Queues
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 3
* Description: request source
*/
#include "Request.h"
#include <iostream>
using namespace std;

Request::Request() : id(0), priority(0), reqTime(0), proTime(0) {}

Request::Request(int ID, int Prio, int requestTime, int processTime) {
    id = ID;
    priority = Prio;
    requestTime = requestTime;
    processTime = processTime;
}

int Request::getID() {
    return id;
}

int Request::getPriority() {
    return priority;
}

int Request::getReqTime() {
    return reqTime;
}

int Request::getProTime() {
    return proTime;
}