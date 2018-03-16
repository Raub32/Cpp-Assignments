// Final Project Milestone 1
//
// Version 1.0
// Date: 2018/03/2018
// Author: Robert Aubow
// Description
//
//
//
//  
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"
using namespace std;
namespace AMA {

	// number of days in month mon_ and year year_
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errorCode(int error) {
	//sets error state to one of the error variables
		errorState = error;
	};

	Date::Date() {
	//set object to safe empty state
		year = 0000;
		month = 0;
		day_of_month = 0;

	//set ERROR STATE to 0
		errorCode(0);

	//set comparison variable to 0
		dateIsRecent = 0;
	};

	Date::Date(int year, int month, int day) {
	//check if numbers are in range in order or year, month, day
		int leapYear = year % 4 ? 1 : 0;

		if (year < 2030 && year > 2012 && month > 0 && month < 12 && day > 0 && day < day + leapYear) {
			//set values and compare
			cout << "comparison" << endl;
		}
		else {
			//else set error state if error
			cout << "error" << endl;
		}
	};

	bool Date::operator==(const Date& rhs) const {
		//compare this object with received onject property members
		return this->year == rhs.year && this->month == rhs.month && this->day_of_month  == rhs.day_of_month ? true : false;
	};

	bool Date::operator!=(const Date& rhs) const {
		//compare this object with received onject property members
		//return true if is not equal
		return *this == rhs == false? true : false;
	};

	bool Date::operator<(const Date& rhs) const {
		//check if this object's members is less than received object's propery members
		return *this != rhs && this->year < rhs.year && this->month < rhs.month && this->day_of_month < rhs.day_of_month ? true : false;
	};

	bool Date::operator>(const Date& rhs) const {
		//check if this object's members is greater than received object's property members
		return *this < rhs ? false : true;
	};

	bool Date::operator<=(const Date& rhs) const {
		//check if this object's property members is less or equal to received object's property members
		return *this == rhs || *this < rhs ? true : false;
	};

	bool Date::operator>=(const Date& rhs) const {
		//check if this object's property members is greater than or equal to received object's property members
		return *this == rhs || *this > rhs ? true : false;
	};

	int Date::errCode() const {
	//return error state
		cout << errorState << endl;
		return 2;

	};

	bool Date::bad() const {
	//return true if state is not NO_ERROR
		return errorState != 0 ? true : false;
	};

	istream& Date::read(istream& istr) {
	//read date from console in formate YYYY/MM/DD
		
		//if fail to read set error staet to CIN_FAILED
		if (istr.fail()) {
			cout << "failed";
			return istr;
		}
		else {
			return istr;
		}
			//call istr.fail() should return true
		
		//return reference to istream object
	};

	ostream& Date::write(ostream& ostr) const {
	//output date to ostream object in format YYYY/MM/DD
		ostr << year << "/" << month << "/" << day_of_month;
		return ostr;
 	};

	ostream& operator<<(ostream& ostr, const Date & c){
	//output date from object
		return c.write(ostr);
	};

	istream& operator>>(istream& istr, Date &c){
	//read date and store in object
		return c.read(istr);
	};

}
