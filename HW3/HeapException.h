/*
* Title: Heaps, Priority Queues
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 3
* Description: HeapException
*/

#pragma once
# include <string>
using namespace std;
class HeapException : public exception {

private:
	string msg;

public:
	virtual const char* what() const throw()
	{
		return msg.c_str();
	}
	HeapException(const string& message = "") :
		exception(), msg(message) {};
	~HeapException() throw() {};

};