/*
* Title: Graphs
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 4
* Description: Flight
*/
#pragma once

class Flight {

private:
	int destination;
	int duration;
	Flight* next;

	friend class Airport;
};