#pragma once
#ifndef _SDDS_TRUCK_H
#define _SDDS_TRUCK_H
#include "MotorVehicle.h"
#include <iostream>

namespace sdds {
	class Truck : public MotorVehicle {
		// This should be in kilograms.
		double m_capacity;
		double m_cargoLoad;
	public:
		Truck(const char* licensePlate, int year, double capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);

		friend std::ostream& operator<<(std::ostream& os, const Truck& vehicle);
		friend std::istream& operator>>(std::istream& in, Truck& vehicle);
	};
}

#endif // _SDDS_TRUCK_H