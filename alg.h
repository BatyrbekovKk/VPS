//alg.h
#ifndef TRANSPORT_SELECTOR_H
#define TRANSPORT_SELECTOR_H

#include <vector>
#include <string>
#include <sqlite3.h>

// Структура для представления груза
struct Cargo {
    int id;
    double weight;
    double volume;
    std::string load_type;
    std::string special_specifications;
};

// Структура для представления транспортного средства
struct Vehicle {
    int id;
    double carrying_capacity;
    double volume;
    std::string category;
    double carrier_rating;
    std::string special_specifications;
};

// Функция для получения данных о грузах из базы данных
std::vector<Cargo> getCargosFromDB(sqlite3* db);

// Функция для получения данных о транспортных средствах из базы данных
std::vector<Vehicle> getVehiclesFromDB(sqlite3* db);

// Функция для фильтрации и сортировки транспортных средств по заданным критериям
std::vector<Vehicle> filterAndSortVehicles(const Cargo& cargo, const std::vector<Vehicle>& vehicles, sqlite3* db);

#endif // TRANSPORT_SELECTOR_H
