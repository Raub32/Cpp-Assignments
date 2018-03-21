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
#include <iostream>
#include <iomanip>
#include <cstring>
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
       this->year = 0;
       this->month = 0;
       this->day_of_month = 0;

	//set ERROR STATE to 0
		errorCode(NO_ERROR);

	//set comparison variable to 0
        comparator = 0;
	};
    
    bool Date:: isValid(int arg1, int arg2, int arg3 ){
        
        if( arg1 < min_year || year > max_year){
            errorCode(YEAR_ERROR);
            return false;
            
        }else if ( arg2 > 12 || arg2 < 1 ){
            errorCode(MON_ERROR);
            return false;
        }else if(arg3 < 1 || arg3 > mdays(arg1, arg2)){
            errorCode(DAY_ERROR);
            return false;
        }
        
        return true;
    }
    
	Date::Date(int _year, int _month, int _day) {
	//check if numbers are in range in order or year, month, day

		if (isValid(_year, _month, _day)){
			//set values and compare
			this->year = _year;
			this->month = _month;
			this->day_of_month = _day;
            comparator = _year * 372 * _month * 13 * _day;
            errorCode(NO_ERROR);
        }else{
            this->year = 0;
            this->month = 0;
            this->day_of_month = 0;
            comparator = 0;
        }
	}

	bool Date::operator==(const Date& rhs) const {
		//compare this object with received onject property members
        std::cout << " == operator overload called " << std::endl;
		return this->year == rhs.year && this->month == rhs.month && this->day_of_month  == rhs.day_of_month ? true : false;
	};

	bool Date::operator!=(const Date& rhs) const {
		//compare this object with received onject property members
		//return true if is not equal
        std::cout << "!= operator overload called " << std::endl;
		return *this == rhs == false? true : false;
	};

	bool Date::operator<(const Date& rhs) const {
		//check if this object's members is less than received object's propery members
		return this->year < rhs.year || this->month < rhs.month || this->day_of_month < rhs.day_of_month ? true : false;
	};

	bool Date::operator>(const Date& rhs) const {
		//check if this object's members is greater than received object's property members
		return *this < rhs == false ? true : false;
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
		return errorState;
	};

	bool Date::bad() const {
	//return true if state is not NO_ERROR
		return errorState != 0 ? true : false;
	};

	std::istream& Date::read(std::istream& istr) {
	//read date from console in formate YYYY/MM/DD
        char seperator;
		//if fail to read set error state to CIN_FAILED
        istr >> year >> seperator >> month >> seperator >> day_of_month;
		
		//call istr.fail() should return true
		if (!istr.fail()) {
		
        if (year > max_year || year < min_year) {
			errorCode(YEAR_ERROR);
			return istr;
		}
		else if(month > 12){
			errorCode(MON_ERROR);
			return istr;
		}
		else if ((year % 4 >= 1 && day_of_month > 28) || (year % 4 == 0 && day_of_month > 29)) {
			errorCode(DAY_ERROR);
			return istr;
        }
        }else{
            errorCode(CIN_FAILED);
        }
        return istr;
    }
    
	ostream& Date::write(ostream& ostr) const {
	//output date to ostream object in format YYYY/MÇM/DD
        ostr << year << "/" << ostr.width(2) << ostr.fill('0') << month << "/" << ostr.width(2) << ostr.fill('0') << day_of_month;
        return ostr;
 	}

	ostream& operator<<(ostream& ostr, const Date &c){
	//output date from object
		return c.write(ostr);
    
	}

    istream& operator>>(istream& istr, Date& c){
	//read date and store in object
        return c.read(istr);
	}

}
