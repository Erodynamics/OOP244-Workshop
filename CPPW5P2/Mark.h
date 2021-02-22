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
