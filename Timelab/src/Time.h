/*
 * Time.h
 *
 *  Created on: Mar 28, 2017
 *      Author: dreifuerstrm
 *      Header file declaring the functions and constructors for the Time class
 */

#ifndef TIME_H_
#define TIME_H_

#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Time {
public:
	Time(); //default constructor
	virtual ~Time(); //default destructor

	Time(int h, int m, int s); //parameter constructor for initializing times

	int gethour(); //get functions to return each of the variables
	int getminute();
	int getsecond();
	void sethour(int h); //set functions for individually setting variables
	void setsecond(int s);
	void setminute(int m);
	int totalsec() const; //function for determining the total amount of seconds in a time
	Time(int seconds); //constructor for creating a time object with only seconds passed into it
	string print(); //returns a string detailing the time of the object

	//operator overloads to enable arithmetic operations with time objects and boolean expressions
	Time operator+(const Time& rhs) const;
	Time operator-(const Time& rhs) const;

	bool operator==(const Time& rhs) const;
	bool operator<(const Time& rhs) const; //time is less if the time is older/ a lower total amount of seconds
	bool operator>(const Time& rhs) const;
	void operator=(const Time& rhs); //function for setting one Time to another time object
	bool operator!=(const Time& rhs) const;



private:
	//data members for keeping track of time
	int hour;
	int minute;
	int second;


};

#endif /* TIME_H_ */
