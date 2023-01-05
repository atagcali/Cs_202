/*
* Title: Graphs
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 4
* Description: Airport
*/

using namespace std;
#include <iostream>
#include "Airport.h"


Airport::Airport() : flight(NULL), flightAmount(0) {

}


void Airport::setnextflight(int v, int w) {
	if (flight == NULL) {
		flight = new Flight;
		flight->destination = v;
		flight->duration = w;
		flight->next = NULL;
	}
	else {
		Flight *temp = flight;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new Flight;
		temp = temp->next;
		temp->destination = v;
		temp->duration = w;
		temp->next = NULL;
	}
}

void Airport::printfligths(int u) {
	if (flight == NULL) {
		cout << "there is no flight" << endl;
	}
	else {
		Flight* temp = flight;
		while (temp != NULL) {
			cout << u << " to " << temp->destination << " with a duration of " << temp->duration << "." << endl;
			temp = temp->next;
		
		}
	}

}

int* Airport::getdurations() {
	int max = 100;
	int* durations = new int[max];
	Flight* temp = flight;
	for (int i = 0; i < flightAmount; i++) {
		int a = temp->destination;
		durations[a] = temp->duration;
	}
	delete temp;
	temp = NULL;

	return durations;
}