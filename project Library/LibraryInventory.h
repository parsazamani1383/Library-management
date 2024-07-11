#ifndef LIBRARYINVENTORY_H
#define LIBRARYINVENTORY_H

#include "Book.h"
#include <unordered_map>
#include <string>
#include <iostream>

class LibraryInventory {
private:
    std::unordered_map<Book*, int> books;

public:
    void addBook(Book &book, int quantity) {
        books[&book] += quantity;
    }

    void removeBook(Book &book, int quantity) {
        if (books[&book] > quantity) {
            books[&book] -= quantity;
        } else {
            books.erase(&book);
        }
    }

    void displayInventory() const {
        std::cout << "Library Inventory:" << std::endl;
        for (const auto &pair : books) {
            std::cout << "Book: " << pair.first->getTitle() << ", Quantity: " << pair.second << std::endl;
        }
    }
};

#endif // LIBRARYINVENTORY_H
