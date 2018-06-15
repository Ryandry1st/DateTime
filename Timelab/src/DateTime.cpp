/*
 * DateTime.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: dreifuerstrm
 *      DateTime class definitions which describe the implementation of the combined Date and Time classes
 */

#include "DateTime.h"

DateTime::DateTime() {
	// default constructor, sets all data to 0
	my_date = Date(0,0,0);
	my_time = Time(0);

}

DateTime::~DateTime() {
	//default destructor
}

DateTime::DateTime(Date d, Time t){
	//parameter constructor which initializes the data members
	setdate(d);
	settime(t);
}

//set functions which ensure illegal data is not entered into the data members
void DateTime::setdate(Date d){
	if(d < Date(0,0,0)){
		cout<< "illegal parameter input" << endl;
	}
	else{
		my_date = d;
	}
}

void DateTime::settime(Time t){
	if(t < Time(0)){
		cout << "illegal parameter input" << endl;
	}
	else{
		my_time = t;
	}
}

//get functions which return the desired data value
Date DateTime::getdate(){
	return my_date;
}

Time DateTime::gettime(){
	return my_time;
}

string DateTime::print(){
	//function which returns a string of the date and time of a DateTime object for printing
	string dat = my_date.print();
	string tim = my_time.print();
	return dat+ " " + tim;
}

//three different addition operators for defining the different objects that can be added to a datetime object
DateTime DateTime::operator+(const DateTime& rhs) const{
	//adds two datetimes by adding both the date and the time and rolling over if the times add another day
	DateTime sum;
	sum.setdate(this->my_date + rhs.my_date);
	sum.settime(this->my_time + rhs.my_time);
	if(sum.gettime() < this->my_time){
		sum.setdate(sum.my_date + Date(0,0,1));
	}
	return sum; //returns the datetime object sum of the two datetime objects
}

DateTime DateTime::operator+(const Time& rhs) const{
	//adds a time to a datetime, generally not changing the date, but it can roll over if necesarry
	DateTime sum;
	sum.setdate(this->my_date);
	sum.settime(this->my_time + rhs);
	if(sum.gettime() < this->my_time){
		sum.setdate(sum.my_date + Date(0,0,1));
	}
	return sum; //return the datetime object sum
}

DateTime DateTime::operator+(const Date& rhs) const{
	//last addition option which is adding a date with a datetime, causing the date to change
	DateTime sum;
	sum.settime(this->my_time);
	sum.setdate(this->my_date + rhs);
	//returns the new datetime object with the same time but a new date
	return sum;
}

//subtraction operator for the three different subtraction cases, similar to the addition cases
DateTime DateTime::operator-(const Time& rhs) const{
	//subtracts the time from a datetime, however does not permit negative time, or reverse rolling days
	DateTime difference;
	difference.setdate(this->my_date);
	difference.settime(this->my_time - rhs);
	return difference; //returns the new datetime object
}

DateTime DateTime::operator-(const Date& rhs) const{
	//subtracts the date from a datetime, and keeps the time the same
	DateTime difference;
	difference.my_time = this->my_time;
	difference.setdate(this->my_date - rhs); //does not permit negative dates
	return difference; //returns the new datetime object
}

DateTime DateTime::operator-(const DateTime& rhs) const{
	//subtracts two datetime objects, but does not allow for negative times or dates to occur
	DateTime difference;
	difference.setdate(this->my_date - rhs.my_date);
	difference.settime(this->my_time - rhs.my_time);
	return difference; //returns the difference of the two datetimes
}

bool DateTime::operator==(const DateTime& rhs) const{
	//checks if both the time and date of two datetimes are the same
	bool dat;
	bool tim;
	dat = (this->my_date == rhs.my_date);
	tim = (this->my_time == rhs.my_time);
	return dat&tim;
}

bool DateTime::operator<(const DateTime& rhs) const{
	//checks if a datetime is less recent than another datetime
	bool dat;
	bool tim;
	if(this->my_date < rhs.my_date){ //if the date is less, it is automatically less
		dat = true;
	}
	else if(this->my_date == rhs.my_date){ //if the dates are equal, the time must be compared
		tim = (this->my_time < rhs.my_time);
		if(tim)
			dat = true;
	}
	else
		dat = false;
	return dat; //returns the boolean result
}

bool DateTime::operator>(const DateTime& rhs) const{
	//checks if the datetime is more recent than another
	bool lt = (*this < rhs);
	bool rt = (*this == rhs); //checks if it is not equal to or less than the other datetime
	return(!(lt|rt));
}

void DateTime::operator=(const DateTime& rhs){
	//sets one datetime equal to another so long as it is not the same object
	if(this != &rhs){
		my_date = rhs.my_date;
		my_time = rhs.my_time;
	}
}
bool DateTime::operator!=(const DateTime& rhs) const{
	//checks for the opposite of the two Datetimes being equal
	return(!(*this == rhs));
}
