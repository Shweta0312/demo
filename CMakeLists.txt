cmake_minimum_required(VERSION 3.26)
project(Cars_rental_management_system)

set(CMAKE_CXX_STANDARD 14)

include_directories(source/CarRentalManagement/src)

add_executable(Cars_rental_management_system
        source/CarRentalManagement/src/Class_CarManagement.h
        source/CarRentalManagement/src/functions_CarManagement.h
        source/CarRentalManagement/src/report_display.cpp
        source/CarRentalManagement/src/report_display.h
        source/CarRentalManagement/src/subscribersmanagement.cpp
        source/CarRentalManagement/src/subscribersmanagement.h
        source/CarRentalManagement/src/SubscriptionManagement.cpp
        source/CarRentalManagement/src/SubscriptionManagement.h
        source/CarRentalManagement/src/CarRental_UI.cpp
        source/CarRentalManagement/src/functions_CarManagement.cpp
)
