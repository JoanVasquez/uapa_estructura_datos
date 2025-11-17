#ifndef MEDIDOR_TIEMPO_SERVICIO_H
#define MEDIDOR_TIEMPO_SERVICIO_H

#include <chrono>

class MedidorTiempoServicio {
private:
    std::chrono::high_resolution_clock::time_point tiempoInicio;
    std::chrono::high_resolution_clock::time_point tiempoFin;
    double tiempoTotal;
    
public:
    MedidorTiempoServicio() : tiempoTotal(0.0) {}
    
    void iniciar() {
        tiempoInicio = std::chrono::high_resolution_clock::now();
    }
    
    double detener() {
        tiempoFin = std::chrono::high_resolution_clock::now();
        auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(tiempoFin - tiempoInicio);
        double tiempoTranscurrido = duracion.count() / 1000.0;
        tiempoTotal += tiempoTranscurrido;
        return tiempoTranscurrido;
    }
    
    double obtenerTiempoTotal() const {
        return tiempoTotal;
    }
    
    void reiniciarTotal() {
        tiempoTotal = 0.0;
    }
};

#endif