#include "Library.hpp"
#include <fstream>
#include <iostream>
#include "json.hpp"

Library::Library() {
    loadBooksFromJson();
}

void Library::loadBooksFromJson() {
    std::ifstream i("booksData.json");
    if (!i.is_open()) {
        std::cerr << "Error opening booksData.json file." << std::endl;
        return;
    }
    nlohmann::json j = nlohmann::json::parse(i);
    for (const auto& item : j) {
        books.emplace_back(item["title"], item["author"], item["isbn"], item["isAvailable"]);
    }
}

ActionResult Library::takeHomeBook(const std::string& isbn) {
    std::cout << "Checking reserved books list:\n";
    for (const auto& book : reservedBooks) {
        std::cout << "Reserved book ISBN: " << book.getISBN() << " Available: " << (book.getIsAvailable() ? "Yes" : "No") << "\n";
    }

    auto it = std::find_if(reservedBooks.begin(), reservedBooks.end(),
                           [&isbn](const Book& book) { return book.getISBN() == isbn && !book.getIsAvailable(); });
    if (it != reservedBooks.end()) {
        return {LibraryActionStatus::Success, "You can pick up the book from the library during the working hours."};
    }
    return {LibraryActionStatus::NotReservedFirst, "You must reserve a book first."};
}

ActionResult Library::checkInBook(const std::string& isbn) {
    auto it = std::find_if(books.begin(), books.end(),
                           [&isbn](const Book& book) { return book.getISBN() == isbn && !book.getIsAvailable(); });
    if (it != books.end()) {
        // Before marking as available
        std::cout << "Checking in book with ISBN: " << isbn << ". Currently not available: " << it->getIsAvailable() << std::endl;

        it->setAvailable(true);
        std::cout << "Book checked in and is now available: " << it->getIsAvailable() << std::endl;
        return {LibraryActionStatus::Success, "Book returned successfully. Available for reservation again."};
    }
    std::cout << "Failed to find book to check in with ISBN: " << isbn << std::endl;
    return {LibraryActionStatus::BookNotFound, "Book not found or was not checked out."};
}

ActionResult Library::reserveBook(const std::string& isbn) {
    auto it = std::find_if(books.begin(), books.end(),
                           [&isbn](const Book& book) { return book.getISBN() == isbn && book.getIsAvailable(); });
    if (it != books.end()) {
        it->setAvailable(false);
        reservedBooks.push_back(*it);
        return {LibraryActionStatus::Reserved, "Book reserved successfully."};
    }
    return {LibraryActionStatus::BookNotFound, "Book not found or already reserved."};
}

ActionResult Library::cancelReservation(const std::string& isbn) {
    auto it = std::find_if(reservedBooks.begin(), reservedBooks.end(),
                           [&isbn](const Book& book) { return book.getISBN() == isbn; });
    if (it != reservedBooks.end()) {
        it->setAvailable(true);
        books.push_back(*it);
        reservedBooks.erase(it); 
        return {LibraryActionStatus::NotReserved, "Reservation cancelled successfully. Book is available again."};
    }
    return {LibraryActionStatus::BookNotFound, "Reserved book not found."};
}

void Library::displayAllBooks() {
    if (books.empty()) {
        std::cout << "No books in the library.\n";
    } else {
        for (const auto& book : books) {
            book.display();
        }
    }
}

void Library::displayReservedBooks() {
    if (reservedBooks.empty()) {
        std::cout << "You didn't make any reservations yet.\n";
    } else {
        for (const auto& book : reservedBooks) {
            book.display();
        }
    }
}

void Library::addBook(const Book& book) {
    books.push_back(book);
}


