#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
	bool debug = false;  // made global in utils.h
	int getTime() {
		int mins = -1;
		if (debug) {
			Time t(0);
			cout << "Enter current time: ";
			do {
				cin.clear();
				cin >> t;   // needs extraction operator overloaded for Time
				if (!cin) {
					cout << "Invlid time, try agian (HH:MM): ";
					cin.clear();
				} else {
					mins = int(t);
				}
				cin.ignore(1000, '\n');
			} while (mins < 0);
		} else {
			time_t t = time(NULL);
			tm lt = *localtime(&t);
			mins = lt.tm_hour * 60 + lt.tm_min;
		}
		return mins;
	}

	int getInt(const char* prompt) {
		std::string input;
		bool valid;
		int errorCount = 0;

		if (prompt != NULL) {
			std::cout << prompt;
		}

		do {
			valid = true;
			errorCount = 0;

			std::getline(std::cin, input);
			
			for (unsigned i = 0; i < input.length(); i++) {
				if (!isdigit(input[i])) {
					valid = false;
					errorCount++;
				}
			}
			if ((unsigned)errorCount >= input.length()) {
				std::cout << "Bad integer value, try again: ";
				std::cin.clear();
			} else if (!valid) {
				std::cout << "Enter only an integer, try again: ";
				std::cin.clear();
			}
		} while (!valid);
		return std::stoi(input);
	}

	int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {
		int input = 0;
		do {
			input = getInt(prompt);
			if ((min > input || input > max)) {
				if (errorMessage != NULL) {
					std::cout << errorMessage;
					input = 0;
				}
				if (showRangeAtError) {
					std::cout << '[' << min << " <= value <= " << max << ']';
					input = 0;
				}
			}
		} while (input == 0);
		return input;
	}

	char* getcstr(const char* prompt, std::istream& istr, char delimiter) {
		char* returned;
		char temp[256] = { 0 };
		if (prompt != NULL) {
			std::cout << prompt;
			if (delimiter != NULL) {
				istr.getline(temp, 256, delimiter);
			} else {
				istr.getline(temp, 256);
			}
		}
		returned = new char[strlen(temp) + 1]();
		strcpy(returned, temp);
		return returned;
	}
	int getHour(int minutes) {
		return minutes / 60;
	}
	int getMinute(int minutes) {
		return minutes % 60;
	}
}