// Workshop 4: DIY
// Date: 2/14/2021
// Author: Jean Blaise Odasco
// Student #: 114351190
// Class: OOP244
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LabelMaker.h"
#include "Label.h"

namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels) {
		Labels = new Label[noOfLabels]();
		labelsCreated = noOfLabels;
	}

	LabelMaker::~LabelMaker() {
		for (int i = 0; i < labelsCreated; i++) {
			Labels[i].~Label();
		}
		delete[] Labels;
		Labels = nullptr;
	}

	void LabelMaker::readLabels() {
		std::cout << "Enter 6 labels:" << std::endl;
		for (int i = 0; i < labelsCreated; i++) {
			std::cout << "Enter label number " << (i + 1) << std::endl;
			std::cout << "> ";
			Labels[i].readLabel();
		}
	}

	void LabelMaker::printLabels() {
		for (int i = 0; i < labelsCreated; i++) {
			Labels[i].printLabel();
			if (i != labelsCreated - 1) {
				std::cout << std::endl;
			}
		}
	}
}