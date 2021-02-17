#pragma once
#ifndef _W1_FILE_H
#define	_W1_FILE_H
#include "ShoppingRec.h"

namespace sdds {
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif