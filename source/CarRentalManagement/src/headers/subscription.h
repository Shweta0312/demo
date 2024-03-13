#ifndef SUBSCRIPTION_H
#define SUBSCRIPTION_H

#include <vector>
#include "class_car_management.h"

void bill(std::vector<int> &amount, int tot);

std::vector<Car> rentedCars(std::vector<Car> &cars, std::vector<Car> &rentedCar, int choice);

void displayCars(const std::vector<Car> &cars);

void displayRentedCar(const std::vector<Car> &rentedCar);

void displayBill(const std::vector<int> &amount);

void
extendRental(std::vector<Car> &cars, std::vector<int> &amount, const std::string &brandName, const std::string &num);

void returnCar(std::vector<Car> &cars, std::vector<int> &amount, const std::string& brandName, const std::string& regNum);

void
rentCar(std::vector<Car> &cars, std::vector<Car> &rentedCar, std::vector<int> &amount, std::string subscriberLevel);

void receipt(std::vector<Car> &cars, int choice);

#endif
