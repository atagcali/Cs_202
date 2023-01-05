/*
* Title: Graphs
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 4
* Description: FlightMap
*/

using namespace std;
#include <iostream>
#include "FlightMap.h"
#include "Airport.h"

FlightMap::FlightMap(int sizeMap)  {
	size = sizeMap;
	airports = new Airport[size];

}


void FlightMap::InsertFlight(int u, int v, int w) { 
	
	airports[u].setnextflight(v, w);
	airports[v].setnextflight(u, w);

	airports[u].flightAmount++;
	airports[v].flightAmount++;

	edge++;

	cout << "Inserted a new flight between " << u << " and " << v << "." << endl;
	cout << "   The number of flights from " << u << " is " << airports[u].flightAmount << "." << endl;
}

void FlightMap::ListFlights(int u) {
	cout << "List of flights from " << u << " : " << endl;

	airports[u].printfligths(u);

	cout << "The number of flights is " << airports[u].flightAmount << endl;
}

void FlightMap::shortest(int s, int t) {
	//step1
	int* weights = new int[size];
	int* tempArr = new int[100];
	tempArr = airports[s].getdurations();
	for (int i = 0; i < size; i++) {
		weights[i] = tempArr[i];
	}
	//step2




}
