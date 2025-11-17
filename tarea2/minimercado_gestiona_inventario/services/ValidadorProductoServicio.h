#ifndef VALIDADOR_PRODUCTO_SERVICIO_H
#define VALIDADOR_PRODUCTO_SERVICIO_H

#include <cstring>

// Servicio: Validador de productos
class ValidadorProductoServicio {
public:
    bool esNombreValido(const char* nombre) const {
        if (nombre == nullptr || strlen(nombre) == 0) {
            return false;
        }
        
        if (strlen(nombre) > 100) {
            return false;
        }
        
        // Verificar que no sea solo espacios
        bool tieneCaracteres = false;
        for (int i = 0; nombre[i] != '\0'; i++) {
            if (nombre[i] != ' ' && nombre[i] != '\t') {
                tieneCaracteres = true;
                break;
            }
        }
        
        return tieneCaracteres;
    }
    
    bool esCodigoValido(int codigo) const {
        return codigo > 0;
    }
    
    bool esCantidadValida(int cantidad) const {
        return cantidad >= 0;
    }
    
    bool esProductoValido(int codigo, const char* nombre, int cantidad) const {
        return esCodigoValido(codigo) && esNombreValido(nombre) && esCantidadValida(cantidad);
    }
};

#endif