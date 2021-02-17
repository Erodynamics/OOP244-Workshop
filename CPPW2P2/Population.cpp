// Workshop 2: DIY
// Date: 2/1/2021
// Author: Jean Blaise Odasco
// Student #: 114351190
// Class: OOP224
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"
#include <cstring>
#include "Population.h"

namespace sdds {

	// Initialized by load function
	int postCodeCount = 0;
	PostalCode* PostalCodes;

	void sort() {
		int i, j;
		PostalCode temp = { nullptr, 0 };
		for (i = postCodeCount - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (PostalCodes[j].popCount > PostalCodes[j + 1].popCount) {
					temp = PostalCodes[j];
					PostalCodes[j] = PostalCodes[j + 1];
					PostalCodes[j + 1] = temp;
				}
			}
		}
	}

	bool load(const char filename[]) {
		bool ok = false;
		if (openFile(filename)) {
			postCodeCount = noOfRecords();
			PostalCodes = new PostalCode[postCodeCount]();

			for (int i = 0; i < postCodeCount; i++) {
				char prefix[4];
				PostalCodes[i].prefix = new char[4];
				if (read(prefix) && read(PostalCodes[i].popCount)) {
					strcpy(PostalCodes[i].prefix, prefix);
					PostalCodes[i].prefix[3] = '\0';
					ok = true;
				} else {
					std::cout << "Error: incorrect number of records read; the data is possibly corrupted." << std::endl;
				}
			}
			closeFile();
			return ok;
		} else {
			std::cout << "Could not open data file: " << filename << std::endl;
		}
		return ok;
	}

	void display() {
		int totalPop = 0;
		// Prints header
		std::cout << "Postal Code: population" << std::endl;
		std::cout << "-------------------------" << std::endl;
		sort();
		for (int i = 0; i < postCodeCount; i++) {
			std::cout << i + 1 << "- ";
			display(PostalCodes, i);
			totalPop += PostalCodes[i].popCount;
		}

		// Prints footer
		std::cout << "-------------------------" << std::endl;
		std::cout << "Population of Canada: " << totalPop << std::endl;
	}

	void display(const PostalCode* pc, int index) {
		std::cout << pc[index].prefix << ":  ";
		std::cout << pc[index].popCount << std::endl;
	}

	void deallocateMemory() {
		for (int i = 0; i < postCodeCount; i++) {
			delete[] PostalCodes[i].prefix;
		}
		delete[] PostalCodes;
	}
}