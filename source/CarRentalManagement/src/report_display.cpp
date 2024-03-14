#include <iostream>
#include <vector>
#include <string>
#include "SubscriptionManagement.h"
#include "subscribersmanagement.h"
#include "functions_CarManagement.h"
using namespace std;
extern vector<Subscriber> subscriber;
void display_Cars(const vector<Car> &cars) {
	cout << "List of Cars:" << endl;
	for (const auto &car : cars) {
		cout << "Brand: " << car.brand << ", Model: " << car.model
				<< ", Registration Number: " << car.registrationNumber << endl;
	}
}

void displayRentedCars(const vector<Car> &RentedCars) {
	cout << "List of Rented Cars:" << endl;
	for (const auto &car : RentedCars) {
		cout << "Brand: " << car.brand << ", Model: " << car.model
				<< ", Registration Number: " << car.registrationNumber << endl;
	}
}

void displaySubscribers(const vector<Subscriber> &subscribers) {

	cout << "List of Subscribers:" << endl;
	for (const auto &Subscriber : subscribers) {
		cout << "Name " << Subscriber.getName() << ", Subscription level    : "
				<< CarRentalSystem::levelToString(Subscriber.getLevel()) << endl;
	}
}

void displayRevenue(const vector<int> &amount) {
	int sum_total = 0;
	cout << "The total revenue" << endl;
	for (const auto &car: amount) {
		sum_total += car;
	}
	cout << sum_total << endl;
}

