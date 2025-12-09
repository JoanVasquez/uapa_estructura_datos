#include "../../includes/controllers/TemperatureController.h"
#include <iostream>

void TemperatureController::executeOption(int option) {
    std::string fecha;
    double temperatura;
    
    switch (option) {
        case 1:
            std::cout << "Enter date (DD/MM/YYYY): ";
            std::getline(std::cin, fecha);
            std::cout << "Enter temperature (°C): ";
            std::cin >> temperatura;
            std::cin.ignore();
            service.addRegistro(fecha, temperatura);
            break;
        case 2:
            service.displayRegistrosSortedByTemperature();
            break;
        case 3:
            std::cout << "Enter date to search (DD/MM/YYYY): ";
            std::getline(std::cin, fecha);
            service.searchByDate(fecha);
            break;
        case 4:
            service.displayAverageTemperature();
            break;
        case 5:
            service.displayAllRegistros();
            break;
        case 6:
            service.displayStatistics();
            break;
        case 7:
            service.clearRegistros();
            break;
    }
}
