// Workshop 4: DIY
// Date: 2/14/2021
// Author: Jean Blaise Odasco
// Student #: 114351190
// Class: OOP244
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////
#pragma once
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"

namespace sdds {
	class LabelMaker {
		Label* Labels;
		int labelsCreated;
	public:
		LabelMaker(int noOfLabels);
		~LabelMaker();

		void readLabels();
		void printLabels();
	};
}

#endif // !SDDS_LABELMAKER_H