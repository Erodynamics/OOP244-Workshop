#include "Truck.h"
#include "MotorVehicle.h"

namespace sdds {
	Truck::Truck(const char* licensePlate, int year, double capacity, const char* address) : MotorVehicle(licensePlate, year) {
		m_capacity = capacity;
		m_cargoLoad = 0;
		moveTo(address);
	}

	bool Truck::addCargo(double cargo) {
		double diff = m_capacity - (m_cargoLoad + cargo);
		if (m_cargoLoad + cargo > m_capacity) {
			if (diff < 0) {
				m_cargoLoad += diff * 2;
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
		m_cargoLoad = 0;
		if (m_cargoLoad == 0) {
			return true;
		} else {
			return false;
		}
	}

	std::ostream& Truck::write(std::ostream& os, Truck truck) {
		return MotorVehicle::write(os) << " | " << m_cargoLoad << " / " << m_capacity;
	}

	std::istream& Truck::read(std::istream& in, Truck truck) {
		MotorVehicle::read(in);
		std::cout << "Capacity: ";
		in >> m_capacity;
		std::cout << "Cargo: ";
		in >> m_cargoLoad;
		return in;
	}
}