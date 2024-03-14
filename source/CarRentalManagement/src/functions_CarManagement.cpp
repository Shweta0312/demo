#include <iostream>
#include "functions_CarManagement.h"
#include "subscribersmanagement.h"
#include "report_display.h"
#include "SubscriptionManagement.h"

//#include "SubscriptionManagementFunctions.cpp"

void addCar(std::vector<Car> &cars) {
	Car newCar;
	std::cout << "Enter Brand: ";
	std::cin >> newCar.brand;
	std::cout << "Enter model: ";
	std::cin >> newCar.model;
	std::cout << "Enter registrationNumber: ";
	std::cin >> newCar.registrationNumber;
	std::cout << "Enter Price :";
	std::cin >> newCar.price;

	cars.push_back(newCar);
	std::cout << "Car added successfully!" << std::endl;
}

void removeCar(std::vector<Car> &carList) {
	std::string registrationNumber;
	std::cout << "Enter registration number of the car to remove: ";
	std::cin >> registrationNumber;
	for (auto it = carList.begin(); it != carList.end(); ++it) {
		if (it->registrationNumber == registrationNumber) {
			carList.erase(it);
			std::cout << "Car removed from rental list." << std::endl;
			return;
		}
	}
	std::cout << "Car with registration number " << registrationNumber
			<< " not found in rental list." << std::endl;
}

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

void manageSubscriber(CarRentalSystem &carRentalSystem) {
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
                break;
            case 2:
                level = SubscriptionLevel::Gold;
                break;
            case 3:
                level = SubscriptionLevel::Platinum;
                break;
            default:
                std::cerr << "Invalid choice! Defaulting to Silver.\n";
                level = SubscriptionLevel::Silver;
        }
		carRentalSystem.addSubscriber(name, id, level);
		break;
	}
	case 'b': {
		std::string id;
		std::cout << "Removing new Subscriber...\n";
		std::cout << "Enter subscriber ID to remove: ";
		std::cin >> id;
		carRentalSystem.removeSubscriberByID(id);
		break;
	}
	case 'c': {
		int level_choice;
		std::string id;
		std::cout << "Promote Subscription...\n";
        std::cout << "Enter subscriber ID to promote: ";
        std::cin >> id;
		std::cout << "Subscription Level: ";
		std::cout << "Choose subscription level:\n";
		std::cout << "1. Silver\n";
		std::cout << "2. Gold\n";
		std::cout << "3. Platinum\n";
		std::cout << "Enter your choice (1, 2, or 3): ";
		std::cin >> level_choice;
		carRentalSystem.promoteSubscriber(id, level_choice);
		break;
	}
	case 'd':
		std::cout << "Returning to main menu...\n";
		break;
	default:
		std::cout << "Invalid choice!\n";
	}
}

void manageSubscription(vector<Car> &cars, vector<int> &amount, vector<Car> &rentedCar) {
	char subChoice;
	std::cout << "Manage subscription:\n";
	std::cout << "a) Rent a car:\n";
	std::cout << "b) Return a car:\n";
	std::cout << "c) Extend the Rental period:\n";
	std::cout << "Enter your choice: ";
	std::cin >> subChoice;
	switch (subChoice) {
	case 'a':
	{
		// TODO: Handle rent car function;
		 _rentCar(cars, amount, rentedCar);
		std::cout << "Rented Car Successfully...\n";
		break;
	}
	case 'b':
	{
		// TODO: Handle return car function;
		_returnCar(cars, amount);
		std::cout << "Returned car Successfully...\n";
		break;
	}
	case 'c':
	{
		// TODO: Handle extend car rental function
		_extendRental(cars, amount);
		std::cout << "Extended the Rental Period...\n";
		break;
	}
	default:
		std::cout << "Invalid choice!\n";
	}

}

void reports(std::vector <Car> &cars, std::vector<Subscriber>& subscribers) {  //<- here
	char subChoice;
	std::cout << "Reports:\n";
	std::cout << "a) See available car list:\n";
	std::cout << "b) See cars under rental now:\n";
	std::cout << "c) See the subscribers list:\n";
	std::cout << "d) See the Revenue so far:\n";
	//std::cout << "Enter your choice: ";                              	                                                	                             	                                                                                                                                                                                                                             std::cout << "d) See current subscription book:\n";
	std::cout << "Enter your choice: ";
	std::cin >> subChoice;
	switch (subChoice) {
	case 'a':
	{
		display_Cars(cars);
		break;
	}
	case 'b':
	{
		// TODO: Handle displayRentedCars function
		// where is rented cars, find it call it in parent function like &cars
		// displayRentedCars(const vector<Car> &RentedCars);
		//displayRentedCars(rentedCar);
		break;
	}
	case 'c':
	{
		displaySubscribers(subscribers);
		break;
	}
	case 'd':
	{
		// TODO: Handle displayRevenue function
		// where is amount, find it call it in parent function like &cars
		//displayRevenue(amount);
		break;
	}
	default:
		std::cout << "Invalid choice!\n";
	}
}
