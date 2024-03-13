#include "headers/subscribers.h"
#include <string>

std::string Subscriber::getName() {
    return name;
}

std::string Subscriber::getID() {
    return id;
}

SubscriptionLevel Subscriber::getLevel() {
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

void CarRentalSystem::addSubscriber(const std::string &name, const std::string &id, SubscriptionLevel level) {
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

    subscribers.emplace_back(name, id, level, maxCars, discount);
}

void CarRentalSystem::removeSubscriberByID(const std::string &id) {
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

void CarRentalSystem::promoteSubscriber(const std::string &id, int newLevel) {
    for (auto &subscriber: subscribers) {
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
                std::cout << "Subscriber with ID " << id << " is already at " << levelToString(level) << " level."
                          << std::endl;
                return;
            }

            subscriber.setLevel(level);
            std::cout << "Subscriber with ID " << id << " promoted to " << levelToString(level) << " level."
                      << std::endl;
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
}
