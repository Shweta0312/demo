cmake_minimum_required(VERSION 3.26)
project(Cars_rental_management_system)

set(CMAKE_CXX_STANDARD 14)

include_directories(source/CarRentalManagement/src)

add_executable(Cars_rental_management_system
        source/CarRentalManagement/src/CarRental_UI.cpp
        source/CarRentalManagement/src/headers/class_car_management.h
        source/CarRentalManagement/src/functions_CarManagement.cpp
        source/CarRentalManagement/src/headers/core_functions.h
        source/CarRentalManagement/src/trash/report_display.cpp
        source/CarRentalManagement/src/headers/subscribers.h
        source/CarRentalManagement/src/headers/manage_car_functions.h
        source/CarRentalManagement/src/manage_cars.cpp
        source/CarRentalManagement/src/manage_subscriber.cpp
        source/CarRentalManagement/src/headers/subscription.h
        source/CarRentalManagement/src/manage_subscription.cpp
        source/CarRentalManagement/src/headers/reports.h
        source/CarRentalManagement/src/reports.cpp)
