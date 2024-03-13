#include <iostream>

#include "headers/class_car_management.h"
#include "headers/core_functions.h"
#include "headers/manage_car_functions.h"
#include "headers/subscribers.h"
#include "headers/subscription.h"
#include "headers/reports.h"

void manageCar(std::vector<Car> &cars) {
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
        case 'a': {
            int level_choice;
            std::string name, id;
            SubscriptionLevel level;
            std::cout << "\nName: ";
            std::cin >> name;
            std::cout << "ID: ";
            std::cin >> id;
            std::cout << "Subscription Level: ";
            std::cout << "Choose subscription level:\n";
            std::cout << "1. Silver\n";
            std::cout << "2. Gold\n";
            std::cout << "3. Platinum\n";
            std::cout << "Enter your choice (1, 2, or 3): ";
            std::cin >> level_choice;
            switch (level_choice) {
                case 1:
                    level = SubscriptionLevel::Silver;
                case 2:
                    level = SubscriptionLevel::Gold;
                case 3:
                    level = SubscriptionLevel::Platinum;
                default:
                    std::cerr << "Invalid choice! Defaulting to Silver.\n";
                    level = SubscriptionLevel::Silver;
            }
            CarRentalSystem::addSubscriber(name, id, level);
            break;
        }
        case 'b': {
            std::string id;
            SubscriptionLevel level;
            std::cout << "Removing new Subscriber...\n";
            std::cout << "Enter subscriber ID to remove: ";
            std::cin >> id;
            CarRentalSystem::removeSubscriberByID(id);
            break;
        }
        case 'c': {
            int level_choice;
            std::string id;
            std::cout << "Promote Subscription...\n";
            std::cout << "Subscription Level: ";
            std::cout << "Choose subscription level:\n";
            std::cout << "1. Silver\n";
            std::cout << "2. Gold\n";
            std::cout << "3. Platinum\n";
            std::cout << "Enter your choice (1, 2, or 3): ";
            std::cin >> level_choice;
            CarRentalSystem::promoteSubscriber(id, level_choice);
            break;
        }
        case 'd':
            std::cout << "Returning to main menu...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
    }

}


void manageSubscription(std::vector<Car> &cars) {
    char subChoice;
    std::cout << "Manage subscription:\n";
    std::cout << "a) Rent a car:\n";
    std::cout << "b) Return a car:\n";
    std::cout << "c) Extend the Rental period:\n";
    std::cout << "Enter your choice: ";
    std::cin >> subChoice;
    switch (subChoice) {
        case 'a':
            std::cout << "Renting a car...\n";
            // TODO: Implement rentCar function, handle rentedCar, amount, and subscriber level
            // rentCar(cars, &rentedCar, &amount, subscriberLevel);
            break;
        case 'b':
            std::cout << "Returning a car...\n";
            // TODO: Implement returnCar function, handle amount, brandName and subscriber level
            // returnCar(cars, &amount, brandName, regNum);
            break;
        case 'c':
            std::cout << "Extending the Rental period...\n";
            // TODO: Implement extendRental function, handle amount, brandName and subscriber level
            // extendRental(cars, &amount, brandName, regNum);
            break;
        default:
            std::cout << "Invalid choice!\n";
    }
}

void reports(std::vector<Car> &cars) {
    char subChoice;
    std::cout << "Reports:\n";
    std::cout << "a) See available car list:\n";
    std::cout << "b) See cars under rental now:\n";
    std::cout << "c) See the subscribers list:\n";
    std::cout << "d) See current subscription book:\n";
    std::cout << "e) See the Revenue so far:\n";
    std::cout << "Enter your choice: ";
    std::cin >> subChoice;
    switch (subChoice) {
        case 'a':
            std::cout << "This is the available car list...\n";
            displayCars(cars);
            break;
        case 'b':
            std::cout << "This is the cars list under rental ...\n";
            // TODO: Implement displayRentedCars function, handle rentedCars
            displayRentedCars(cars);
            break;
        case 'c':
            std::cout << "This is the subscribers list...\n";
            // TODO: Implement displaySubscribers function, handle getSubscribers
            displaySubscribers(Subscriber::getSubscribers());
            break;
        case 'd':
            std::cout << "This is the current subscription book...\n";
            // TODO: Implement displayCurrentSubscription function, handle rentedCars
            displayCurrentSubscription(cars);
            break;
        case 'e':
            std::cout << "This is the Revenue so far...\n";
            // TODO: Implement displayRevenue function, handle amount
            displayRevenue(amount);
            break;
        default:
            std::cout << "Invalid choice!\n";
    }
}