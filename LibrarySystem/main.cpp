#include "Library.hpp"
#include <iostream>

void displayMenu() {
    std::cout << "\nLibrary Management System Menu:\n";
    std::cout << "1. Display All Books\n";
    std::cout << "2. Add a Book\n";
    std::cout << "3. Take Home a Book\n";
    std::cout << "4. Return a Book\n";
    std::cout << "5. Reserve a Book\n";
    std::cout << "6. Cancel a Reservation\n";
    std::cout << "7. Display Reserved Books\n";
    std::cout << "8. Exit\n\n";
    std::cout << "Enter your choice: ";
}

int getUserChoice() {
    int choice;
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

void performAction(int choice, Library& library) {
    std::string isbn, title, author;
    ActionResult result;
    switch (choice) {
        case 1:
            library.displayAllBooks();
            break;
        case 2:
            std::cout << "Enter title: ";
            getline(std::cin, title);
            std::cout << "Enter author: ";
            getline(std::cin, author);
            std::cout << "Enter ISBN: ";
            getline(std::cin, isbn);
            library.addBook(Book(title, author, isbn, true));
            break;
        case 3:
            std::cout << "Enter ISBN to check out: ";
            getline(std::cin, isbn);
            result = library.takeHomeBook(isbn);
            std::cout << result.message << "\n";
            break;
        case 4:
            std::cout << "Enter ISBN to return: ";
            getline(std::cin, isbn);
            result = library.checkInBook(isbn);
            std::cout << result.message << "\n";
            break;
        case 5:
            std::cout << "Enter ISBN to reserve: ";
            getline(std::cin, isbn);
            result = library.reserveBook(isbn);
            std::cout << result.message << "\n";
            break;
        case 6:
            std::cout << "Enter ISBN to cancel reservation: ";
            getline(std::cin, isbn);
            result = library.cancelReservation(isbn);
            std::cout << result.message << "\n";
            break;
        case 7:
            library.displayReservedBooks();
            break;
        case 8:
            std::cout << "Exiting...\n";
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
    }
}

int main() {
    Library myLibrary;
    bool running = true;
    while (running) {
        displayMenu();
        int choice = getUserChoice();
        if (choice == 8) {
            running = false;
        } else {
            performAction(choice, myLibrary);
        }
    }
    return 0;
}


