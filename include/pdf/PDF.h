#ifndef FILE_H
#define FILE_H

#include <filesystem> // path
#include <iostream> // ostream
#include <memory> // unique_ptr
#include <poppler/cpp/poppler-document.h> // poppler::document
#include <poppler/cpp/poppler-page.h> // poppler::page
#include <string>
#include <vector>

namespace PDF {

class Document {
  private:
	// private members
	std::filesystem::path p;
	std::unique_ptr<poppler::document> doc;
  public:
	// ctors, copy constructor, assignment operator, & dtor
	Document() = default;
	Document(const std::string &filePath);
	Document(const char *&filePath);
	Document(const Document&) = delete;
	Document & operator=(const Document&) = delete;
	~Document() = default;

	// public members
	int pageCount;

	// working with page objects
	using Page = poppler::page; // typedef poppler::page Page;
	std::unique_ptr<Page> getPage(const int i) const;
	std::string readPage(const Page &page) const;

	// working with indexes
	std::string readPage(const int i) const;

	// read an entire PDF
	std::string readPDF() const;
};

// example useful operators
std::ostream& operator<<(std::ostream &os, const Document::Page &page);
std::ostream& operator<<(std::ostream &os, const Document &doc);

}

#endif
