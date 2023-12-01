    // CarRentalProject.cpp
    #include "CarRentalProject.h"
    #include <iostream>
    #include <string>
    #include <iomanip>

    // Car class implementation
    Car::Car(const std::string& _model, double _price) : model(_model),price(_price), available(true) {}

    // User class implementation
    User::User(const std::string& _username, const std::string& _password, std::string& _bookedCarModel)
            : username(_username), password(_password), bookedCarModel(_bookedCarModel){}

    // User class implementation
    User::User()  {}

    // admin username and password implementation (no bookedCarModel)
    User CarRentalProject::admin("bilal", "41114123", (std::string &) "");

    // CarRentalProject class implementation
    CarRentalProject::CarRentalProject() {

        // Initializing the cars and their prices
        cars.emplace_back("Ford_Mustang", 70.0); // places the car and the price to the cars vector
        cars.emplace_back("Honda_Accord", 50.0);
        cars.emplace_back("Toyota_Corolla", 60.0);
        cars.emplace_back("Nissan_Maxima", 45.0);
        cars.emplace_back("Dodge_Charger", 75.0);
    }

    // the function that displays the customer menu
    void CarRentalProject::displayMenu() {
        std::cout << std::endl;
        std::cout << "=== FGCU CAR RENTAL CUSTOMER MENU ===\n";
        std::cout << "1. View Available Cars\n";
        std::cout << "2. Book a Car\n";
        std::cout << "3. Return a Car\n";
        std::cout << "4. Main Menu\n";
        std::cout << "5. Exit\n";
    }

    // the function that displays the admin menu
    void CarRentalProject::displayAdminMenu() {
        std::cout << std::endl;
        std::cout << "=== FGCU CAR RENTAL ADMIN MENU ===\n";
        std::cout << "1. Register a Customer\n";
        std::cout << "2. View Customer History\n";
        std::cout << "3. View Available Cars\n";
        std::cout << "4. Book a Car for a Customer\n";
        std::cout << "5. Return a Car for a Customer\n";
        std::cout << "6. Main Menu\n";
        std::cout << "7. Exit\n";
    }

    // the boolean function login() checks for the admin username & password, customer username & password
    bool CarRentalProject::login() {
        std::string username, password;

        std::cout << "Enter username: ";
        std::cin >> username; // get the username
        std::cout << "Enter password: ";
        std::cin >> password; // get the password

        // if the username and password matches with admins then admin login is successful and return true
        if (username == admin.username && password == admin.password) {
            currentUser = admin; // assign the currentUser as admin
            std::cout << "Admin login successful!\n";
            return true; // return true and stop the function
        }
        // if the username and password matches with new customer then customer login is successful and return true
        if (username == currentUser.username && password == currentUser.password){
            std::cout << "Customer Login successful!\n";
            return true; // return true and stop the function
        }

        // search for the existing user that rented a car before
        for (const auto& user : users) {
            if (user.username == username && user.password == password) {
                currentUser = user; // if the login successful then assign the customer as currentUser
                std::cout << "Customer Login successful!\n";

                // search for the existing users rented car
                for (const auto& car : cars) {
                    // if the not available car matches with the users bookedCarModel
                    if (car.model == currentUser.bookedCarModel && !car.available) {
                        currentUser.bookedCarModel = car.model; // assign the car.model as current users car

                        return true; // return true and stop the function
                    }
                }
                return true; // return true and stop the function
            }
        }
        std::cerr << std::endl << "Invalid username or password. Please try again." << std::endl; // error message
        return false; // return false and do not stop the function
    }

    // the function that register the users new username and password
    void CarRentalProject::registerUser() {
        std::string username, password;
        std::cout << "Enter a new username: ";
        std::cin >> username; // get the new username

        // check if the username is already taken with searching through the users vector
        for (const auto& user : users) {
            // if matches then print the error message
            if (user.username == username) {
                std::cerr << std::endl << "*Username already taken. Please choose a different one." << std::endl;
                return; // stop the function because error
            }
        }
        // check if the "new users that without a car" have the same username, if so print the error
        if (currentUser.username == username) {
            std::cerr << std::endl << "*Username already taken. Please choose a different one." << std::endl;
            return; // stop the function because error
        }

        std::cout << "Enter a new password: ";
        std::cin >> password; // get the new password

        setData(username,password); // call the setData() function to set new username and password

        std::cout << "Registration successful!\n"; // print the successful message
    }

    // the function that sets the data of new users username and the password
    void CarRentalProject::setData(const std::string& _username, const std::string& _password){

        currentUser.username = _username; // set as currentUser username
        currentUser.password = _password; // set as currentUser password

    }

    // the function that views available cars
    void CarRentalProject::viewAvailableCars() const {
        std::cout << std::endl << "Available Cars:\n" << std::endl;
        // search through the cars vector
        for (const auto& car : cars) {
            if (car.available) {
                // if car available then print the car model and its price next to it
                std::cout << "- " << car.model << ":" << std::setw(3)  << "$" << car.price << " a day.\n";
            }
        }
    }

    // the function that views the customer history and the customers booked car
    void CarRentalProject::viewCustomers() const {
        std::cout << "Available Customers:\n";

        // search through the users vector
        for (const auto& user : users) {
            if (!currentUser.bookedCarModel.empty()) {
                // if there is a bookedCard (if vector is not empty) then print the username and the booked car
                std::cout << "-User: " << user.username << " Rented Car: " << user.bookedCarModel << std::endl;
            }
        }
    }

    // the boolean function that checks if the card number is true or not
    bool CarRentalProject::cardPayment() {
        std::string cardNumber; // define the cardNumber

        while (true){ // loop until it's false
            std::cout << "***Card Payment***" << std::endl;
            std::cout << "Please enter the card number (11 digits): " << std::endl;
            std::cin >> cardNumber; // get the cardNumber

            if (cardNumber.length() == 11) { // if the card numbers length 11 then stop the loop
                return false; // return false to stop the loop
            }
            else {
                // print the error message if cardNumber not 11 digits
                std::cerr  << "*Invalid card number. Please enter 11 digits Card Number!" << std::endl;
            }
        }
    }


    // returnCar() is a function that makes the !available bookedCarModel to available
    void CarRentalProject::returnCar() {

        if (currentUser.bookedCarModel.empty()) {  // if there is none bookedCarModel then print the error
            std::cerr << std::endl << "You haven't booked any car.\n";
            return; // return and stop the function
        }

        // search for the booked car
        for (auto& car : cars) {
            if (car.model == currentUser.bookedCarModel && !car.available) {
                // if the car is not available then assign as car.model
                car.available = true; // booked car is available again

                // reset user's booked car
                currentUser.bookedCarModel.clear();
                std::cout << "Thank you for returning the car " << currentUser.username << std::endl;

                return; // return and stop the function
            }
        }

    }


    // bookCar() is a function that allows user to book a car and places users information to users vector
    void CarRentalProject::bookCar() {

            viewAvailableCars(); // call the viewAvailable() function to view models and prices
            std::string selectedCar; // selectedCar variable
            double total, day; // total price and day variables
            std::string insurance, toll; // insurance and toll variables
            std::cout << "Enter the model of the car you want to book: " << std::endl;
            std::cin >> selectedCar; // get the selectedCar

            // search through to cars vector to find the selectedCar
            for (auto& car : cars) {
                // if car is available then print the model and the price
                if (car.model == selectedCar && car.available) {
                    std::cout << "Car model: " << car.model << std::endl;
                    std::cout << "Daily car rental price: $" << car.price << std::endl;
                    std::cout << "Do you want to book the car?\n";
                    std::cout << "1. Yes\n";
                    std::cout << "2. No\n";
                    int book;
                    std::cin >> book; // get the booking selection 1/2

                    switch (book){ // switch case statement for the book
                        case 1:
                            std::cout << "How many days would you like to rent? " << std::endl;
                            std::cin >> day; // get day variable
                            std::cout << "Would you like to have an insurance? If so 10$ daily. (yes/no) " << std::endl;
                            std::cin >> insurance; // get insurance variable yes/no
                            std::cout << "Would you like to add toll? If so 5$. (yes/no) " << std::endl;
                            std::cin >> toll; // get toll variable yes/no

                            total = car.price * day; // calculate the total price

                            if (insurance == "yes" || insurance == "y") {
                                total += (10 * day); // add the insurance daily price to total
                            }
                            if (toll == "yes" || toll == "y") {
                                total += 5; // add the toll price to total
                            }

                            currentUser.bill = total; // assign the total as currenUser bill
                            currentUser.bookedCarModel = car.model; // assign the car.model as currentUser car
                            // place all the currentUser data to users vector
                            users.emplace_back(currentUser.username, currentUser.password, currentUser.bookedCarModel);
                            car.available = false; // make the car not available

                            cardPayment(); // call the cardPayment() function to check the card payment

                            std::cout << std::endl;
                            std::cout << "\nBooking details:" << std::endl;
                            std::cout << "* Renter Name: " << currentUser.username << std::endl; // print the username
                            std::cout << "* Booked Car model: " << currentUser.bookedCarModel << std::endl; // print the car
                            std::cout << "* Booked Car price: $" << currentUser.bill << std::endl; // print the total bill

                            std::cout << "Booking successful! Enjoy your ride." << std::endl;
                            return; // return to stop the function

                        case 2: // if book is "No" then ask for a different car to book
                            bookCar();
                            break;
                        default:
                            std::cerr << std::endl << "Invalid choice. Please try again.\n";
                            bookCar(); // if choice is invalid then loop again

                    }
                }
            }
            // if selectedCar is invalid then print the error
            std::cerr << std::endl << "Invalid car model or the car is not available.\n";
    }

    // the function that runs all the code and displays the menus
    void CarRentalProject::run() {
        int choiceAdmin, choiceCustom, userChoice, choiceCustom2;
        std::cout << std::endl;
        std::cout << "=== WELCOME TO FGCU CAR RENTAL ===\n";
        std::cout << "1. Customer Menu\n";
        std::cout << "2. Administrator Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> userChoice; // get the user choice

        switch (userChoice) { // switch case statement for the userChoice
            case 1:
                do {
                    std::cout << std::endl;
                    std::cout << "=== FGCU CAR RENTAL CUSTOMER MENU ===\n";
                    std::cout << "1. Login\n";
                    std::cout << "2. Register\n";
                    std::cout << "3. Main menu\n";
                    std::cout << "4. Exit\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> choiceCustom; // get the customer choice

                    switch (choiceCustom){ // switch case statement for the customer choice

                        case 1:
                            if (login()){ // if login is successful then display the menu for the customer
                                do {
                                    displayMenu();
                                    std::cout << "Enter your choice: ";
                                    std::cin >> choiceCustom2; // get the second customer choice
                                    switch (choiceCustom2) { // switch case statement for the second customer choice
                                        case 1:
                                            viewAvailableCars(); // call viewAvailableCars() function
                                            break;
                                        case 2:
                                            bookCar(); // call bookCar() function
                                            break;
                                        case 3:
                                            returnCar();  // call returnCar() function
                                            break;
                                        case 4:
                                            run(); // call run() function to go back to main menu
                                            break;
                                        case 5:
                                            // exit the system stop the code
                                            std::cout << "Exiting the Car Rental System. Goodbye!\n";
                                            break;
                                        default:
                                            // print the error message if selection invalid
                                            std::cerr << std::endl << "*Invalid choice. Please try again.\n";
                                    }
                                }while (choiceCustom2 != 5); // if second choice is 5 then stop the code
                            }
                            break;
                        case 2:
                            registerUser(); // call the registerUser() function
                            break;
                        case 3:
                            run(); // call the run() function to go back to main menu
                            break;
                        case 4:
                            std::cout << "Exiting the Car Rental System. Goodbye!\n";
                            break;
                        default:
                            // print the error message if selection invalid
                            std::cerr << std::endl << "*Enter a valid choice! " << std::endl;
                            break;
                    }

                } while (choiceCustom != 4); // if first choice is 4 then stop the code
                break;
            case 2:
                if (login()) {
                    do {
                        displayAdminMenu();
                        std::cout << "Enter your choice: ";
                        std::cin >> choiceAdmin; // get the admin choice

                        switch (choiceAdmin) { // switch case statement for the admin choice
                            case 1:
                                registerUser(); // call the registerUser() function
                                break;
                            case 2:
                                viewCustomers(); // call viewCustomers() function
                                break;
                            case 3:
                                viewAvailableCars(); // call viewAvailableCars() function
                                break;
                            case 4:
                                if (login()){ // if login is successful then book a car for the customer
                                    bookCar(); // call bookCar() function
                                }
                                else{
                                    // print an error message if the login() is not successful
                                    std::cerr << "*Please enter a existing customer name!" << std::endl;
                                }
                                break;
                            case 5:
                                if (login()){ // if login is successful then return a car for the customer
                                    returnCar(); // call returnCar() function
                                }
                                else{
                                    // print an error message if the login() is not successful
                                    std::cerr << "*Please enter a existing customer name!" << std::endl;
                                }
                                break;
                            case 6:
                                run(); // call the run() function to go back to main menu
                                break;
                            case 7:
                                // stop the code
                                std::cout << "Exiting the Car Rental System. Goodbye!\n";
                                break;
                            default:
                                // print the error message if selection invalid
                                std::cerr << std::endl << "*Invalid choice. Please try again.\n";
                        }
                    } while (choiceAdmin != 7); // if admin choice is 7 then stop the code
                }
                else{
                    // call the run() function to go back to main menu
                    run();
                }
                break;
            default:
                // print the error message if selection invalid
                std::cerr << std::endl << "*Enter a valid choice! " << std::endl;
                run(); // call the run() function to go back to main menu
                break;
        }
    }
