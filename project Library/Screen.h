
#include "Library.h"
#include "Librarian.h"
#include "Member.h"
#include <iostream>
#include <string>

class Screen {
private:
    Library library;
    Librarian librarian;
    Member *currentMember = nullptr;

public:
    Screen(const Librarian &lib) : librarian(lib) {}

    void mainMenu() {
        int choice;
        do {
            std::cout << "Main Menu:\n";
            std::cout << "1. Librarian Login\n";
            std::cout << "2. Member Login\n";
            std::cout << "3. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    librarianMenu();
                    break;
                case 2:
                    memberLogin();
                    break;
                case 3:
                    std::cout << "Exiting the program. Goodbye!\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 3);
    }

private:
    void librarianMenu() {
        int choice;
        do {
            std::cout << "\nLibrarian Menu:\n";
            std::cout << "1. Add Book\n";
            std::cout << "2. Remove Book\n";
            std::cout << "3. View All Books\n";
            std::cout << "4. View All Members\n";
            std::cout << "5. Logout\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    addBook();
                    break;
                case 2:
                    removeBook();
                    break;
                case 3:
                    viewAllBooks();
                    break;
                case 4:
                    viewAllMembers();
                    break;
                case 5:
                    std::cout << "Logging out...\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 5);
    }

    void memberLogin() {
        std::string name;
        int id;
        std::cout << "Enter member ID: ";
        std::cin >> id;
        currentMember = library.searchMember(id);
        if (currentMember) {
            memberMenu();
        } else {
            std::cout << "Member not found.\n";
        }
    }

    void memberMenu() {
        int choice;
        do {
            std::cout << "\nMember Menu:\n";
            std::cout << "1. Borrow Book\n";
            std::cout << "2. Return Book\n";
            std::cout << "3. View Borrowed Books\n";
            std::cout << "4. Logout\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    borrowBook();
                    break;
                case 2:
                    returnBook();
                    break;
                case 3:
                    currentMember->displayInfo();
                    break;
                case 4:
                    std::cout << "Logging out...\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 4);
    }

    void addBook() {
        std::string title, author, isbn;
        std::cin.ignore();
        std::cout << "Enter book title: ";
        std::getline(std::cin, title);
        std::cout << "Enter book author: ";
        std::getline(std::cin, author);
        std::cout << "Enter book ISBN: ";
        std::getline(std::cin, isbn);
        Book *newBook = new Book(title, author, isbn);
        librarian.addBook(library, *newBook);
    }

    void removeBook() {
        std::string title;
        std::cin.ignore();
        std::cout << "Enter book title to remove: ";
        std::getline(std::cin, title);
        Book *book = library.searchBook(title);
        if (book) {
            librarian.removeBook(library, *book);
        } else {
            std::cout << "Book not found.\n";
        }
    }

    void viewAllBooks() {
        for (const auto &book : library.getBooks()) {
            book->displayInfo();
        }
    }

    void viewAllMembers() {
        for (const auto &member : library.getMembers()) {
            member->displayInfo();
        }
    }

    void borrowBook() {
        std::string title;
        std::cin.ignore();
        std::cout << "Enter book title to borrow: ";
        std::getline(std::cin, title);
        Book *book = library.searchBook(title);
        if (book) {
            currentMember->borrowBook(*book);
        } else {
            std::cout << "Book not found.\n";
        }
    }

    void returnBook() {
        std::string title;
        std::cin.ignore();
        std::cout << "Enter book title to return: ";
        std::getline(std::cin, title);
        Book *book = library.searchBook(title);
        if (book) {
            currentMember->returnBook(*book);
        } else {
            std::cout << "Book not found.\n";
        }
    }
};
