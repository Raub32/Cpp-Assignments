#pragma once
// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

// Error States
#define NO_ERROR = 0;
#define CIN_FAILED = 1;
#define YEAR_ERROR = 2;
#define MON_ERROR = 3;
#define DAY_ERROR = 4;

namespace AMA {

	-class Date {
		int year;
		int day_of_month;
		int month;
		int dateIsRecent;
		int errorState;
	public:
		int mdays(int mon, int year)const;
		void errCode(int errorCode);
		
		// class constructor
		Date();
		Date(int year, int month, int day);
		
		//operator overloads
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		int errCode() const;
		bool bad() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
		friend operator<<(const std::ostream& ostr) const;
		friend operator>>(std::istream& istr);

	};
}
#endif