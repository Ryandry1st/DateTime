/*
 * DateTime.h
 *
 *  Created on: Apr 10, 2017
 *      Author: dreifuerstrm
 */

#ifndef DATETIME_H_
#define DATETIME_H_

#include "Time.h"
#include "Date.h"

class DateTime {
public:

	DateTime();//default constructor
	virtual ~DateTime(); //default destructor

	DateTime(Date d, Time t); //parameter constructor for initializing date and time members
	void setdate(Date d); //get and set functions for date and time manipulation
	void settime(Time t);
	Date getdate();
	Time gettime();
	string print(); //returns a string with the date and time information

	//addition operator overloading to enable adding of a datetime with any date,time, or datetime object
	DateTime operator+(const DateTime& rhs) const;
	DateTime operator+(const Time& rhs) const;
	DateTime operator+(const Date& rhs) const;

	//subtraction operator overloading to enable subtraction of a datetime with any similar data type
	DateTime operator-(const Time& rhs) const;
	DateTime operator-(const Date& rhs) const;
	DateTime operator-(const DateTime& rhs) const;

	//boolean operators for determining which date is more recent or older, down to the second definition
	bool operator==(const DateTime& rhs) const;
	bool operator<(const DateTime& rhs) const;
	bool operator>(const DateTime& rhs) const;
	void operator=(const DateTime& rhs); //sets a datetime object to have the same data entries as another datetime
	bool operator!=(const DateTime& rhs) const;





private:
	//data members for the date and time of a DateTime object
	Date my_date;
	Time my_time;
};

#endif /* DATETIME_H_ */
