// Workshop 5: DIY
// Date: 2/21/21
// Author: Jean Blaise Odasco
// Student #: 114351190
// Class: OOP244
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Mark.h"

namespace sdds {
	void Mark::setEmpty() {
		markPercent = 0;
	}

	Mark::Mark() {
		markPercent = 0;
	}

	Mark::Mark(int newStudentMark) {
		markPercent = newStudentMark;
	}

	Mark::operator int() const {
		if (0 <= markPercent && markPercent <= 100) {
			return markPercent;
		} else {
			return 0;
		}
	}

	Mark::operator double() const {
		if (0 <= markPercent && markPercent < 50) {
			return 0;
		}
		if (50 <= markPercent && markPercent < 60) {
			return 1;
		}
		if (60 <= markPercent && markPercent < 70) {
			return 2;
		}
		if (70 <= markPercent && markPercent < 80) {
			return 3;
		}
		if (80 <= markPercent && markPercent <= 100) {
			return 4;
		}
		return 0;
	}

	Mark::operator char() const {
		if (1 <= markPercent && markPercent < 50) {
			return 'F';
		}
		if (50 <= markPercent && markPercent < 60) {
			return 'D';
		}
		if (60 <= markPercent && markPercent < 70) {
			return 'C';
		}
		if (70 <= markPercent && markPercent < 80) {
			return 'B';
		}
		if (80 <= markPercent && markPercent <= 100) {
			return 'A';
		}
		return 'X';
	}

	Mark& sdds::Mark::operator+=(int addedMark) {
		int combinedMarks = addedMark + markPercent;
		if (0 <= combinedMarks && combinedMarks <= 100) {
			markPercent = combinedMarks;
		} else {
			markPercent = 0;
		}
		return *this;
	}

	Mark& sdds::Mark::operator=(int assignedMark) {
		if (assignedMark >= 0 && assignedMark <= 100) {
			markPercent = assignedMark;
		} else {
			markPercent = 0;
		}
		return *this;
	}

	int operator+=(int& addedMark, const Mark& studentMarks) {
		if (0 <= (int)studentMarks && (int)studentMarks <= 100) {
			return addedMark += (int)studentMarks;
		} else {
			return addedMark;
		}
	}
}