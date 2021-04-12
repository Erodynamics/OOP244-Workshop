#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HtmlText.h"
namespace sdds {
	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
		if (title != NULL) {
			m_title = new char[strlen(title) + 1]();
			strcpy(m_title, title);
		} else {
			m_title = nullptr;
		}
	}

	HtmlText::~HtmlText() {
		if (m_title != NULL) {
			delete[] m_title;
		}
		m_title = nullptr;
	}

	HtmlText& HtmlText::operator=(HtmlText& source) {
		this->Text::operator=(source);
		if (source.m_title != NULL) {
			if (m_title != NULL) {
				delete[] m_title;
			}
			m_title = new char[strlen(source.m_title) + 1]();
			strcpy(m_title, source.m_title);
		} else {
			m_title = nullptr;
		}

		return *this;
	}

	void HtmlText::write(std::ostream& ostr) const {
		int contentLength = strlen(Text::write)
		bool MS = false;
		ostr << "<html><head><title>";
		if (m_title != NULL) {
			ostr << m_title;
		} else {
			ostr << "No Title";
		}
		ostr << "</title></head>\n<body>\n";
		if ("</title>\n\n" != NULL) {
			ostr << "<h1>" << m_title << "</h1>\n";
		}
		for (int i = 0; i < )
	}
}