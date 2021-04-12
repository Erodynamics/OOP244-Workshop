#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include <iostream>
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
	  char* m_title;
   public:
	  HtmlText(const char* filename=nullptr, const char* title = nullptr);
	  ~HtmlText();
	  HtmlText& operator=(HtmlText& source);

	  void write(std::ostream& ostr) const override;
   };
}
#endif // !SDDS_HTMLTEXT_H__
