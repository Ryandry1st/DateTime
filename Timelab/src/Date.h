/*
 * Date.h
 *
 *  Created on: Mar 28, 2017
 *      Author: dreifuerstrm
 *      Header file for the Date Class
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Date {
public:
	Date(); //basic default constructor
	virtual ~Date(); //default destructor

	Date(int y, int m, int d);
	//constructor for initializing data

	int getyear(); //get functions for the data members
	int getmonth();
	int getday();
	void setyear(int y); //set functions for individual data members
	void setmonth(int m);
	void setday(int d);
	string print(); //returns a string detailing the data members

	int totaldate() const; //converts a date into the total number of days
	int monthconv() const; //used to convert the number of months into days
	void daytodate(int days); //converts the number of days into a date

	//operator overloads to enable arithmetic operation on Date objects
	Date operator+(const Date& rhs) const;
	Date operator-(const Date& rhs) const;

	// boolean operators which check if the total number of days is the same or not
	bool operator==(const Date& rhs) const;
	bool operator<(const Date& rhs) const;
	bool operator>(const Date& rhs) const;
	void operator=(const Date& rhs); //operator which sets one date to be equal to another date
	bool operator!=(const Date& rhs) const;


private:
	//data members for a classically defined date
	int year;
	int month;
	int day;



};

#endif /* DATE_H_ */
