#include "subscribersmanagement.h"

Subscriber::Subscriber(std::string n, std::string i, SubscriptionLevel l, int max, double disc)
    : name(n), id(i), level(l), maxCars(max), discount(disc) {}

std::string Subscriber::getName() const {
    return name;
}

std::string Subscriber::getID() const {
    return id;
}

SubscriptionLevel Subscriber::getLevel() const {
    return level;
}

int Subscriber::getMaxCars() const {
    return maxCars;
}

double Subscriber::getDiscount() const {
    return discount;
}

void Subscriber::setLevel(SubscriptionLevel newLevel) {
    level = newLevel;
}

void CarRentalSystem::addSubscriber(std::string name, std::string id, SubscriptionLevel level) {
    int maxCars;
    double discount;

    switch (level) {
    case SubscriptionLevel::Silver:
        maxCars = 1;
        discount = 0.0;
        break;
    case SubscriptionLevel::Gold:
        maxCars = 2;
        discount = 0.10;
        break;
    case SubscriptionLevel::Platinum:
        maxCars = 3;
        discount = 0.20;
        break;
    }

    subscribers.push_back(Subscriber(name, id, level, maxCars, discount));

    std::cout << "Subscriber added successfully:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Subscription Level: " << levelToString(level) << std::endl;
}

void CarRentalSystem::removeSubscriberByID(std::string id) {
    for (auto it = subscribers.begin(); it != subscribers.end(); ++it) {
        if (it->getID() == id) {
            std::cout << "Subscriber removed successfully:" << std::endl;
            std::cout << "Name: " << it->getName() << std::endl;
            std::cout << "ID: " << it->getID() << std::endl;
            std::cout << "Subscription Level: " << levelToString(it->getLevel()) << std::endl;
            subscribers.erase(it);
            return;
        }
    }
    std::cout << "Subscriber with ID " << id << " not found." << std::endl;
}

void CarRentalSystem::promoteSubscriber(std::string id, int newLevel) {
    for (auto &subscriber : subscribers) {
        if (subscriber.getID() == id) {
            SubscriptionLevel currentLevel = subscriber.getLevel();
            SubscriptionLevel level;
            switch (newLevel) {
            case 0:
                level = SubscriptionLevel::Silver;
                break;
            case 1:
                level = SubscriptionLevel::Gold;
                break;
            case 2:
                level = SubscriptionLevel::Platinum;
                break;
            default:
                std::cout << "Invalid subscription level." << std::endl;
                return;
            }

            if (currentLevel == level) {
                std::cout << "Subscriber with ID " << id << " is already at " << levelToString(level) << " level." << std::endl;
                return;
            }

            subscriber.setLevel(level);
            std::cout << "Subscriber with ID " << id << " promoted to " << levelToString(level) << " level." << std::endl;
            return;
        }
    }
    std::cout << "Subscriber with ID " << id << " not found." << std::endl;
}

std::string CarRentalSystem::levelToString(SubscriptionLevel level) {
    switch (level) {
    case SubscriptionLevel::Silver:
        return "Silver";
    case SubscriptionLevel::Gold:
        return "Gold";
    case SubscriptionLevel::Platinum:
        return "Platinum";
    }
    return ""; // This should never be reached, just to satisfy the compiler.
}

void handleMenuChoice(CarRentalSystem& rentalSystem, int choice) {
    if (choice == 1) {
        std::string name, id;
        int level;

        std::cout << "Enter subscriber name: ";
        std::cin >> name;
        std::cout << "Enter subscriber ID: ";
        std::cin >> id;
        std::cout << "Enter subscription level (0 for Silver, 1 for Gold, 2 for Platinum): ";
        std::cin >> level;

        rentalSystem.addSubscriber(name, id, static_cast<SubscriptionLevel>(level));
    } else if (choice == 2) {
        std::string id;
        std::cout << "Enter subscriber ID to remove: ";
        std::cin >> id;
        rentalSystem.removeSubscriberByID(id);
    } else if (choice == 3) {
        std::string id;
        int level;
        std::cout << "Enter subscriber ID to promote: ";
        std::cin >> id;
        std::cout << "Enter new subscription level (0 for Silver, 1 for Gold, 2 for Platinum): ";
        std::cin >> level;
        rentalSystem.promoteSubscriber(id, level);
    } else if (choice == 4) {
        std::cout << "Exiting..." << std::endl;
    } else {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
}

int main() {
    CarRentalSystem rentalSystem;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add a subscriber" << std::endl;
        std::cout << "2. Remove a subscriber by ID" << std::endl;
        std::cout << "3. Promote subscription level" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 4) {
            handleMenuChoice(rentalSystem, choice);
            break;
        } else {
            handleMenuChoice(rentalSystem, choice);
}     }     return 0; }
