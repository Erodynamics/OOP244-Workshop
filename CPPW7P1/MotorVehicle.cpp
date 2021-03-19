#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include <cstring>
#include <iostream>

namespace sdds {
	MotorVehicle::MotorVehicle(const char* licensePlate, int year) {
		// Initalizes class with license plate and year. Default address is "Factory".
		strcpy(m_licencePlate, licensePlate);
		m_licencePlate[8] = 0;
		for (int i = 0; i < 64; i++) {
			m_address[i] = 0;
		}
		strcpy(m_address, "Factory");
		m_year = year;
	}

	void MotorVehicle::moveTo(const char* address) {
		std::string oldAddress = m_address;
		strcpy(m_address, address);
		// Checks if there are any changes in m_address and the first index is not NULL, display it if everything checks out
		if (m_address[0] != 0) {
			if (strcmp(m_address, address) == 0) {
				std::cout << "|" << std::right;
				std::cout.width(8);
				std::cout << m_licencePlate;
				std::cout << "| |" << std::right;
				std::cout.width(20);
				std::cout << oldAddress;
				std::cout << " ---> " << std::left;
				std::cout.width(20);
				std::cout << m_address;
				std::cout << "|" << std::endl;
			}
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os)const {
		return os << "| " << m_year << " | " << m_licencePlate << " | " << m_address;
	}

	std::istream& MotorVehicle::read(std::istream& in) {
		MotorVehicle temp("", 0);
		// Grab input from user
		std::cout << "Built year: ";
		in >> temp.m_year;
		std::cout << "License plate: ";
		in >> temp.m_licencePlate;
		std::cout << "Current location: ";
		in >> temp.m_address;
		
		// Time to copy
		m_year = temp.m_year;
		strcpy(m_licencePlate, temp.m_licencePlate);
		strcpy(m_address, temp.m_address);
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle) {
		return vehicle.write(os);
	}
	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle) {
		return vehicle.read(in);
	}
}