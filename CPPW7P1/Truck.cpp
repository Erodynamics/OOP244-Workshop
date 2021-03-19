#include "Truck.h"
#include "MotorVehicle.h"

namespace sdds {
	Truck::Truck(const char* licensePlate, int year, double capacity, const char* address) : MotorVehicle(licensePlate, year) {
		m_capacity = capacity;
		m_cargoLoad = 0;
		moveTo(address);
	}

	bool Truck::addCargo(double cargo) {
		double emptySpace = m_capacity - m_cargoLoad;
		if (emptySpace - cargo < 0) {
			if (emptySpace != 0) {
				m_cargoLoad = m_capacity;
				return true;
			} else {
				return false;
			}
		} else {
			m_cargoLoad += cargo;
			return true;
		}
	}

	bool Truck::unloadCargo() {
		if (m_cargoLoad != 0) {
			m_cargoLoad = 0;
			return true;
		} else {
			return false;
		}
	}

	std::ostream& Truck::write(std::ostream& os) const {
		return MotorVehicle::write(os) << " | " << m_cargoLoad << " / " << m_capacity;
	}

	std::istream& Truck::read(std::istream& in) {
		Truck temp("", 0, 0, "");
		temp.MotorVehicle::read(in);
		std::cout << "Capacity: ";
		in >> temp.m_capacity;
		std::cout << "Cargo: ";
		in >> temp.m_cargoLoad;

		// Time to copy
		m_capacity = temp.m_capacity;
		m_cargoLoad = temp.m_cargoLoad;
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const Truck& vehicle) {
		return vehicle.write(os);
	}

	std::istream& operator>>(std::istream& in, Truck& vehicle) {
		return vehicle.read(in);
	}
}