
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
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
// Error States

#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>

#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4
#define max_year 2030
#define min_year 2000

namespace AMA {

	class Date {
		int year;
		int day_of_month;
		int month;
		int comparator;
		int errorState;
        void errorCode(int errorCode);
    public:
		int mdays(int mon, int year)const;

		// class constructor
		Date();
		Date(int _year, int _month, int _day);

		//operator overloads
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
        void operator=(const Date& rhs);

		int errCode() const;
		bool bad() const;
        std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
        bool isValid(int arg1, int ag2, int arg3 );
	};
	
	std::ostream& operator<<(std::ostream& ostr, const Date & c);
	std::istream& operator>>(std::istream& istr, Date &c);
}

#endif
