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
#include "Label.h"

namespace sdds {
	Label::Label() {
		frame = new char[9]();
		labelContent = new char[71]();
		strcpy(frame, "+-+|+-+|");
	}
	Label::Label(const char* frameArg) {
		frame = new char[9]();
		labelContent = new char[71]();
		strcpy(frame, frameArg);
	}
	Label::Label(const char* frameArg, const char* content) {
		frame = new char[9]();
		labelContent = new char[71]();
		strcpy(frame, frameArg);
		strcpy(labelContent, content);
	}
	Label::~Label() {
		delete[] frame;
		delete[] labelContent;
		frame = nullptr;
		labelContent = nullptr;
	}
	void Label::readLabel() {
		char temp[71] = { 0 };
		std::cin.getline(temp, 71);
		if (temp[0] != 0) {
			strcpy(labelContent, temp);
		}
	}
	std::ostream& Label::printLabel() const {

		///////////////////////////////////////////////////
		// Layout 01234567
		// 
		// 011111111111111111111111112
		// 7                         3
		// 7                         3 Content goes on this line
		// 7                         3
		// 655555555555555555555555554
		//
		///////////////////////////////////////////////////

		int contentLen = strlen(labelContent);

		if (labelContent[0] != 0) {
			// Top frame
			std::cout << frame[0];
			for (int i = 0; i < contentLen + 2; i++) {
				std::cout << frame[1];
			}
			std::cout << frame[2] << std::endl;

			// Mid frame
			std::cout << frame[7];
			for (int i = 0; i < contentLen + 2; i++) {
				std::cout << " ";
			}
			std::cout << frame[3] << std::endl;

			std::cout << frame[7] << " " << labelContent << " " << frame[3] << std::endl;

			std::cout << frame[7];
			for (int i = 0; i < contentLen + 2; i++) {
				std::cout << " ";
			}
			std::cout << frame[3] << std::endl;

			// Bottom frame
			std::cout << frame[6];
			for (int i = 0; i < contentLen + 2; i++) {
				std::cout << frame[5];
			}
			return std::cout << frame[4] ;
		}
		else {
			return std::cout;
		}
	}
}