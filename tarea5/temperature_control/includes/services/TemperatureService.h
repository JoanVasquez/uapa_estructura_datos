#ifndef TEMPERATURESERVICE_H
#define TEMPERATURESERVICE_H

#include "../repositories/TemperatureRepository.h"
#include <string>
#include <vector>

class TemperatureService {
private:
    TemperatureRepository repository;

public:
    void addRegistro(std::string fecha, double temperatura);
    void displayRegistrosSortedByTemperature();
    void searchByDate(std::string fecha);
    void displayAverageTemperature();
    void displayAllRegistros();
    void displayStatistics();
    void clearRegistros();
};

#endif
