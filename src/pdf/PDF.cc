#include "PDF.h"
#include <filesystem>
#include <iostream>
#include <memory>
#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>
#include <stdexcept> // not included in header
#include <string>
#include <vector>

using std::filesystem::path, std::ostream, std::out_of_range, std::string, std::unique_ptr, std::vector;
using poppler::document; // poppler::page typedef in PDF.h
using PDF::Document;

// ctors
Document::Document(const string &filePath) : p(filePath), doc(unique_ptr<document>(document::load_from_file(p.c_str()))), pageCount(doc->pages()) {}
Document::Document(const char *&filePath) : Document(string(filePath)) {}

// working with page objects
unique_ptr<Document::Page> Document::getPage(const int i) const {
	if (i < 0 || i >= pageCount)
		throw out_of_range("Invalid page number");
	return unique_ptr<Document::Page>(doc->create_page(i));
}
string Document::readPage(const Document::Page &page) const {
	return page.text().to_latin1();
}

// working with indexes
string Document::readPage(const int i) const {
	unique_ptr<Document::Page> currentPage = getPage(i);
	return readPage(*currentPage);
}

// read an entire PDF
string Document::readPDF() const {
	string documentText;
	for (int i = 0; i < pageCount; ++i)
		documentText += readPage(i);
	return documentText;
}

// example useful operators
ostream& PDF::operator<<(ostream &os, const Document::Page &page) {
	return os << Document().readPage(page);
}
ostream& PDF::operator<<(ostream &os, const Document &doc) {
	return os << doc.readPDF();
}
