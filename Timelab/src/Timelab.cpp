//============================================================================
// Name        : Timelab.cpp
// Author      : Ryan Dreifuerst
// Version     :
// Copyright   : 
// Description : Date, Time, and DateTime classes for object oriented understanding
//============================================================================

#include <iostream>
#include "Time.h"
#include "Date.h"
#include "DateTime.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//main code defined by Dr. Carl

int main() {
	// Test Date class.
	cout << "***Test Date Class***" << endl;
	Date d1(2016,1,31);
	Date d2(0,0,31);
	Date d3(2017,9,1);
	Date d4(0,5,12);
	Date d5(0,5,11);
	Date d6(2000,3,1);
	Date d7(0,0,1);
	Date d8(1000,1,30);
	cout << "d1: " << d1.print() << endl;
	cout << "d2: " << d2.print() << endl;
	cout << "d3: " << d3.print() << endl;
	cout << "d4: " << d4.print() << endl;
	cout << "d5: " << d5.print() << endl;
	cout << "d6: " << d6.print() << endl;
	cout << "d7: " << d7.print() << endl;
	cout << "d8: " << d8.print() << endl;

	Date dTest = d1 + d2;
	cout << "d1 + d2: " << dTest.print() << endl;
	dTest = d3 - d1;
	cout << "d3 - d1: " << dTest.print() << endl;
	dTest = d3 + d4;
	cout << "d3 + d4: " << dTest.print() << endl;
	dTest = d6 - d7;
	cout << "d6 - d7: " << dTest.print() << endl;
	dTest = d8 + d8;
	cout << "d8 + d8: " << dTest.print() << endl;
	cout << "d1 > d2: ";
	if(d1 > d2){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "d1 < d2: ";
	if(d1 < d2){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "d4 == d5: ";
	if(d4 == d5){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "d4 != d5: ";
	if(d4 != d5){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}

	// Test Time class.
	cout << "\n***Test Time Class***" << endl;
	Time t1(10,15,30);
	Time t2(0,0,45);
	Time t3(14,45,8);
	Time t4(0,46,9);
	Time t5(0,46,8);
	cout << "t1: " << t1.print() << endl;
	cout << "t2: " << t2.print() << endl;
	cout << "t3: " << t3.print() << endl;
	cout << "t4: " << t4.print() << endl;
	cout << "t5: " << t5.print() << endl;

	Time t6 = t1 + t2;
	cout << "t1 + t2: " << t6.print() << endl;
	t6 = t3 - t1;
	cout << "t3 - t1: " << t6.print() << endl;
	t6 = t3 + t1;
	cout << "t3 + t1: " << t6.print() << endl;
	t6 = t3 + t4;
	cout << "t3 + t4: " << t6.print() << endl;
	cout << "t1 > t2: ";
	if(t1 > t2){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "t1 < t2: ";
	if(t1 < t2){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "t4 == t5: ";
	if(t4 == t5){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "t4 != t5: ";
	if(t4 != t5){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}

	// Test DateTime Class
	cout << "\n***Test DateTime Class***" << endl;
	DateTime dt1(d1,t1);
	DateTime dt2(d2,t2);
	DateTime dt3(d3,t3);
	DateTime dt4(d4,t4);
	DateTime dt5(d5,t4);
	DateTime dt6(d4,t5);
	DateTime dt7(d8,t3);
	cout << "dt1: " << dt1.print() << endl;
	cout << "dt2: " << dt2.print() << endl;
	cout << "dt3: " << dt3.print() << endl;
	cout << "dt4: " << dt4.print() << endl;
	cout << "dt5: " << dt5.print() << endl;
	cout << "dt6: " << dt6.print() << endl;
	cout << "dt7: " << dt7.print() << endl;

	DateTime dtTest = dt1 + dt2;
	cout << "dt1 + dt2: " << dtTest.print() << endl;
	dtTest = dt3 - dt1;
	cout << "dt3 - dt1: " << dtTest.print() << endl;
	dtTest = dt3 + dt4;
	cout << "dt3 + dt4: " << dtTest.print() << endl;
	dtTest = dt3 + d4;
	cout << "dt3 + d4: " << dtTest.print() << endl;
	dtTest = dt3 + t1;
	cout << "dt3 + t1: " << dtTest.print() << endl;
	dtTest = dt3 + t4;
	cout << "dt3 + t4: " << dtTest.print() << endl;
	dtTest = dt7 + dt7;
	cout << "dt7 + dt7: " << dtTest.print() << endl;
	cout << "dt1 > dt2: ";
	if(dt1 > dt2){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "dt1 < dt2: ";
	if(dt1 < dt2){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "dt4 > dt5: ";
	if(dt4 > dt5){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "dt4 < dt5: ";
	if(dt1 < dt2){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "dt4 > dt6: ";
	if(dt4 > dt6){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "dt4 < dt6: ";
	if(dt1 < dt2){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "dt5 > dt6: ";
	if(dt5 > dt6){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "dt5 < dt6: ";
	if(dt5 < dt6){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "dt4 == dt5: ";
	if(dt4 == dt5){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}
	cout << "dt4 != dt5: ";
	if(dt4 != dt5){
		cout << "True" << endl;
	}
	else{
		cout << "False" << endl;
	}

	return 0;
}
