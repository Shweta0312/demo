#include <iostream>
#include <vector>
#include <string>
using namespace std;

void displayCars(const vector<Car>& cars) {
    cout << "List of Cars:" << endl;
    for (const auto& car : cars) {
        cout << "Brand: " << car.brand << ", Model: " << car.model << ", Registration Number: " << car.registrationNumber << endl;
    }
}

void displayRentedCars(const vector<Car>& RentedCars){
    cout << "List of Rented Cars:" << endl;
    for (const auto& car : RentedCars) {
        cout << "Brand: " << car.brand << ", Model: " << car.model << ", Registration Number: " << car.registrationNumber << endl;
    }
}

void displaySubscribers(const vector<Subscriber> subscribers){
    cout << "List of Subscribers:" << endl;
    for (const auto& Subscriber: subscribers) {
        cout << "Name " <<Subscriber::getName() << ", Subscription level    : " << Subscriber::getLevel() << endl;
    }
}

void displayRevenue(const vector<Car>& amount    ){
    int sum_total=0;
    cout << "The total revenue" << endl;
    for (const auto& car : RentedCars) {
       sum_total+=car.revenue;
    }
    cout<<sum_total<<endl;
}

