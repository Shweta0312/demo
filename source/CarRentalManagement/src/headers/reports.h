#ifndef REPORTS_H
#define REPORTS_H

#include "headers/class_car_management.h"
#include "headers/subscribers.h"



void displayRentedCars(const std::vector<Car> &RentedCars);

void displaySubscribers(std::vector<Subscriber> subscribers);

void displayCurrentSubscription(const std::vector<Car> &RentedCars);

void displayRevenue(const std::vector<Car> &amount);

#endif
