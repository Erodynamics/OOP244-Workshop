#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Mark.h"

namespace sdds {
	void Mark::setEmpty() {
		markPercent = 0;
		grade = 'X';
		gpa = 0.0;
	}

	char Mark::calculateGrade(int mark) {
		if (mark < 50) {
			return 'F';
		}
		if (mark > 50 && mark <= 60) {
			return 'D';
		}
		if (mark > 60 && mark <= 70) {
			return 'C';
		}
		if (mark > 70 && mark <= 80) {
			return 'B';
		}
		if (mark > 80 && mark <= 100) {
			return 'A';
		}
		return 'X';
	}

	double Mark::calculateGPA(int mark) {
		if (mark > 50 && mark <= 60) {
			return 1.0;
		}
		if (mark > 60 && mark <= 70) {
			return 2.0;
		}
		if (mark > 70 && mark <= 80) {
			return 3.0;
		}
		if (mark > 80 && mark <= 100) {
			return 4.0;
		}
		return 0.0;
	}

	Mark::Mark() {
		markPercent = 0;
		grade = 'X';
		gpa = 0.0;
	}

	Mark::Mark(int newStudentMark) {
		if (newStudentMark > 0 && newStudentMark <= 100) {
			markPercent = newStudentMark;
			grade = calculateGrade(markPercent);
			gpa = calculateGPA(markPercent);
		} else {
			markPercent = 0;
			grade = 'X';
			gpa = 0.0;
		}
	}

	Mark::operator int() const {
		return markPercent;
	}

	Mark::operator double() const {
		return gpa;
	}

	Mark::operator char() const {
		return grade;
	}

	Mark& sdds::Mark::operator+=(int addedMark) {
		
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

	int operator+=(int addedMarks, const Mark& studentMarks) {
		int combinedMarks = addedMarks + (int)studentMarks;
		if (combinedMarks >= 0 && combinedMarks <= 100) {
			return combinedMarks;
		} else {
			return addedMarks;
		}
	}
}