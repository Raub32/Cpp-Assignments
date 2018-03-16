#pragma once
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
#define NO_ERROR  0;
#define CIN_FAILED  1;
#define YEAR_ERROR  2;
#define MON_ERROR  3;
#define DAY_ERROR 4;
#define MAX_YEAR  2030;
#define MIN_YEAR  2012;

#ifndef AMA_DATE_H
#define AMA_DATE_H

#include <iostream>


namespace AMA {

	class Date {
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

		int errorCode() const;
		bool bad() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
		friend std::ostream& operator<<(const std::ostream& ostr, const Date & c);
		friend std::istream& operator>>(std::istream& istr, const Date &c);
	};
}

#endif
