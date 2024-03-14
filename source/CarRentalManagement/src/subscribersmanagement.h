#ifndef subscribersmanagement_h
#define subscribersmanagement_h
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
    void addSubscriber(const std::string& name, const std::string& id, SubscriptionLevel level);
    void removeSubscriberByID(const std::string& id);
    void promoteSubscriber(const std::string& id, int newLevel);
    static std::string levelToString(SubscriptionLevel level);
};

#endif
