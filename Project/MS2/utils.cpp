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
	// Part of this code was written by 
	int getInt(const char* prompt) {
		bool valid = true;
		int input = -1;

		if (prompt != nullptr) {
			std::cout << prompt;
		}

		do {
			valid = true;
			std::cin >> input;
			if (std::cin.fail()) {
				std::cin.clear();
				valid = false;
				std::cout << "Bad integer value, try again: ";
			}

			if (std::cin.get() != '\n') {
				std::cin.clear();
				valid = false;
				std::cout << "Enter only an integer, try again: ";
			}
		} while (!valid);
		return input;
	}

	int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {
		int input = -2;

		do {
			if (input == -2) {
				input = getInt(prompt);
			} else {
				input = getInt();
			}

			if (min > input || input > max) {
				if (errorMessage != NULL) {
					std::cout << errorMessage;
					input = -1;
				}
				if (showRangeAtError) {
					std::cout << '[' << min << " <= value <= " << max << ']' << ": ";
					input = -1;
				}
			}
		} while (input <= -1);
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