#include "cstring.h"
#define _CRT_SECURE_NO_WARNINGS

namespace sdds {
	void strCpy(char* des, const char* src) {
		int i;
		for (i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	void strnCpy(char* des, const char* src, int len) {
		int desLen = strLen(des);
		int i;
		for (i = 0; i < len; i++) {
			des[i] = src[i];
		}
		des[desLen] = '\0';
		
	}

	int strCmp(const char* s1, const char* s2) {
		int str1Val = 0;
		int str2Val = 0;
		// Adds the ASCII values of s1 and s2, 
		for (int i = 0; i < strLen(s1); i++) {
			str1Val += s1[i];
			str2Val += s2[i];
		}
		return str1Val - str2Val;
	}

	int strnCmp(const char* s1, const char* s2, int len) {
		int str1Val = 0;
		int str2Val = 0;
		for (int i = 0; i < len; i++) {
			str1Val += s1[i];
			str2Val += s2[i];
		}
		return str1Val - str2Val;
	}

	int strLen(const char* s) {
		bool breakFlag = false;
		int count = 0;
		char currentChar;
		do {
			currentChar = s[count];
			if (currentChar != '\0') {
				count++;
			}
			else {
				breakFlag = true;
			}
		} while (!breakFlag);
		return count;
	}

	const char* strStr(const char* str1, const char* str2) {
		int str1Len = strLen(str1);
		int str2Len = strLen(str2);
		int i;
		int j = 0;
		bool found = false;
		int firstMatch = 0;

		for (i = 0; i < str1Len && !found; i++) {
			if (str1[i] == str2[j]) {
				// If all parts of str2 is matched within str1, raise found flag
				j++;
				if (j == str2Len) {
					found = true;
				}
			} else {
				// Resets variable j if a character that doesn't match is found
				j = 0;
				found = false;
			}
			if (j == 1) {
				firstMatch = i;
			}
		}
		if (found == true) {
			return &str1[firstMatch];
		} else {
			return nullptr;
		}
	}

	void strCat(char* des, const char* src) {
		strCpy(des + strLen(des), src);
	}
}