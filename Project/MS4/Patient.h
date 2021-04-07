#pragma once
#ifndef _SDDS_PATIENT_H
#define _SDDS_PATIENT_H
#include <iomanip>
#include "IOAble.h"
#include "Ticket.h"

namespace sdds {
	class Patient : public IOAble {
		char* m_name;
		int m_ohip;
		Ticket m_ticket;
		bool fromFile;
	public:
		Patient(int tickNumber, bool imported = false);
		Patient& operator=(Patient&) = delete;
		Patient(Patient&) = delete;
		~Patient() override;

		virtual char type() const = 0;

		bool fileIO() const;
		void fileIO(bool imported);

		bool operator==(char cmp) const;
		bool operator==(const Patient& cmp) const;

		void setArrivalTime();
		operator Time() const;
		int number() const;

		std::istream& csvRead(std::istream& istr) override;
		std::istream& read(std::istream& istr) override;
		std::ostream& csvWrite(std::ostream& ostr) const override;
		std::ostream& write(std::ostream& ostr) const override;
		
	};
}

#endif // _SDDS_PATIENT_H