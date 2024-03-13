#include "headers/core_functions.h"
#include "headers/class_car_management.h"
#include <iostream>

void addCar(std::vector<Car> &cars) {
    Car newCar;
    std::cout << "Enter Brand: ";
    std::cin >> newCar.brand;
    std::cout << "Enter model: ";
    std::cin >> newCar.model;
    std::cout << "Enter registrationNumber: ";
    std::cin >> newCar.registrationNumber;
    std::cout << "Enter Price :";
    std::cin >> newCar.price;

    cars.push_back(newCar);
    std::cout << "Car added successfully!" << std::endl;
}

void removeCar(std::vector<Car> &carList) {
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