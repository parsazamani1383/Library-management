cmake_minimum_required(VERSION 3.28)
project(untitled6)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled6 main.cpp
        Book.cpp
        Book.h
        Member.cpp
        Member.h
        Library.cpp
        Library.h
        Person.cpp
        Person.h
        Librarian.cpp
        Librarian.h
        LibraryInventory.cpp
        LibraryInventory.h
        Transaction.cpp
        Transaction.h
        Screen.cpp
        Screen.h)
