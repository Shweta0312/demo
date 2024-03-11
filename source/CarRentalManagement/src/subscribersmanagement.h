#ifndef SMS_H // C
#define SMS_H
#include <iostream>
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
    Subscriber(std::string n, std::string i, SubscriptionLevel l, int max, double disc);
    std::string getName() const;
    std::string getID() const;
    SubscriptionLevel getLevel() const;
    int getMaxCars() const;
    double getDiscount() const;
    void setLevel(SubscriptionLevel newLevel);
};

class CarRentalSystem {
private:
    std::vector<Subscriber> subscribers;

public:
    void addSubscriber(std::string name, std::string id, SubscriptionLevel level);
    void removeSubscriberByID(std::string id);
    void promoteSubscriber(std::string id, int newLevel);
    std::string levelToString(SubscriptionLevel level);
};

#endif
