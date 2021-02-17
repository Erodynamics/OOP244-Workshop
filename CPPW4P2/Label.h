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
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
namespace sdds {
	class Label {
		char* labelContent;
		char* frame;
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		std::ostream& printLabel()const;
	};
}
#endif // !SDDS_LABEL_H