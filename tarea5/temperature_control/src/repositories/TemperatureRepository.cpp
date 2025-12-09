#include "../../includes/repositories/TemperatureRepository.h"
#include <iostream>
#include <algorithm>

TemperatureRepository::TemperatureRepository() {}

void TemperatureRepository::addRegistro(std::string fecha, double temperatura) {
    registros.push_back(DiaClima(fecha, temperatura));
}

void TemperatureRepository::mergeSortByTemperature(std::vector<DiaClima>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortByTemperature(arr, left, mid);
        mergeSortByTemperature(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void TemperatureRepository::merge(std::vector<DiaClima>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    std::vector<DiaClima> leftArr(n1);
    std::vector<DiaClima> rightArr(n2);
    
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i].temperatura <= rightArr[j].temperatura) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

std::vector<DiaClima> TemperatureRepository::getRegistrosSortedByTemperature() {
    std::vector<DiaClima> sortedRegistros = registros;
    
    if (!sortedRegistros.empty()) {
        mergeSortByTemperature(sortedRegistros, 0, sortedRegistros.size() - 1);
    }
    
    return sortedRegistros;
}

int TemperatureRepository::searchByDateRecursive(std::string fecha, int index) {
    if (index >= static_cast<int>(registros.size())) {
        return -1;
    }
    
    if (registros[index].fecha == fecha) {
        return index;
    }
    
    return searchByDateRecursive(fecha, index + 1);
}

DiaClima* TemperatureRepository::searchByDate(std::string fecha) {
    int index = searchByDateRecursive(fecha, 0);
    
    if (index != -1) {
        return &registros[index];
    }
    
    return nullptr;
}

double TemperatureRepository::calculateAverageRecursive(int index, double sum, int count) {
    if (index >= static_cast<int>(registros.size())) {
        if (count == 0) return 0.0;
        return sum / count;
    }
    
    return calculateAverageRecursive(index + 1, sum + registros[index].temperatura, count + 1);
}

double TemperatureRepository::getAverageTemperature() {
    return calculateAverageRecursive(0, 0.0, 0);
}

std::vector<DiaClima> TemperatureRepository::getAllRegistros() {
    return registros;
}

int TemperatureRepository::getRegistroCount() {
    return static_cast<int>(registros.size());
}

void TemperatureRepository::clearRegistros() {
    registros.clear();
}
