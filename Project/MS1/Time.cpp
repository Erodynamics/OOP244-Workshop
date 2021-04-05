#include "Time.h"
#include "utils.h"
#include <iomanip>
using namespace std;
namespace sdds {
	Time& Time::setToNow() {
		m_min = sdds::getTime();
		return *this;
	}

	Time::Time(unsigned int min) {
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const {
		int hours = 0;
		int minutes = 0;

		// Checks if m_min is positive. Breaks down m_mins to hours and minutes and displays in H:MM format when valid.
		if (m_min > 0) {
			hours = getHour((int)this);
			minutes = getMinute((int)this);
			ostr << hours << ':' << std::setw(2) << std::setfill('0') << minutes;
		}
		return ostr;
	}

	std::istream& Time::read(std::istream& istr) {
		int hour;
		int minute;
		char throwaway;

		// Reads the istr stream. If istr is not in H:MM format, it will set failbit.
		// Otherwise, multiply hour by 60, add minute and store in the class' m_min.
		if (!(istr >> hour) || hour < 0) {
			istr.setstate(ios::failbit);
		}
		if (!(istr >> throwaway)) {
			istr.setstate(ios::failbit);
		}
		if (!(istr >> minute) || minute < 0) {
			istr.setstate(ios::failbit);
		}
		if (istr.good()) {
			m_min = (hour * 60) + minute;
		}
		return istr;
	}

	Time& Time::operator-=(const Time& D) {
		int thisHour = getHour(m_min);
		int thisMinute = getMinute(m_min);
		int dHour = getHour(D.m_min);
		int dMinute = getMinute(D.m_min);
		int diffHour = 0;
		int diffMinute = 0;

		while ((thisHour - dHour) < 0) {
			thisHour += 24;
		}
		diffHour = thisHour - dHour;

		if ((thisMinute - dMinute) < 0) {
			thisMinute += 60;
		}
		diffMinute = dMinute;
		m_min = (diffHour * 60) + diffMinute;
		return *this;
	}

	Time Time::operator-(const Time& D) const {
		Time newTime;
		int thisHour = getHour(m_min);
		int thisMinute = getMinute(m_min);
		int dHour = getHour(D.m_min);
		int dMinute = getMinute(D.m_min);
		int diffHour = 0;
		int diffMinute = 0;

		while ((thisHour - dHour) < 0) {
			thisHour += 24;
		}
		diffHour = thisHour - dHour;

		if ((thisMinute - dMinute) < 0) {
			thisMinute += 60;
		}
		diffMinute = dMinute;
		newTime.m_min = (diffHour * 60) + diffMinute;
		return newTime;
	}

	Time& Time::operator+=(const Time& D) {
		m_min += D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D) const {
		Time temp;
		temp.m_min = m_min + D.m_min;
		return temp;
	}

	Time Time::operator/(unsigned int val) const {
		Time temp;
		temp.m_min = m_min / val;
		return temp;
	}

	Time::operator unsigned int() const {
		return (unsigned int)m_min;
	}

	Time::operator int() const {
		return (int)m_min;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D) {
		D.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Time& D) {
		D.read(istr);
		return istr;
	}

	Time& Time::operator=(unsigned int val) {
		m_min = val;
		return *this;
	}
	
	Time& Time::operator*=(unsigned int val) {
		m_min *= val;
		return *this;
	}
	Time& Time::operator/=(unsigned int val) {
		m_min /= val;
		return *this;
	}
	Time Time::operator*(unsigned int val) const {
		Time temp;
		temp.m_min = m_min * val;
		return temp;
	}
}