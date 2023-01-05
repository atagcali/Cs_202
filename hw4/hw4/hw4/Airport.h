/*
* Title: Graphs
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 4
* Description: Airport
*/

#pragma once
#include "Flight.h"
using namespace std;

class Airport {
public: 
	Airport();
	void setnextflight(int v, int w);
	void printfligths(int u);
	int* getdurations();
private:
	Flight* flight;
	int flightAmount;
	friend class FlightMap;
};