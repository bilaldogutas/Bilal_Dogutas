// CarRentalProject.h
#ifndef CAR_RENTAL_PROJECT_H
#define CAR_RENTAL_PROJECT_H

#include <iostream>
#include <string>
#include <vector>

class Car { // Car class
public:
    Car(const std::string &_model, double _price); // Car class constructor

    std::string model; // car model variable
    double price; // car price variable
    bool available; // car available variable
};

class User { // User class
public:
    User(const std::string& , const std::string& , std::string&); // User class constructor
    User(); // User class constructor

    std::string username; // user username variable
    std::string password; // user password variable
    double bill; // user bill variable
    std::string bookedCarModel; // user bookedCarModel variable
};

class CarRentalProject { // CarRentalProject class
public:
    CarRentalProject(); // CarRentalProject class constructor

    static User admin; // admin object
    User currentUser; // currentUser object

    void displayMenu(); // the function that displays the customer menu
    void displayAdminMenu(); // the function that displays the admin menu
    bool login(); // the boolean function login() checks for the admin username & password, customer username & password
    void registerUser(); // the function that register the users new username and password
    void setData(const std::string& , const std::string&); // the function that sets the data of new users username and the password
    void viewAvailableCars() const; // the function that views available cars
    void viewCustomers() const; // the function that views the customer history and the customers booked car
    bool cardPayment(); // the boolean function that checks if the card number is true or not
    void returnCar(); // returnCar() is a function that makes the !available bookedCarModel to available
    void bookCar(); // bookCar() is a function that allows user to book a car and places users information to users vector
    void run(); // the function that runs all the code and displays the menus


private:
    std::vector<User> users; // users vector
    std::vector<Car> cars; // cars vector

};

#endif // CAR_RENTAL_PROJECT_H
