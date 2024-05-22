#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool isAvailable;

public:
    Book(const std::string& title, const std::string& author, const std::string& isbn, bool isAvailable);

    void display() const;
    void toggleAvailability();
    void setAvailable(bool available);

    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    bool getIsAvailable() const;

    void setTitle(const std::string& newTitle);
    void setAuthor(const std::string& newAuthor);
    void setISBN(const std::string& newISBN);
};

#endif 



