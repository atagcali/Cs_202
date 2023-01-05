/*
* Title: Heaps, Priority Queues
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 3
* Description: PQException
*/
#pragma once
# include <string>
using namespace std;
class PQException : public exception {

private:
	string msg;

public:
	virtual const char* what() const throw()
	{
		return msg.c_str();
	}
	PQException(const string& message = "") :
		exception(), msg(message) {};
	~PQException() throw() {};

}; 
