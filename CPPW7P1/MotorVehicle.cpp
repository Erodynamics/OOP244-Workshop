#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include <cstring>
#include <iostream>

namespace sdds {
	MotorVehicle::MotorVehicle(const char* licensePlate, int year) {
		strcpy(m_licencePlate, licensePlate);
		strcpy(m_address, "Factory");
		m_year = year;
	}

	void MotorVehicle::moveTo(const char* address) {
		strcpy(m_address, address);
		if (strcmp(m_address, address)) {
			std::cout << '|' << std::right;
			std::cout.width(8);
			std::cout << m_licencePlate;
			std::cout << '| |' << std::right;
			std::cout.width(20);
			std::cout << m_address << " ---> " << address << '|' << std::endl;
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os) {
		return os << " | " << m_year << " | " << m_licencePlate << " | " << m_address << std::endl;
	}

	std::istream& MotorVehicle::read(std::istream& in) {
		std::cout << "Built year: ";
		in >> m_year;
		std::cout << "License plate: ";
		in >> m_licencePlate;
		std::cout << "Current Location: ";
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle) {
		// Unfinished
		return os;
	}
	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle) {
		// Unfinished
		return in;
	}
}