#include <vector>
#include "Class_CarManagement.h"
#include "subscribersmanagement.h"

void display_Cars(const std::vector<Car>& cars);
void displayRentedCars(const std::vector<Car>& RentedCars);
void displaySubscribers(const std::vector<Subscriber> & subscribers);
void displayCurrentSubscription(const std::vector<Car>& RentedCars);
void displayRevenue(const std::vector<Car>& RentedCars);
