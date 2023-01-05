/*
* Title: Graphs
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 4
* Description: FlightMap
*/
#pragma once
#include "Airport.h"
using namespace std;

const int MAX_SIZE = 100;

class FlightMap {
public:
	FlightMap(int sizeMap);
	void InsertFlight(int u, int v, int w); 
	void ListFlights(int u);
	void shortest(int s, int t);
private:
	Airport* airports;
	int size;
	int edge;
};
