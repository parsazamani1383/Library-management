#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
protected:
    std::string name;
    int id;

public:
    Person(const std::string &name, int id) : name(name), id(id) {}

    std::string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", ID: " << id << std::endl;
    }
};

#endif // PERSON_H
