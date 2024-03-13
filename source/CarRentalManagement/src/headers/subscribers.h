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
    Subscriber(std::string  n, std::string i, SubscriptionLevel l, int max, double disc);

    std::string getName() const;

    std::string getID();

    SubscriptionLevel getLevel() const;

    int getMaxCars() const;

    double getDiscount() const;

    void setLevel(SubscriptionLevel newLevel);

};

class CarRentalSystem {
private:
    static std::vector<Subscriber> subscribers;

public:
    static void addSubscriber(const std::string &name, const std::string &id, SubscriptionLevel level);

    static void removeSubscriberByID(const std::string &id);

    static void promoteSubscriber(const std::string &id, int newLevel);

    static std::string levelToString(SubscriptionLevel level);
};

#endif
