#include "headers/subscription.h"

#include <vector>
#include <iostream>

void bill(std::vector<int> &amount, int tot) {
    amount.push_back(tot);
}

std::vector<Car> rentedCars(std::vector<Car> &cars, std::vector<Car> &rentedCar, int choice) {
    Car obj;
    obj.brand = cars[choice - 1].brand;
    obj.model = cars[choice - 1].model;
    obj.registrationNumber = cars[choice - 1].registrationNumber;
    rentedCar.push_back(obj);
}

void displayCars(const std::vector<Car> &cars) {
    std::cout << "List of Cars:" << std::endl;
    int i = 1;

    for (const auto &car: cars) {
        std::cout << i << "\nBrand: " << car.brand << "\nModel: " << car.model << "\nRegistration Number: "
                  << car.registrationNumber << "\nPrice:" << car.price << std::endl;
        i++;
    }
};

void displayRentedCar(const std::vector<Car> &rentedCar) {
    std::cout << "List of Cars:" << std::endl;
    int i = 1;

    for (const auto &car: rentedCar) {
        std::cout << i << "\nBrand: " << car.brand << "\nModel: " << car.model << "\nRegistration Number: "
                  << car.registrationNumber << std::endl;
        i++;
    }
};

void displayBill(const std::vector<int> &amount) {
    std::cout << "List of Cars:" << std::endl;
    int i = 1;

    for (const auto &car: amount) {
        std::cout << i << "\nBill: " << car << std::endl;
        i++;
    }
};

void
extendRental(std::vector<Car> &cars, std::vector<int> &amount, const std::string &brandName, const std::string &num) {
    int flag;
    int day;
    std::string name, _name;
    do {
        int i = 0;
        for (const auto &car: cars) {
            if ((car.registrationNumber == num) && (car.brand == brandName)) {
                flag = 1;
                break;
            } else {
                flag = 0;
            }
            i++;
        }
        if (flag == 1) {
            std::cout << "How many days you want to extend the rental period?" << std::endl;
            std::cin >> day;
            std::cout << "You have to pay:" << day * cars[i].price << std::endl;
            std::cout << "Have you paid the bill?(yes/no)" << std::endl;
            std::cin >> name;
            do {
                if ((name == "yes") || (name == "y")) {
                    bill(amount, day * cars[i].price);
                    std::cout << "Thank You.Have a nice day!";
                    break;
                } else {
                    std::cout << "Please pay the bill." << std::endl;
                    std::cout << "Have you paid the bill?(y/n)" << std::endl;
                    std::cin >> name;
                }
            } while (name == "y");
        } else {
            std::cout << "Invalid credentials,you want to try again?(yes/no)" << std::endl;
            std::cin >> _name;
        }
    } while (_name == "yes");
}

void returnCar(std::vector<Car> &cars, std::vector<int> &amount, std::string brandName, std::string regNum) {
    int flag;
    std::string choice, _choice;
    do {
        std::cout << "Do you want to return?(yes/no/exit)";
        std::cin >> choice;
        if (choice == "yes") {
            for (const auto &car: cars) {
                if ((car.registrationNumber == regNum) && (car.brand == brandName)) {
                    flag = 1;
                    break;
                } else {
                    flag = 0;
                }
            }
            if (flag == 1) {
                std::cout << "Thank you for returning the car." << std::endl;
            } else {
                std::cout << "The given credentials are not valid to return the car,you want to try again?(yes/no)"
                          << std::endl;
                std::cin >> _choice;
                if (_choice == "no") {
                    std::cout << "Thank you for using our system." << std::endl;
                }
            }


        } else if (choice == "no") {
            extendRental(cars, amount, brandName, regNum);
        } else {
            std::cout << "Invalid input,you wanna try again?(yes/no)" << std::endl;
            std::cin >> _choice;
        }
    } while (_choice == "yes");
};

void
rentCar(std::vector<Car> &cars, std::vector<Car> &rentedCar, std::vector<int> &amount, std::string subscriberLevel) {
    int day, choice;
    std::string decide, ans, option;
    displayCars(cars);
    std::cout << "Enter your choice:" << std::endl;
    std::cin >> choice;
    std::cout << "How many days you want to rent the  car?";
    std::cin >> day;
    std::cout << "Are you sure you want to rent this car (yes/no/exit)" << std::endl;
    std::cin >> decide;
    switch (decide[0]) {
        case 'y':
        case 'Y':
            receipt(cars, choice);
            rentedCars(cars, rentedCar, choice);
            std::cout << "You have to pay:" << day * cars[choice - 1].price << std::endl;
            std::cout << "Have you paid the bill?(yes/no)" << std::endl;
            std::cin >> ans;
            if (ans == "yes") {
                bill(amount, day * cars[choice - 1].price);
                std::cout << "Thanks for using our system." << std::endl;
            } else {
                std::cout << "Please pay the bill." << std::endl;
            }
            break;
        case 'n':
        case 'N':
            displayCars(cars);
            std::cout << "Choose your option" << std::endl;
            std::cin >> choice;
            std::cout << "How many days you want to rent the  car?";
            std::cin >> day;
            receipt(cars, choice);
            rentedCars(cars, rentedCar, choice);
            std::cout << "You have to pay:" << day * cars[choice - 1].price << std::endl;
            std::cout << "Have you paid the bill?(yes/no)" << std::endl;
            std::cin >> ans;
            if (ans == "yes") {
                bill(amount, day * cars[choice - 1].price);
                std::cout << "Thanks for using our system." << std::endl;
            } else {
                std::cout << "Please pay the bill." << std::endl;
            }
            break;
        default:
            std::cout << "\t\t Thank you for using our system" << std::endl;
            std::cout << "\t\t-----------------------------" << std::endl;
            break;
    }


    std::cout << "Do you want to rent another car:(yes/no)";
    std::cin >> option;
    if (option == "yes") {
        switch (subscriberLevel[0]) {
            case 'S':
                std::cout << "Please upgrade your subscription to gold or platinum to rent another car." << std::endl;
                break;
            case 'G':
                std::cout << "You can rent one more car. Do you want to? (yes/no)" << std::endl;
                std::cin >> ans;
                if (ans == "yes") {
                    rentCar(cars, rentedCar, amount, subscriberLevel);
                } else {
                    std::cout << "Thank you for renting the car." << std::endl;
                }
                break;
            case 'P':
                std::cout << "You can rent two more cars. Do you want to? (yes/no)" << std::endl;
                std::cin >> ans;
                if (ans == "yes") {
                    rentCar(cars, rentedCar, amount, subscriberLevel);
                } else {
                    std::cout << "Thank you for renting the car." << std::endl;
                }
                break;
            default:
                std::cerr << "Invalid subscriber level." << std::endl;
                break;
        }
    }
}

void receipt(std::vector<Car> &cars, int choice) {
    std::cout << "\t\t Car rented Succesfully" << std::endl;
    std::cout << "\t\t-----------------------------" << std::endl;
    std::cout << "\t\t Brand:" << cars[choice - 1].brand << std::endl;
    std::cout << "\t\t Model:" << cars[choice - 1].model << std::endl;
    std::cout << "\t\t Registration No:" << cars[choice - 1].registrationNumber << std::endl;
    std::cout << "\t\t Price:" << cars[choice - 1].price << std::endl;
    std::cout << "\t\t-----------------------------" << std::endl;
    std::cout << "\t\t Thank You for choosing our sytsem" << std::endl;
    std::cout << "\t\t-----------------------------" << std::endl;
}