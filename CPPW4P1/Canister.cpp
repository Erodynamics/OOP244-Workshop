// Workshop 4: Lab
// Date: 2/11/2021
// Author: Jean Blaise Odasco
// Student #: 114351190
// Class: OOP244
// I have done all the coding by myself and only copied the code that my professor provided to
// complete my workshops and assignments.
//
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring>  // using strLen, strCpy and strCmp 
#include "Canister.h"

double pi = 3.14159265;
namespace sdds {
	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_diameter = 10.0;
		m_height = 13.0;
		m_contentVolume = 0;
		m_usable = true;
	}

	void Canister::setName(const char* Cstr){
		if (Cstr != nullptr && m_usable) {
			delete[] m_contentName;
			m_contentName = new char[strlen(Cstr) + 1]();
			m_contentName[strlen(Cstr)] = 0;
			strcpy(m_contentName, Cstr);
		}
	}

	bool Canister::isEmpty() const {
		if (m_contentVolume < 0.00001) {
			return true;
		} else {
			return false;
		}
	}

	bool Canister::hasSameContent(const Canister& C) const {
		bool cN1Valid = false;
		bool cN2Valid = false;
		if (m_contentName != nullptr) {
			if (m_contentName[0] != 0) {
				cN1Valid = true;
			}
		}
		if (C.m_contentName != nullptr) {
			if (C.m_contentName[0] != 0) {
				cN2Valid = true;
			}
		}

		if (cN1Valid && cN2Valid) {
			if (strcmp(m_contentName, C.m_contentName) == 0) {
				return true;
			} else {
				return false;
			}
		} else if (cN1Valid == cN2Valid) {
			return true;
		} else {
			return false;
		}
	}

	Canister::Canister() {
		setToDefault();
	}

	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName) {
		setToDefault();

		// Check for invalid values, set as unusable if found
		if (height < 10 || height > 40 || diameter < 10 || diameter > 30) {
			m_usable = false;
		} else {
			m_height = height;
			m_diameter = diameter;
			setName(contentName);
		}
	}

	Canister::~Canister() {
		void clear();
	}

	Canister& Canister::setContent(const char* contentName) {
		if ((!hasSameContent(contentName) && m_contentVolume != 0) || contentName == nullptr) {
			m_usable = false;
		}
		setName(contentName);
		return *this;
	}

	Canister& Canister::pour(double quantity) {
		m_contentVolume += quantity;
		if (m_contentVolume > capacity()) {
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(Canister& C) {
		double diff = capacity() - volume();
		if (m_contentVolume > 0 && !hasSameContent(C)) {
			m_usable = false;
		}
		setName(C.m_contentName);
		if (m_contentVolume + C.m_contentVolume > capacity()) {
			pour(diff);
			C.m_contentVolume -= (diff);
		} else {
			pour(C.m_contentVolume);
			C.m_contentVolume = 0;
		}
		return *this;
	}

	double Canister::volume() const {
		return m_contentVolume;
	}

	std::ostream& Canister::display() const {\
		std::cout.width(7);
		std::cout << std::fixed << std::setprecision(1);
		std::cout << capacity();
		std::cout << "cc (" << m_height << "x" << m_diameter << ") Canister";

		if (m_usable) {
			if (m_contentName != nullptr) {
				std::cout << " of ";
				std::cout.width(7);
				std::cout << std::right << m_contentVolume << "cc   ";
				return std::cout << m_contentName;
			} else {
				return std::cout;
			}
		} else {
			return std::cout << " of Unusable content, discard!";
		}
	}

	double Canister::capacity() const{
		return pi * (m_diameter / 2) * (m_diameter / 2) * (m_height - 0.267);
	}

	void Canister::clear() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0;
		m_usable = true;
	}
}