#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include "Text.h"
using namespace std;
namespace sdds {
   int Text::getFileLength() const {
	  int len = 0;
	  ifstream fin(m_filename);
	  while (fin) {
		 fin.get();
		 len += !!fin;
	  }
	  return len;
   }

   const char& Text::operator[](int index) const {
	   return m_content[index];
   }

   Text::Text(const char* filename) {
	   if (filename != nullptr) {
		   m_filename = new char[strlen(filename) + 1]();
		   strcpy(m_filename, filename);
		   m_content = new char[getFileLength() + 1]();
		   read();
	   } else {
		   m_filename = nullptr;
		   m_content = nullptr;
	   }
   }

   Text::~Text() {
	   if (m_filename != NULL) {
		   delete[] m_filename;
	   }
	   
	   if (m_content != NULL) {
		   delete[] m_content;
	   }
   }

   Text& Text::operator=(const Text& source) {
	   if (source.m_filename != nullptr) {
		   delete[] m_filename;
		   m_filename = new char[strlen(source.m_filename) + 1]();
		   strcpy(m_filename, source.m_filename);
	   } else {
		   m_filename = nullptr;
	   }
	   
	   if (source.m_content != nullptr) {
		   delete[] m_content;
		   m_content = new char[strlen(source.m_content) + 1]();
		   strcpy(m_content, source.m_content);
	   } else {
		   m_content = nullptr;
	   }

	   return *this;
   }

   void Text::read() {
	   int len = getFileLength();
	   std::ifstream file (m_filename);
	   if (file.is_open()) {
		   if (len > 0) {
			   for (int i = 0; i < len; i++) {
				   m_content[i] = file.get();
			   }
		   }
	   }
   }

   void Text::write(std::ostream& ostr) const {
	   if (m_content != NULL) {
		   ostr << m_content;
	   }
   }

   std::ostream& operator<<(std::ostream& ostr, const Text& source) {
	   source.write(ostr);
	   return ostr;
   }
}