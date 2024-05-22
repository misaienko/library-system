#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.hpp"
#include <vector>
#include <string>

enum class LibraryActionStatus {
    Success,
    Failure,
    BookNotFound,
    AlreadyCheckedOut,
    AlreadyCheckedIn,
    Reserved,
    NotReserved,
    NoReservations,
    NotReservedFirst
};

struct ActionResult {
    LibraryActionStatus status;
    std::string message;
};

class Library {
private:
    std::vector<Book> books;
    std::vector<Book> reservedBooks;

public:
    Library();
    void loadBooksFromJson();
    ActionResult takeHomeBook(const std::string& isbn);
    ActionResult checkInBook(const std::string& isbn);
    ActionResult reserveBook(const std::string& isbn);
    ActionResult cancelReservation(const std::string& isbn);
    void displayAllBooks();
    void displayReservedBooks();
    void addBook(const Book& book);
};

#endif 


