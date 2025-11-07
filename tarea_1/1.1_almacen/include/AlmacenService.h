#pragma once
#include "IAlmacenRepository.h"
#include <memory>

class AlmacenService {
private:
    std::unique_ptr<IAlmacenRepository> repository;

public:
    explicit AlmacenService(std::unique_ptr<IAlmacenRepository> repo);
    
    void registrarNacional(const std::string& codigo, const std::string& nombre,
                          double precio, int cantidad, const std::string& empresa, int minimo = 10);
    void registrarImportado(const std::string& codigo, const std::string& nombre,
                           double precio, int cantidad, const std::string& pais, 
                           double precioUSD, int minimo = 10);
    
    void modificarCantidad(const std::string& codigo, int cantidad);
    void modificarNivelMinimo(const std::string& codigo, int nivel);
    
    std::vector<IComponente*> nacionalesPorPrecio(double minimo);
    std::vector<IComponente*> importadosPorPais(const std::string& pais);
    std::vector<IComponente*> componentesBajoStock();
};