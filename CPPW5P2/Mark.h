// Workshop 5: DIY
// Date: 2/21/21
// Author: Jean Blaise Odasco
// Student #: 114351190
// Class: OOP244
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////
#pragma once
#ifndef _SDDS_MARK_H
#define _SDDS_MARK_H

namespace sdds {
	class Mark {
		int markPercent;
		void setEmpty();
	public:
		Mark();
		Mark(int newStudentMark);
		operator int()const;
		operator double()const;
		operator char()const;

		Mark& operator += (int addedMark);
		Mark& operator = (int assignedMark);
	};
	int operator += (int& addedMarks, const Mark& studentMarks);
}

#endif // !_SDDS_MARK_H
