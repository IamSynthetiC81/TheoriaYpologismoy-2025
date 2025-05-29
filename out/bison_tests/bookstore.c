#include "lambdalib.h"
#include <stdbool.h>
struct Address {
char* street;
int number;
char* city;
void setAddress(char* s, int n, char* c) {
    street = s;
    number = n;
    city = c;
}
void printAddress() {
    write("Address: %s %d, %s\n",street,number,city);
}
};
struct Person {
char* firstName, lastName;
char* email;
int phone;
Address address;
void setPerson(char* fn, char* ln, char* email, int phone, Address addr) {
    firstName = fn;
    lastName = ln;
    email = email;
    phone = phone;
    address = addr;
}
void printPersonInfo() {
    write("%s %s, email: %s phone: %d\n",firstName,lastName,email,phone);
    /* ERROR */
}
};
struct Book {
char* title, isbn;
Person author;
int numOfCopies;
float price;
void setBook(char* t, Person a, int numOfCopies, float price) {
    title = t;
    author = a;
    numOfCopies = numOfCopies;
    price = price;
}
void printBook() {
    write("Title: %s\n",title);
    writeStr("Author:");
    /* ERROR */
    write("Price:%f\n",price);
    write("Number of available copies: %d\n",numOfCopies);
}
};
struct Order {
int orderNum;
Book book;
int quantity;
Address shippingAddress;
bool delivered;
void setOrder(int orNum, Book b, int q, Address sh, bool del) {
    orderNum = orNum;
    book = b;
    quantity = q;
    shippingAddress = sh;
    delivered = del;
}
void printOrder() {
    ;;}
};
struct Bookstore {
char* name;
Book listOfBooks[100];
int numOfBooks;
Order listOfOrders[100];
int numOfOrders;
void putOrder(Order o) {
    listOfOrders/* ERROR */
}
void addBook(Book b) {
    listOfBooks/* ERROR */
}
void printBookStoreBooks() {
    for (int i = 0; i < numOfBooks; i++) {
    	/* ERROR */
    
    }
}
float calculateTotalOrdersIncome() {
    float total;
    total = 0;
    for (int i = 0; i < numOfOrders; i++) {
    	/* ERROR */
    /* ERROR */
    
    }
    return total;
}
};
int orderId;
Address createAddress(char* s, int n, char* c) {
    Address a;
    /* ERROR */
    return a;
}
Person createPerson(char* fn, char* ln, char* email, int phone, Address addr) {
    Person p;
    /* ERROR */
    return p;
}
Book createBook(char* t, Person a, int numOfCopies, float price) {
    Book b;
    /* ERROR */
    return b;
}
Order createOrder(int orNum, Book b, int q, Address sh, bool del) {
    Order ord;
    /* ERROR */
    return ord;
}
Bookstore createBookstore(char* n) {
    Bookstore bs;
    /* ERROR */
    /* ERROR */
    /* ERROR */
    return bs;
}
int main() {
    orderId = 0;
    Address a, a1;
    a = createAddress("Stadiou",10,"Stadiou");
    Person author;
    author = createPerson("Christos","Papadimitriou","cpap@gmail.com",12345,a);
    Book b;
    b = createBook("Computation Theory",author,34.3,100);
    Bookstore bs;
    bs = createBookstore("Papasotiriou");
    /* ERROR */
    a = createAddress("Wall Street",10,"NY");
    author = createPerson("Dennis","Richie","richie@gmail.com",54321,a);
    b = createBook("C Programming",author,10.3,100);
    /* ERROR */
    /* ERROR */
    Order ord;
    ord = createOrder(orderId,b,2,a,false);
    /* ERROR */
    /* ERROR */
    /* ERROR */
};
