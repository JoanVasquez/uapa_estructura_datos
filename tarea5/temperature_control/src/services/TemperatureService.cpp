#include "../../includes/services/TemperatureService.h"
#include <iostream>
#include <iomanip>

void TemperatureService::addRegistro(std::string fecha, double temperatura) {
    repository.addRegistro(fecha, temperatura);
    std::cout << "Registro added: " << fecha << " - " << temperatura << "°C\n";
}

void TemperatureService::displayRegistrosSortedByTemperature() {
    std::vector<DiaClima> sortedRegistros = repository.getRegistrosSortedByTemperature();
    
    if (sortedRegistros.empty()) {
        std::cout << "No temperature records available.\n";
        return;
    }
    
    std::cout << "=== TEMPERATURE RECORDS SORTED BY TEMPERATURE ===\n";
    std::cout << std::left << std::setw(12) << "Date" 
              << std::setw(15) << "Temperature (°C)" << "\n";
    std::cout << std::string(27, '-') << "\n";
    
    for (const DiaClima& registro : sortedRegistros) {
        std::cout << std::left << std::setw(12) << registro.fecha
                  << std::setw(15) << std::fixed << std::setprecision(1) << registro.temperatura << "\n";
    }
}

void TemperatureService::searchByDate(std::string fecha) {
    DiaClima* registro = repository.searchByDate(fecha);
    
    if (registro) {
        std::cout << "Temperature record found:\n";
        std::cout << "Date: " << registro->fecha << "\n";
        std::cout << "Temperature: " << std::fixed << std::setprecision(1) << registro->temperatura << "°C\n";
    } else {
        std::cout << "No temperature record found for date: " << fecha << "\n";
    }
}

void TemperatureService::displayAverageTemperature() {
    double average = repository.getAverageTemperature();
    std::cout << "Average temperature: " << std::fixed << std::setprecision(2) << average << "°C\n";
}

void TemperatureService::displayAllRegistros() {
    std::vector<DiaClima> registros = repository.getAllRegistros();
    
    if (registros.empty()) {
        std::cout << "No temperature records available.\n";
        return;
    }
    
    std::cout << "=== ALL TEMPERATURE RECORDS ===\n";
    std::cout << "Total records: " << registros.size() << "\n\n";
    std::cout << std::left << std::setw(5) << "No."
              << std::setw(12) << "Date"
              << std::setw(15) << "Temperature (°C)" << "\n";
    std::cout << std::string(32, '-') << "\n";
    
    for (size_t i = 0; i < registros.size(); i++) {
        std::cout << std::left << std::setw(5) << i + 1
                  << std::setw(12) << registros[i].fecha
                  << std::setw(15) << std::fixed << std::setprecision(1) << registros[i].temperatura << "\n";
    }
}

void TemperatureService::displayStatistics() {
    int count = repository.getRegistroCount();
    double average = repository.getAverageTemperature();
    std::vector<DiaClima> sortedRegistros = repository.getRegistrosSortedByTemperature();
    
    std::cout << "=== TEMPERATURE STATISTICS ===\n";
    std::cout << "Total records: " << count << "\n";
    std::cout << "Average temperature: " << std::fixed << std::setprecision(2) << average << "°C\n";
    
    if (count > 0) {
        double minTemp = sortedRegistros[0].temperatura;
        double maxTemp = sortedRegistros[count - 1].temperatura;
        
        std::cout << "Minimum temperature: " << std::fixed << std::setprecision(1) << minTemp << "°C\n";
        std::cout << "Maximum temperature: " << std::fixed << std::setprecision(1) << maxTemp << "°C\n";
        std::cout << "Temperature range: " << (maxTemp - minTemp) << "°C\n";
    }
}

void TemperatureService::clearRegistros() {
    repository.clearRegistros();
    std::cout << "All temperature records cleared.\n";
}
