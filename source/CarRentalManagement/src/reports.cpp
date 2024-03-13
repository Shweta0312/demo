#include "headers/class_car_management.h"
#include "headers/subscribers.h"

#include <iostream>
#include <vector>
#include <string>

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
        std::string name = subscriber.getName();  // Call getName() on the subscriber object
        SubscriptionLevel level = subscriber.getLevel();  // Call getLevel() on the subscriber object
        std::cout << "Name: " << name << ", Subscription level: "
                  << CarRentalSystem::levelToString(level) << std::endl; // Call levelToString() statically
    }
}


void displayRevenue(const std::vector<Car> &amount) {
    int sum_total = 0;
    std::cout << "The total revenue" << std::endl;
    // TODO: Handle RentedCars
//    for (const auto &car: RentedCars) {
//        sum_total += car.revenue;
//    }
    std::cout << sum_total << std::endl;
}