#ifndef VALIDADOR_PAGINA_SERVICIO_H
#define VALIDADOR_PAGINA_SERVICIO_H

#include <cstring>

class ValidadorPaginaServicio {
public:
    bool esUrlValida(const char* url) const {
        if (url == nullptr || strlen(url) == 0) {
            return false;
        }
        
        if (strlen(url) > 200) {
            return false;
        }
        
        // Verificar que no sea solo espacios
        bool tieneCaracteres = false;
        for (int i = 0; url[i] != '\0'; i++) {
            if (url[i] != ' ' && url[i] != '\t') {
                tieneCaracteres = true;
                break;
            }
        }
        
        return tieneCaracteres;
    }
    
    bool esFechaValida(const char* fecha) const {
        if (fecha == nullptr || strlen(fecha) == 0) {
            return false;
        }
        
        if (strlen(fecha) > 20) {
            return false;
        }
        
        return true;
    }
    
    bool esPaginaValida(const char* url, const char* fecha) const {
        return esUrlValida(url) && esFechaValida(fecha);
    }
};

#endif