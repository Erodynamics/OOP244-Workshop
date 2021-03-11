#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include <cstring>

namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }

   Line::Line() {
       m_value = nullptr;
   }

   Line::~Line() {
       delete[] m_value;
   }

   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strlen(lineValue) + 1]();
      strcpy(m_value, lineValue);
      return *this;
   }

   void TextFile::setFilename(const char* fname, bool isCopy) {
       if (isCopy) {
           m_filename = new char[strlen(fname) + 3]();
           strcpy(m_filename, fname);
       } else {
           m_filename = new char[strlen(fname) + 3]();
           strcpy(m_filename, "C_");
           strcat(m_filename, fname);
       }
   }

   void TextFile::setNoOfLines() {
       char currentChar;
       std::ifstream file;
       int lineCount = 0;
       if (this) {
           file.open(m_filename);
           do {
               file.get(currentChar);
               if (currentChar == '\n') {
                   lineCount++;
               }
           } while (!file.eof());
       }
       m_noOfLines = lineCount;
   }

   void TextFile::loadText() {
       std::string temp;
       if (this) {
           delete[] m_textLines;
           m_textLines = new Line[m_noOfLines]();
           std::ifstream file(m_filename);
           for (int i = 0; i < m_noOfLines; i++) {
               std::getline(file, temp);
               strcpy(m_textLines[i].m_value, temp.c_str());
           }
       }
   }

   void TextFile::saveAs(const char* fileName) const {

   }

   void TextFile::setEmpty() {
       delete[] m_textLines;
       delete[] m_filename;
       m_textLines = nullptr;
       m_filename = nullptr;
       m_noOfLines = 0;
   }

   TextFile::TextFile(unsigned pageSize) {
       m_textLines = nullptr;
       m_filename = nullptr;
       m_noOfLines = 0;
       m_pageSize = pageSize;
   }

   TextFile::TextFile(const char* filename, unsigned pageSize) {
       m_pageSize = pageSize;
       if (filename[0] != NULL) {
           setFilename(filename, false);
           loadText();
           setNoOfLines();
       } else {
           m_textLines = nullptr;
           m_noOfLines = 0;
       }
   }

   TextFile::TextFile(const TextFile& source) {
       m_pageSize = source.m_pageSize;
       if (source) {
           setFilename(m_filename, true);
           loadText();
           setNoOfLines();
       } else {
           m_textLines = nullptr;
           m_noOfLines = 0;
       }
   }

   TextFile& TextFile::operator=(const TextFile& source) {
       // TODO: insert return statement here
   }

   TextFile::~TextFile() {
       delete[] m_textLines;
       delete[] m_filename;
       m_noOfLines = 0;
       m_pageSize = 0;
   }

   std::ostream& TextFile::view(std::ostream& ostr) const {
       if (this) {

       }
   }

   std::istream& TextFile::getFile(std::istream& istr) {
       istr.getline(m_filename, 50, '\n');
       setNoOfLines();
       loadText();
       return istr;
   }

   TextFile::operator bool() const {
       if (m_filename != nullptr) {
           return true;
       } else {
           return false;
       }
   }

   unsigned TextFile::lines() const {
       return 0;
   }

   const char* TextFile::name() const {
       return nullptr;
   }

   const char* TextFile::operator[](unsigned index) const {
       unsigned correctIndex;
       if (index > m_noOfLines) {
           
       } else {
           correctIndex = index;
       }
       return nullptr;
   }

   std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
       return text.view(ostr);
   }

   std::istream& operator>>(std::istream& istr, TextFile& text) {
       
       return text.getFile(istr);
   }

}