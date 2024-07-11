#include "Screen.h"
#include <iostream>

int main() {
    Librarian librarian("John", 100);
    Screen screen(librarian);
    screen.mainMenu();
    return 0;
}
