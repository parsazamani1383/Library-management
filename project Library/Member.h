#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"
#include "Book.h"
#include <vector>
#include <algorithm>

class Member : public Person {
private:
    std::vector<Book*> borrowed_books;

public:
    Member(const std::string &name, int id) : Person(name, id) {}

    void borrowBook(Book &book) {
        if (book.isAvailable()) {
            book.changeStatus();
            borrowed_books.push_back(&book);
            std::cout << name << " borrowed " << book.getTitle() << std::endl;
        } else {
            std::cout << book.getTitle() << " is not available" << std::endl;
        }
    }

    void returnBook(Book &book) {
        auto it = std::find(borrowed_books.begin(), borrowed_books.end(), &book);
        if (it != borrowed_books.end()) {
            book.changeStatus();
            borrowed_books.erase(it);
            std::cout << name << " returned " << book.getTitle() << std::endl;
        } else {
            std::cout << name << " does not have " << book.getTitle() << std::endl;
        }
    }

    void displayInfo() const override {
        std::cout << "Member Name: " << name << ", ID: " << id << ", Borrowed Books: ";
        for (const auto &book : borrowed_books) {
            std::cout << book->getTitle() << " ";
        }
        std::cout << std::endl;
    }
};

#endif // MEMBER_H
