#include "PDF.h"
#include <iostream>

using std::cout;
using namespace PDF;

int main(int, char **) {
	// Example PDF reading
	Document doc("../src/pdf/FileName.pdf"); 	// path relative to the location of the executable
	cout << doc; 								// read entire document
	// cout << *doc.getPage(0); 				// read a single page
	
	return 0;
}
