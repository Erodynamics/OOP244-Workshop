#define _CRT_SECURE_NO_WARNINGS
#include "PreTriage.h"
#include "Time.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "Patient.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <cstring>

namespace sdds {
	PreTriage::PreTriage(const char* dataFilename) :

		m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), 
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {

		m_dataFilename = new char[strlen(dataFilename) + 1]();
		strcpy(m_dataFilename, dataFilename);

		m_averCovidWait = 15;
		m_averTriageWait = 5;
		load();
	}

	PreTriage::~PreTriage() {
		// Is possibly jank, suspect for bugs.
		std::ofstream output(m_dataFilename);

		std::cout << "Saving Average Wait Times," << std::endl;
		std::cout << "   COVID Test: " << m_averCovidWait << std::endl;
		std::cout << "   Triage: " << m_averTriageWait << std::endl;
		std::cout << "Saving m_lineup..." << std::endl;

		output << m_averCovidWait << ',' << m_averTriageWait << std::endl;

		if (output.good()) {
			for (int i = 0; i < m_lineupSize; i++) {
				m_lineup[i]->csvWrite(output);
				std::cout << i + 1 << "- ";
				m_lineup[i]->csvWrite(std::cout);
				output << std::endl;
				std::cout << std::endl;
			}
		}

		output.close();

		for (int i = 0; i < maxNoOfPatients; i++) {
			delete m_lineup[i];
		}

		delete[] m_dataFilename;
		std::cout << "done!\n";
	}

	void PreTriage::run(void) {
		// Fairly simple, hard to screw up. Less likely to have bugs.
		
		int choice = -1;
		bool exit = false;

		while (!exit) {
			m_appMenu >> choice;
			switch (choice) {
			case 1:
				reg();
				break;
			case 2:
				admit();
				break;
			case 0:
				exit = true;
				break;
			}
		}
	}

	void PreTriage::reg() {
		int choice = -1;
		Patient* newPatient = nullptr;
		if (m_lineupSize < maxNoOfPatients) {
			m_pMenu >> choice;

			switch (choice) {
			case 1:
				// New COVID Patient
				newPatient = new CovidPatient();
				break;

			case 2:
				// New Triage Patient
				newPatient = new TriagePatient();
				break;

			case 0:
				// Exit
				break;
			}

			if (newPatient != nullptr) {

				newPatient->setArrivalTime();
				std::cout << "Please enter patient information: \n";
				newPatient->fileIO(false);
				newPatient->read(std::cin);

				std::cout << std::endl;

				std::cout << "******************************************\n";
				newPatient->write(std::cout);
				std::cout << "Estimated Wait Time: " << getWaitTime(*newPatient) << std::endl;
				std::cout << "******************************************\n\n";

				m_lineup[m_lineupSize] = newPatient;
				m_lineupSize++;
				
			}
		} else {
			std::cout << "Line up full!\n";
		}
	}

	void PreTriage::admit() {
		int choice = -1;
		int nextPatient = -1;
		m_pMenu >> choice;

		switch (choice) {
		case 1:
			// Get next COVID patient
			nextPatient = indexOfFirstInLine('C');
			break;

		case 2:
			// Get next Triage patient
			nextPatient = indexOfFirstInLine('T');
			break;

		case 0:
			// Exit
			break;
		}

		if (nextPatient != -1) {
			std::cout << "\n******************************************\n";
			m_lineup[nextPatient]->fileIO(false);
			std::cout << "Calling for ";
			m_lineup[nextPatient]->write(std::cout);
			std::cout << "******************************************\n\n";
			setAverageWaitTime(*m_lineup[nextPatient]);
			removePatientFromLineup(nextPatient);
		}
	}

	const Time PreTriage::getWaitTime(const Patient& p) const {
		int typeCount = 0;
		for (int i = 0; i < m_lineupSize; i++) {
			if (p.type() == m_lineup[i]->type()) {
				typeCount++;
			}
		}
		
		if (p.type() == 'T') {
			return m_averTriageWait.operator*(typeCount);
		} else if (p.type() == 'C') {
			return m_averCovidWait.operator*(typeCount);
		} else {
			// This should never happen, a Pre-Triage patient is either in Triage or has COVID.
			return 0;
		}
	}

	void PreTriage::setAverageWaitTime(const Patient& p) {
		Time CT = getTime();
		
		// This is sketch and GCC might complain about the type conversions.
		if (p.type() == 'T') {
			m_averTriageWait = ((CT - p).operator int() + (m_averTriageWait.operator int() * (p.number() - 1) / p.number()));
		} else if (p.type() == 'C') {
			m_averCovidWait = ((CT - p).operator int() + (m_averCovidWait.operator int() * (p.number() - 1) / p.number()));
		}
	}

	void PreTriage::removePatientFromLineup(int index) {
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const {
		int firstLineIndex = -1;
		bool found = false;

		for (int i = 0; !found && i < maxNoOfPatients; i++) {
			if (m_lineup[i]->type() == type) {
				firstLineIndex = i;
				found = true;
			}
		}

		return firstLineIndex;
	}

	void PreTriage::load() {
		// Lots of black boxes, suspect for bugs.
		std::ifstream csv(m_dataFilename);
		bool limit = false;
		std::cout << "Loading data...\n";
		Patient* newPatient = nullptr;
		char patientType = '\0';

		// Loading average wait times
		csv >> m_averCovidWait;
		csv.get();
		csv >> m_averTriageWait;
		csv.get();

		// Load patients from CSV file
		if (csv.good()) {
			while (!csv.eof() && !limit) {
				patientType = csv.get();

				if (patientType == 'C') {
					newPatient = new CovidPatient();
					csv.get();
				} else if (patientType == 'T') {
					newPatient = new TriagePatient();
					csv.get();
				} else {
					newPatient = nullptr;
					csv.get();
				}

				if (newPatient != nullptr) {
					newPatient->fileIO(true);
					newPatient->csvRead(csv);
					newPatient->fileIO(false);

					m_lineup[m_lineupSize] = newPatient;
					m_lineupSize++;

					if (m_lineupSize == 100) {
						limit = true;
						if (!csv.eof()) {
							std::cout << "Warning: number of records exceeded 100\n";
						}
					}
				}
			}
		}

		if (m_lineupSize == 0) {
			std::cout << "No data or bad data file!\n\n";
		} else {
			std::cout << m_lineupSize << " Records imported...\n\n";
		}
	}
}