#pragma once
#include <vector>

struct AlertaStock {
    int almacen;
    int producto;
    int stockActual;
    int umbralMinimo;
};

class IInventario {
public:
    virtual ~IInventario() = default;
    virtual void registrarStock(int almacen, int producto, int cantidad) = 0;
    virtual int obtenerStock(int almacen, int producto) const = 0;
    virtual std::vector<int> detectarAgotados(int almacen) const = 0;
    virtual int almacenMenorStock() const = 0;
    virtual std::vector<AlertaStock> generarAlertas() const = 0;
    virtual void configurarUmbral(int umbral) = 0;
    virtual int calcularStockTotal(int almacen) const = 0;
};