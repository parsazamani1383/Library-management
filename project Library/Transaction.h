#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Member.h"
#include "Book.h"
#include <string>
#include <iostream>

class Transaction {
private:
    Member *member;
    Book *book;
    std::string transaction_type;
    std::string transaction_date;

public:
    Transaction(Member *member, Book *book, const std::string &transaction_type, const std::string &transaction_date)
            : member(member), book(book), transaction_type(transaction_type), transaction_date(transaction_date) {}

    void displayInfo() const {
        std::cout << "Transaction - Member: " << member->getName() << ", Book: " << book->getTitle()
                  << ", Type: " << transaction_type << ", Date: " << transaction_date << std::endl;
    }
};

#endif // TRANSACTION_H
