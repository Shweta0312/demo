#include "headers/functions.h"
#include <iostream>

void addCar(std::vector<Car> &cars) {
    Car newCar;
    std::cout << "Enter Brand: ";
    std::cin >> newCar.brand;
    std::cout << "Enter model: ";
    std::cin >> newCar.model;
    std::cout << "Enter registrationNumber: ";
    std::cin >> newCar.registrationNumber;
    std::cout<<"Enter Price :";
    std::cin>>newCar.price;

    cars.push_back(newCar);
    std::cout << "Car added successfully!" << std::endl;
}

void removeCar(std::vector<Car>& carList) {
    std::string registrationNumber;
    std::cout << "Enter registration number of the car to remove: ";
    std::cin >> registrationNumber;
    for (auto it = carList.begin(); it != carList.end(); ++it) {
        if (it->registrationNumber == registrationNumber) {
            carList.erase(it);
            std::cout << "Car removed from rental list." << std::endl;
            return;
        }
    }
    std::cout << "Car with registration number " << registrationNumber << " not found in rental list." << std::endl;
}

void manageCar(std::vector<Car>& cars) {
    char subChoice;
    std::cout << "Manage Car:\n";
    std::cout << "a) Add new car\n";
    std::cout << "b) Remove existing car\n";
    std::cout << "c) Return to main menu\n";
    std::cout << "Enter your choice: ";
    std::cin >> subChoice;

    switch (subChoice) {
        case 'a':
            std::cout << "Adding new car...\n";
            addCar(cars);
            break;
        case 'b':
            std::cout << "Removing existing car...\n";
            removeCar(cars);
            break;
        case 'c':
            std::cout << "Returning to main menu...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
    }
}

void manageSubscriber() {
    char subChoice;
    std::cout << "Manage Subscriber:\n";
    std::cout << "a) Add new subscriber:\n";
    std::cout << "b) Remove existing subscriber:\n";
    std::cout << "c) Promote Subscription:\n";
    std::cout << "d) Returning to main menu:\n";
    std::cout << "Enter your choice: ";
    std::cin >> subChoice;

    switch (subChoice) {
        case 'a':
            std::cout << "Adding new subscriber...\n";
            break;
        case 'b':
            std::cout << "Removing new Subscriber...\n";
            break;
        case 'c':
            std::cout << "Promote Subscription...\n";
            break;
        case 'd':
            std::cout << "Returning to main menu...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
    }

}




void manageSubscription() {
    char subChoice;
    std::cout << "Manage subscription:\n";
    std::cout << "a) Rent a car:\n";
    std::cout << "b) Return a car:\n";
    std::cout << "c) Extend the Rental period:\n";
    std::cout << "Enter your choice: ";
    std::cin >> subChoice;
    switch (subChoice) {
        case 'a':
            std::cout << "Rent Car Successfully...\n";
            break;
        case 'b':
            std::cout << "Returned car Successfully...\n";
            break;
        case 'c':
            std::cout << "Extended the Rental Period...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
    }







}

void reports() {
    char subChoice;
    std::cout << "Reports:\n";
    std::cout << "a) See available car list:\n";
    std::cout << "b) See cars under rental now:\n";
    std::cout << "c) See the subscribers list:\n";
    std::cout << "d) See current subscription book:\n";
    std::cout << "e) See the Revenue so far:\n";
    //std::cout << "Enter your choice: ";
    // std::cout << "d) See current subscription book:\n";
    std::cout << "Enter your choice: ";
    std::cin >> subChoice;
    switch (subChoice) {
        case 'a':
            std::cout << "This is the available car list...\n";
            break;
        case 'b':
            std::cout << "This is the cars list under rental ...\n";
            break;
        case 'c':
            std::cout << "This is the subscribers list...\n";
            break;
        case 'd':
            std::cout << "This is the current subscription book...\n";
            break;
        case 'e':
            std::cout<<"This is the Revenue so far...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
    }




}