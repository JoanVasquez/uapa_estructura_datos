#ifndef TEMPERATUREREPOSITORY_H
#define TEMPERATUREREPOSITORY_H

#include "../entities/DiaClima.h"
#include <string>
#include <vector>

class TemperatureRepository {
private:
    std::vector<DiaClima> registros;
    
    void mergeSortByTemperature(std::vector<DiaClima>& arr, int left, int right);
    void merge(std::vector<DiaClima>& arr, int left, int mid, int right);
    double calculateAverageRecursive(int index, double sum, int count);
    int searchByDateRecursive(std::string fecha, int index);

public:
    TemperatureRepository();
    void addRegistro(std::string fecha, double temperatura);
    std::vector<DiaClima> getRegistrosSortedByTemperature();
    DiaClima* searchByDate(std::string fecha);
    double getAverageTemperature();
    std::vector<DiaClima> getAllRegistros();
    int getRegistroCount();
    void clearRegistros();
};

#endif
