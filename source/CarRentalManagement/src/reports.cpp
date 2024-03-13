#include "headers/class_car_management.h"
#include "headers/subscribers.h"

#include <iostream>
#include <vector>
#include <string>

void displayCars(const std::vector<Car> &cars) {
    std::cout << "List of Cars:" << std::endl;
    for (const auto &car: cars) {
        std::cout << "Brand: " << car.brand << ", Model: " << car.model << ", Registration Number: "
                  << car.registrationNumber << std::endl;
    }
}

void displayRentedCars(const std::vector<Car> &RentedCars) {
    std::cout << "List of Rented Cars:" << std::endl;
    for (const auto &car: RentedCars) {
        std::cout << "Brand: " << car.brand << ", Model: " << car.model << ", Registration Number: "
                  << car.registrationNumber << std::endl;
    }
}

void displaySubscribers(const std::vector<Subscriber> &subscribers) {
    std::cout << "List of Subscribers:" << std::endl;
    for (const auto &subscriber: subscribers) {
        std::cout << "Name: " << Subscriber::getName() << ", Subscription level: "
                  << CarRentalSystem::levelToString(Subscriber::getLevel())
                  << std::endl;
    }
}


void displayRevenue(const std::vector<Car> &amount) {
    int sum_total = 0;
    std::cout << "The total revenue" << std::endl;
    // TODO: Handle RentedCars
    for (const auto &car: RentedCars) {
        sum_total += car.revenue;
    }
    std::cout << sum_total << std::endl;
}