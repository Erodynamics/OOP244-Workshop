#pragma once
#ifndef _SDDS_MOTORVEHICLE_H
#define _SDDS_MOTORVEHICLE_H
#include <iostream>

namespace sdds {
	class MotorVehicle {
		char m_licencePlate[9];
		char m_address[64];
		int m_year;
	public:
		MotorVehicle(const char* licensePlate, int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);

		// Stream stuff not implemented
		friend std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);
		friend std::istream& operator>>(std::istream& in, MotorVehicle& vehicle);
	};
}

#endif //_SDDS MOTORVEHICLE_H