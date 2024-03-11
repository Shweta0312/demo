#include <iostream>
#include <vector>
#include <string>

#include "headers/Class_CarManagement.h"
#include "headers/functions_CarManagement.h"


using namespace std;


int main() {
    cout << "----------------------" << endl;
    cout << "Company Name : RapidRentals " << endl;
    cout << "----------------------" << endl;
    vector<Car> cars;
    int choice;

    while (true) {
        cout << "Main Menu:\n";
        cout << "1. Manage Car\n";
        cout << "2. Manage Subscriber\n";
        cout << "3. Manage Subscription\n";
        cout << "4. Reports\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

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
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}

