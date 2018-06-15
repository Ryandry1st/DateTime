/*
 * Time.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: dreifuerstrm
 *      File defining the Time class and its methods and operations
 */

#include "Time.h"
#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Time::Time() {
	// default contructor which begins entirely of zeros
	hour = 0;
	minute = 0;
	second =0;
}

Time::Time(int h, int m, int s){
	//initializes the variables for the parameter constructor
	sethour(h);
	setminute(m);
	setsecond(s);
}

Time::~Time() {
	// default destructor
}

//get and set functions for the data members of a Time object
int Time::gethour(){
	return hour;
}
int Time::getminute(){
	return minute;
}
int Time::getsecond(){
	return second;
}
void Time::sethour(int h){
	if(h >= 0){
		hour = h;
	}
	else{ //does not accept a negative value, resulting in an error message
		cout <<"Illegal negative parameter";
	}
}
void Time::setsecond(int s){
	if(s >= 0){
		second = s;
	}
	else{//does not accept a negative value, resulting in an error message
		cout <<"Illegal negative parameter";
	}
}
void Time::setminute(int m){
	if(m >= 0){
		minute = m;
	}
	else{//does not accept a negative value, resulting in an error message
		cout <<"Illegal negative parameter";
	}
}


string Time::print(){
	//function for returning a string explaining the data members of the time
	ostringstream s; //used to convert the data into a string to be returned and then printed
	ostringstream m;
	ostringstream h;
	s << second;
	m << minute;
	h << hour;
	string report = "The time is " + h.str() + ":" + m.str() + ":" + s.str(); //includes colons for clear time reading
	return report;
}

int Time::totalsec() const{
	//returns the total number of seconds within a single time object
	return hour*3600 + 60*minute + second;
}

Time::Time(int seconds){
	//constructor for creating a time object from a provided number of seconds
	//can be used to create time objects from the total number of seconds in arithmetic operations
	int hours = 0;
	int minutes = 0;
	while(seconds >= 3600){ //first remove the maximum hours from the total seconds
		hours++;
		seconds -= 3600;
	}
	while(seconds >= 60){ //remove the maximum minutes from the total seconds remaining
		minutes++;
		seconds -= 60;
	}
	while(hours >= 24){ //if the hours are greater than 24, reset back down to 0 hours
		hours -= 24;
	}
	sethour(hours); //fill the data members for the object with the corresponding variables
	setminute(minutes);
	setsecond(seconds);
}

Time Time::operator+(const Time& rhs) const{
	//allows for adding two time objects together by adding the total number of seconds of each time together
	int res = this->totalsec() + rhs.totalsec();
	Time sum(res);
	return sum; //returns a new time object that is the sum of the two objects added
}

Time Time::operator-(const Time& rhs) const{
	//allows the program to subtract two time objects by subtracting the rhs total seconds from the first's total seconds
	int res = this->totalsec() - rhs.totalsec();
	Time difference(res);
	return difference; //returns a new time object that is the difference of the two objects added
}

bool Time::operator==(const Time& rhs) const{
	//operator for checking if two time objects are the same, checks by comparing the total seconds of each
	return (this->totalsec() == rhs.totalsec());
}

bool Time::operator<(const Time& rhs) const{
	//operator which is true if the left time has less total seconds, or is closer to the start of the day,
	//than the right time object
	return (this->totalsec() < rhs.totalsec());
}

bool Time::operator>(const Time& rhs) const{
	//the opposite of the less than operator, this checks if the left time has more total seconds than the right time
	return (this->totalsec() > rhs.totalsec());
}

void Time::operator=(const Time& rhs){
	//operator which sets one time object to have the same data member values as another time object
	if(this != &rhs){ //cannot be called on itself
		this->sethour(rhs.hour);
		this->setminute(rhs.minute);
		this->setsecond(rhs.second);
	}
	else;
}

bool Time::operator!=(const Time& rhs) const{
	//checks for the opposite of if two times have the same total number of seconds
	return (!(*this == rhs));
}

