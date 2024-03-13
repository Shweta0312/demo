#ifndef SUBSCRIBERS_MANAGEMENT_H
#define SUBSCRIBERS_MANAGEMENT_H

#include <iostream>
#include <utility>
#include <vector>
#include <string>

enum class SubscriptionLevel {
    Silver,
    Gold,
    Platinum
};

class Subscriber {
private:
    std::string name;
    std::string id;
    SubscriptionLevel level;
    int maxCars;
    double discount;

public:
    Subscriber(std::string n, std::string i, SubscriptionLevel l, int max, double disc)
            : name(std::move(n)), id(std::move(i)), level(l), maxCars(max), discount(disc) {}

    static std::string getName();

    std::string getID();

    static SubscriptionLevel getLevel();

    int getMaxCars() const;

    double getDiscount() const;

    void setLevel(SubscriptionLevel newLevel);
};

class CarRentalSystem {
private:
    static std::vector<Subscriber> subscribers;

public:
    static void addSubscriber(const std::string& name, const std::string& id, SubscriptionLevel level);

    static void removeSubscriberByID(const std::string& id);

    static void promoteSubscriber(const std::string& id, int newLevel);

    static std::string levelToString(SubscriptionLevel level);
};

#endif
