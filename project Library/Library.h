#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

class Library {
private:
    std::vector<Book*> books;
    std::vector<Member*> members;

    const std::string books_file = "books.txt";
    const std::string members_file = "members.txt";

public:
    Library() {
        loadBooks();
        loadMembers();
    }

    ~Library() {
        saveBooks();
        saveMembers();
    }

    std::vector<Book*> getBooks() const {
        return books;
    }

    std::vector<Member*> getMembers() const {
        return members;
    }

    void addBook(Book &book) {
        books.push_back(&book);
    }

    void removeBook(Book &book) {
        auto it = std::find(books.begin(), books.end(), &book);
        if (it != books.end()) {
            books.erase(it);
        }
    }

    void addMember(Member &member) {
        members.push_back(&member);
        std::cout << "Member " << member.getName() << " added to the library" << std::endl;
    }

    void removeMember(Member &member) {
        auto it = std::find(members.begin(), members.end(), &member);
        if (it != members.end()) {
            members.erase(it);
        }
    }

    Book* searchBook(const std::string &title) {
        for (auto &book : books) {
            if (book->getTitle() == title) {
                return book;
            }
        }
        return nullptr;
    }

    Member* searchMember(int id) {
        for (auto &member : members) {
            if (member->getId() == id) {
                return member;
            }
        }
        return nullptr;
    }

    void saveBooks() {
        std::ofstream out(books_file);
        for (const auto &book : books) {
            out << book->getTitle() << "," << book->getAuthor() << "," << book->getIsbn() << "," << book->isAvailable() << std::endl;
        }
    }

    void loadBooks() {
        std::ifstream in(books_file);
        std::string line, title, author, isbn;
        bool is_available;
        while (std::getline(in, line)) {
            std::stringstream ss(line);
            std::getline(ss, title, ',');
            std::getline(ss, author, ',');
            std::getline(ss, isbn, ',');
            ss >> is_available;
            Book *book = new Book(title, author, isbn);
            if (!is_available) {
                book->changeStatus();
            }
            books.push_back(book);
        }
    }

    void saveMembers() {
        std::ofstream out(members_file);
        for (const auto &member : members) {
            out << member->getName() << "," << member->getId() << std::endl;
        }
    }

    void loadMembers() {
        std::ifstream in(members_file);
        std::string line, name;
        int id;
        while (std::getline(in, line)) {
            std::stringstream ss(line);
            std::getline(ss, name, ',');
            ss >> id;
            Member *member = new Member(name, id);
            members.push_back(member);
        }
    }
};

#endif // LIBRARY_H
