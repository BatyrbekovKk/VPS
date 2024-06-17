//alg.cpp
#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <string>
#include <algorithm>
#include "transport_selector.h"

std::vector<Cargo> getCargosFromDB(sqlite3* db) {
    std::vector<Cargo> cargos;
    sqlite3_stmt* stmt;
    const char* sql = "SELECT id, weight, volume, load_type, special_specifications FROM Cargo";
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            Cargo cargo;
            cargo.id = sqlite3_column_int(stmt, 0);
            cargo.weight = sqlite3_column_double(stmt, 1);
            cargo.volume = sqlite3_column_double(stmt, 2);
            cargo.load_type = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            cargo.special_specifications = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
            cargos.push_back(cargo);
        }
    }
    sqlite3_finalize(stmt);
    return cargos;
}

std::vector<Vehicle> getVehiclesFromDB(sqlite3* db) {
    std::vector<Vehicle> vehicles;
    sqlite3_stmt* stmt;
    const char* sql = "SELECT id, carrying_capacity, volume, category, technical_condition FROM Vehicle";
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            Vehicle vehicle;
            vehicle.id = sqlite3_column_int(stmt, 0);
            vehicle.carrying_capacity = sqlite3_column_double(stmt, 1);
            vehicle.volume = sqlite3_column_double(stmt, 2);
            vehicle.category = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            vehicle.special_specifications = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
            vehicles.push_back(vehicle);
        }
    }
    sqlite3_finalize(stmt);
    return vehicles;
}

std::vector<Vehicle> filterAndSortVehicles(const Cargo& cargo, const std::vector<Vehicle>& vehicles, sqlite3* db) {
    std::vector<Vehicle> filteredVehicles;

    for (const auto& vehicle : vehicles) {
        if (vehicle.carrying_capacity >= cargo.weight &&
            vehicle.volume >= cargo.volume &&
            vehicle.category == cargo.load_type &&
            vehicle.special_specifications == cargo.special_specifications) {
            
            double carrier_rating = 0.0;
            sqlite3_stmt* stmt;
            const char* sql = "SELECT carrier_rating FROM Personnel WHERE id = ?";
            if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
                sqlite3_bind_int(stmt, 1, vehicle.id);
                if (sqlite3_step(stmt) == SQLITE_ROW) {
                    carrier_rating = sqlite3_column_double(stmt, 0);
                }
            }
            sqlite3_finalize(stmt);

            Vehicle v = vehicle;
            v.carrier_rating = carrier_rating;
            filteredVehicles.push_back(v);
        }
    }

    std::sort(filteredVehicles.begin(), filteredVehicles.end(), [](const Vehicle& a, const Vehicle& b) {
        return a.carrier_rating > b.carrier_rating;
    });

    return filteredVehicles;
}

int main() {
    sqlite3* db;
    if (sqlite3_open("transport.db", &db) != SQLITE_OK) {
        std::cerr << "Не удалось открыть базу данных\n";
        return -1;
    }

    std::vector<Cargo> cargos = getCargosFromDB(db);
    std::vector<Vehicle> vehicles = getVehiclesFromDB(db);

    if (cargos.empty()) {
        std::cerr << "Нет данных о грузах в базе данных\n";
        sqlite3_close(db);
        return -1;
    }

    const Cargo& cargo = cargos[0]; // Предполагаем, что выбираем первый груз из списка

    std::vector<Vehicle> suitableVehicles = filterAndSortVehicles(cargo, vehicles, db);

    std::cout << "Подходящие транспортные средства:\n";
    for (const auto& vehicle : suitableVehicles) {
        std::cout << "ID: " << vehicle.id
                  << ", Грузоподъемность: " << vehicle.carrying_capacity
                  << ", Объем: " << vehicle.volume
                  << ", Категория: " << vehicle.category
                  << ", Рейтинг: " << vehicle.carrier_rating
                  << ", Особые спецификации: " << vehicle.special_specifications << "\n";
    }

    sqlite3_close(db);
    return 0;
}

