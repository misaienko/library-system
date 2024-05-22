#include "Book.hpp"
#include <iostream>

Book::Book(const std::string& title, const std::string& author, const std::string& isbn, bool isAvailable)
    : title(title), author(author), isbn(isbn), isAvailable(isAvailable) {}

void Book::toggleAvailability() {
    isAvailable = !isAvailable;
}

void Book::display() const {
    std::cout << "Title: " << title << '\n'
              << "Author: " << author << '\n'
              << "ISBN: " << isbn << '\n'
              << "Available: " << (isAvailable ? "Yes" : "No") << '\n';
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return isbn;
}

bool Book::getIsAvailable() const {
    return isAvailable;
}

void Book::setAvailable(bool available) {
    isAvailable = available;
}

void Book::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void Book::setAuthor(const std::string& newAuthor) {
    author = newAuthor;
}

void Book::setISBN(const std::string& newISBN) {
    isbn = newISBN;
}

