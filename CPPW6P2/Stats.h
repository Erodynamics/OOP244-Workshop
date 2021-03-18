#ifndef _SDDS_STATS_H
#define _SDDS_STATS_H
#include <iostream>
namespace sdds {
	class Stats {
		char* m_fileName;
		unsigned m_columnWidth;
		unsigned m_noOfColumns;
		unsigned m_precision;
		int* m_values;

		Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision);
		Stats(const char* fileName, unsigned columnWidth, unsigned noOfColumns, unsigned precision);
		Stats(const Stats& original);
		Stats operator=(const Stats& original);

		double& operator[](unsigned idx);
		double operator[](unsigned idx) const;
		operator bool();

		void sort(bool ascending);
		void size()const;
		void toArray();
		const char* name()const;

		unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
	};
}
#endif // _SDDS_STATS_H