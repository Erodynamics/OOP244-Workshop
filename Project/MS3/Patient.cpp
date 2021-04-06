#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"
#include "Time.h"

namespace sdds {
	Patient::Patient(int tickNumber, bool imported) : m_ticket (tickNumber) {
		fromFile = imported;
		m_name = nullptr;
		m_ohip = 0;

		if (tickNumber == 0) {
			imported = false;
		}
	}

	Patient::~Patient() {
		delete[] m_name;
	}

	bool Patient::fileIO() const {
		return fromFile;
	}

	void Patient::fileIO(bool imported) {
		fromFile = imported;
	}

	bool Patient::operator==(char cmp) const {
		return cmp == type();
	}

	bool Patient::operator==(const Patient& cmp) const {
		return type() ==  cmp.type();
	}

	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	Patient::operator Time() const {
		return m_ticket;
	}

	int Patient::number() const {
		return m_ticket.number();
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr) const {
		ostr << type() << ',' << m_name << ',' << m_ohip << ',';
		m_ticket.csvWrite(ostr);
		return ostr;
	}

	std::istream& Patient::csvRead(std::istream& istr) {
		char tempName[256] = { 0 };
		delete[] m_name;
		m_name = nullptr;
		istr.getline(tempName, 256, ',');
		m_name = new char[strlen(tempName) + 1]();
		strcpy(m_name, tempName);
		istr >> m_ohip;
		istr.get();
		m_ticket.csvRead(istr);
		return istr;
	}

	std::ostream& Patient::write(std::ostream& ostr) const {
		m_ticket.write(ostr);
		ostr << std::endl;
		if (strlen(m_name) > 25) {
			for (int i = 0; i < 25; i++) {
				ostr << m_name[i];
			}
		} else {
			ostr << m_name;
		}
		ostr << ", OHIP: " << m_ohip;
		return ostr;
	}

	std::istream& Patient::read(std::istream& istr) {
		m_name = nullptr;
		m_name = getcstr("Name: ", istr, '\n');
		m_ohip = getInt(100000000, 999999999, "OHIP:", "Invalid OHIP Number, ");
		return istr;
	}
}