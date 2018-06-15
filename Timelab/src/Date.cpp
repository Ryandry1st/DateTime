/*
 * Date.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: dreifuerstrm
 *      File defining the Date class and its methods and operations
 */

#include "Date.h"
#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Date::Date() {
	// default constructor with basic values
	setyear(0);
	setmonth(0);
	setday(0);
}

Date::Date(int y, int m, int d){
	//constructor which initializes variables to defined values
	setyear(y);
	setmonth(m);
	setday(d);
}

Date::~Date() {
	// default destructor, not special
}

//get functions for the data members of the Date class
int Date::getyear(){
	return year;
}
int Date::getmonth(){
	return month;
}
int Date::getday(){
	return day;
}

//set functions for the data members of the Date class to prevent illegal data entries
void Date::setyear(int y){
	//does not allow negative years to be input
	if(y < 0) {
		cout<< "We don't believe in time before Christ" << endl;
		year = 0;
	}
	else{
		year = y;
	}
}
void Date::setmonth(int m){
	//does not allow negative months to be input
	if(m < 0){
		cout<< "You cannot have negative months" << endl;
		month = 0;
	}
	else{
		month = m;
	}
}
void Date::setday(int d){
	//does not allow negative days to be input
	if(d < 0){
		cout<<"Time does not go in reverse in our 3D view" << endl;
		day = 0;
	}
	else{
		day = d;
	}
}

string Date::print(){
	//function which converts the data results into a string and returns the string for easy printing
	ostringstream convd;
	convd << day;
	ostringstream convm;
	convm << month;
	ostringstream convy;
	convy << year;
	string out = "The date is " + convy.str() + "/" + convm.str() + "/" + convd.str();
	return out;
}

int Date::totaldate() const{
	//function which converts a date into the total number of days since 0/0/0
	int total = 0;
	total = year*365.25 + monthconv() + day;
	if(year % 4){ //handles leap years except for the year it is on so it is corrected to add a day
		total++;
	}
	return total;
}

int Date::monthconv() const{
	//used to convert from a number of months into the number of days since the new year
	int days = 0;
	int monthtest = month - 1; //how many months have been completed is stored here
	for(;monthtest > 0; monthtest--){ //iterates through the number of completed months
		if(monthtest == 0){
			days = 0;
		}
		else if(monthtest == 1){ //certain months have more days, so these are checked individually
			days += 31;
		}
		else if(monthtest == 2){
			if(!(year % 4)){ //if it is a leap year, add a day to february
				days += 29;
			}
			else{
				days += 28;
			}
		}
		else if(monthtest == 3 || monthtest == 5|| monthtest ==7 || monthtest == 8 || monthtest == 10 || monthtest == 12){
			days += 31;
		}
		else{ //any of the months not specifically named have 30 days in them and are added here
			days += 30;
		}
	}
	return days;
}

void Date::daytodate(int days){
	//function to convert a number of days into a date
	int months = 1; //initialize the variables
	int years = 0;
	int pass = 1; //pass keeps track if the last month was completely filled or not
	int montharr[] = {31,28, 31, 30, 31, 30, 31, 31,30,31, 30, 31}; //array of the months normal number of days
	while(days> 31 && pass==1){
		if(!(years % 4)){ //leap years add a day to February
			montharr[1]= 29;
		}
		else{
			montharr[1] = 28;
		}
		for(int i=0; i<12; i++){ //iterates through the months
			if(pass == 1){
				if(days > montharr[i]){
					pass = 1;
					months++; //adds a month if it is filled
					days-=montharr[i];
				}
				else{
					pass = 0;
				}
				if(i == 11 && months == 13 && days > 0){ //if a year has gone through, add one to the year and start over
					years++;
					months = 1;
				}
			}
		}
	}
	setmonth(months); //sets the data values for the results
	setday(days);
	setyear(years);
}

Date Date::operator+(const Date& rhs) const{
	//operator definition for adding two dates by adding the total number of days between them
	int days = this->totaldate() + rhs.totaldate();
	Date sum;
	sum.daytodate(days); //returns the date object from that sum
	return sum;
}

Date Date::operator-(const Date& rhs) const{
	//operator for subtracting two dates by subtracting the total number of days
	int days = this->totaldate() - rhs.totaldate();
	Date oppositeofasum;
	oppositeofasum.daytodate(days); //returns a date object of the difference in total days
	return oppositeofasum;
}

bool Date::operator==(const Date& rhs) const{
	//checks if two date objects have the same number of total days
	return (this->totaldate() == rhs.totaldate());
}
bool Date::operator<(const Date& rhs) const{
	//checks if the left date object has less total days, or is less recent, than another date
	return (this->totaldate() < rhs.totaldate());
}
bool Date::operator>(const Date& rhs) const{
	//checks if the left object has more total days or is more recent than another date
	return (this->totaldate() > rhs.totaldate());
}
void Date::operator=(const Date& rhs){
	//sets one date equal to another so long as they are not the exact same date object
	if(this != &rhs){
		this->setday(rhs.day);
		this->setmonth(rhs.month);
		this->setyear(rhs.year);
	}
	else;
}
bool Date::operator!=(const Date& rhs) const{
	//checks if the total days between two objects is not the same
	return (this-> totaldate() != rhs.totaldate());
}
