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

namespace AMA {

	// number of days in month mon_ and year year_
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
	void Date::errCode(int errorCode) {
	//sets error state to one of the error variables
		errorState = errorCode;
	};
	Date::Date() {
	//set object to safe empty state
		year = 0000;
		month = 0;
		day_of_month = 0;

	//set NO_ERROR to 0
		errorCode(NO_ERROR);
	//set comparison variable to 0
		dateIsRecent = 0;
	};
	Date::Date(int year, int month, int day) {
	//check if numbers are in range in order or year, month, day
		int leapYear = year % 4 ? 1 : 0;

		if (year < max_year && year > min_year && month > 0 && month < 12 && day > 0 && day < day + leapYear) {
			//set values and compare

		}
		else {
			//else set error state if error

		}
	};
	bool Date::operator==(const Date& rhs) const {
		//compare this object with received onhect property members
		return rhs.year == year && rhs.month == month && rhs.day_of_month == day_of_month ? true : false;
	};
	bool Date::operator!=(const Date& rhs) const {
		//compare this object with received onhect property members
		//return true if is not equal	
		return (this == rhs) = false ? true : false;
	};
	bool Date::operator<(const Date& rhs) const {
		//check if this object's members is less than received object's propery members
		return rhs.year < year && rhs.month < month && rhs.day_of_month < day_of_month ? true : false;
	};
	bool Date::operator>(const Date& rhs) const {
		//check if this object's members is greater than received object's property members
		return (this == rhs) == false && (this < rhs) == false ? true : false;
	};
	bool Date::operator<=(const Date& rhs) const {
		//check if this object's property members is less or equal to received object's property members
		return (this == rhs) == true || (this < rhs) == true ? true : false;
	};
	bool Date::operator>=(const Date& rhs) const {
		//check if this object's property members is greater than or equal to received object's property members
		return (this == rhs) == true || (this > rhs) == true ? true : false;
	};
	int Date::errCode() const {
	//return error state

	};
	bool Date::bad() const {
	//return true if state is not NO_ERROR
		return errorState == NO_ERROR ? true : false;
	};
	Date::std::istream& read(std::istream& istr) {
	//read date from console in formate YYYY/MM/DD

		//if fail to read set error staet to CIN_FAILED
			//call istr.fail() should return true

		//return reference to istream object
	};
	Date::std::ostream& write(std::ostream& ostr) const {
	//output date to ostream object in format YYYY/MM/DD
		cout << ostr.year << "/" << ostr.month << "/" << ostr.day_of_month << endl;
 	};
	operator<<(const std::ostream& ostr) const {
	//output date from object
		write(ostr);
	};
	operator>>(std::istream& istr){
	//read date and store in object
		read(istr);
	};

}