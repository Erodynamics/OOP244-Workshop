#define _CRT_SECURE_NO_WARNINGS
#include "Stats.h"
#include <fstream>
#include <cstring>
#include <string>

namespace sdds {
	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision) {

	}

	Stats::Stats(const char* fileName, unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
		if (fileName != nullptr) {
			m_fileName = new char[strlen(fileName) + 1]();
			strcpy(m_fileName, fileName);
		}
		m_columnWidth = columnWidth;
		m_noOfColumns = noOfColumns;
		m_precision = precision;
	}

	Stats::Stats(const Stats& original) {

	}

	Stats Stats::operator=(const Stats& original) {
		
	}

	double& Stats::operator[](unsigned idx) {
		// TODO: insert return statement here
	}

	double Stats::operator[](unsigned idx) const {
		
		return 0.0;
	}

	Stats::operator bool() {

	}

	void Stats::sort(bool ascending) {

	}

	void Stats::size() const {
		int temp;
	}

	void Stats::toArray() {
		int items = 0;
		std::string rawText;
		std::ifstream csvFile(m_fileName);
		if (!csvFile.is_open()) {
			std::cout << "Failed to open file" << std::endl;
		} else {
			// Loads the CSV file and checks how many used cells are in the CSV
			std::getline(csvFile, rawText);
			for (int i = 0; i < rawText.length(); i++) {
				if (rawText[i] == ',' || rawText[i] == '\n');
				items++;
			}
			csvFile.close();
			// Checks if m_values contain anything, deletes it if it does
			if (m_values[0] != NULL) {
				delete[] m_values;
			}
			csvFile.open(m_fileName);
			m_values = new int[items];
			// Writes the array onto m_values
			for (int i = 0; i < items; i++) {
				

			}
		}
	}

	const char* Stats::name() const {
		return nullptr;
	}

	unsigned Stats::occurrence(double min, double max, std::ostream& ostr) {
		return 0;
	}
}