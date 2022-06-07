cmake_minimum_required(VERSION 3.22)
project(cpp_big_homework)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_big_homework
        main.cpp
        model/Vehicle.cpp model/Vehicle.h
        Utils.cpp Utils.h
        model/Truck.cpp model/Truck.h
        model/Car.cpp model/Car.h
        model/Bus.cpp model/Bus.h
        model/Person.cpp model/Person.h
        model/Date.cpp model/Date.h
        service/VehicleService.cpp service/VehicleService.h
        MenuFunc.cpp MenuFunc.h
        service/PersonService.cpp service/PersonService.h
        )
