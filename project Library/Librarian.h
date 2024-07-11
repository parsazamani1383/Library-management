#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Person.h"
#include "Library.h"

class Librarian : public Person {
public:
    Librarian(const std::string &name, int id) : Person(name, id) {}

    void addBook(Library &library, Book &book) {
        library.addBook(book);
        std::cout << "Book " << book.getTitle() << " added to the library by " << name << std::endl;
    }

    void removeBook(Library &library, Book &book) {
        library.removeBook(book);
        std::cout << "Book " << book.getTitle() << " removed from the library by " << name << std::endl;
    }

    void displayInfo() const override {
        std::cout << "Librarian Name: " << name << ", ID: " << id << std::endl;
    }
};

#endif // LIBRARIAN_H
