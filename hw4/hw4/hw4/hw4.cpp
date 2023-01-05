/*
* Title: Graphs
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 4
* Description: hw4
*/

using namespace std;
#include <iostream>
#include "FlightMap.h"
#include <string>
#include <fstream>


int main(int argc, char* argv[]) {

	//argv[0] is program name. hw4.
	string fileName = argv[1];

	ifstream file;

	file.open(fileName, ios::in);

	int airportAmount;
	int inputAmount;
	file >> airportAmount;
	file >> inputAmount;
	
	
	FlightMap f(airportAmount);
	
	
	for (int i = 0; i < inputAmount; i++) {
		char opcode;
		file >> opcode;
		if (opcode == 'I') {
			int u ,v, w;

			file >> u >> v >> w;
			f.InsertFlight(u, v, w);
		}
		else if (opcode == 'L') {
			int u;
			file >> u;
			f.ListFlights(u);
		}
		else if (opcode == 'S') {
			int s, t;
			file >> s >> t;
		}
		else if (opcode == 'M') {

		}
	}

	file.close();
	/*FlightMap f(5);
	f.InsertFlight(1, 2, 5);
	f.InsertFlight(2, 4, 3);
	f.ListFlights(2);*/
	
	return 0;
};