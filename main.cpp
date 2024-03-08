#include <iostream>
#include <vector>
#include "headers/car.h"
#include "headers/functions.h"


int main() {
    std::cout << "----------------------" << std::endl;
    std::cout << "Company Name : RapidRide Rentals: " << std::endl;
    std::cout << "----------------------" << std::endl;
    std::vector<Car> cars;
    int choice;

    while (true) {
        std::cout << "Main Menu:\n";
        std::cout << "1. Manage Car\n";
        std::cout << "2. Manage Subscriber\n";
        std::cout << "3. Manage Subscription\n";
        std::cout << "4. Reports\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                manageCar(cars);
                break;
            case 2:
                manageSubscriber();
                break;
            case 3:
                manageSubscription();
                break;
            case 4:
                reports();
                break;
            case 5:
                std::cout << "Exiting program...\n";
                return 0;
            default:
                std::cout << "Invalid choice!\n";
        }
    }
}
