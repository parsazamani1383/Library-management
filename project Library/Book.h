#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool is_available;

public:
    Book(const std::string &title, const std::string &author, const std::string &isbn)
            : title(title), author(author), isbn(isbn), is_available(true) {}

    void displayInfo() const {
        std::cout << "Title: " << title << ", Author: " << author
                  << ", ISBN: " << isbn << ", Available: " << (is_available ? "Yes" : "No") << std::endl;
    }

    void changeStatus() {
        is_available = !is_available;
    }

    bool isAvailable() const {
        return is_available;
    }

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    std::string getIsbn() const {
        return isbn;
    }
};

#endif // BOOK_H
