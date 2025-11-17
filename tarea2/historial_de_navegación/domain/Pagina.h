#ifndef PAGINA_H
#define PAGINA_H

#include <cstring>

class Pagina {
private:
    static const int MAX_URL = 200;
    static const int MAX_FECHA = 20;
    char url[MAX_URL];
    char fechaHora[MAX_FECHA];
    
public:
    Pagina() {
        url[0] = '\0';
        fechaHora[0] = '\0';
    }
    
    Pagina(const char* urlParam, const char* fechaParam) {
        establecerUrl(urlParam);
        establecerFechaHora(fechaParam);
    }
    
    void establecerUrl(const char* urlParam) {
        if (urlParam != nullptr) {
            strncpy(url, urlParam, MAX_URL - 1);
            url[MAX_URL - 1] = '\0';
        }
    }
    
    void establecerFechaHora(const char* fechaParam) {
        if (fechaParam != nullptr) {
            strncpy(fechaHora, fechaParam, MAX_FECHA - 1);
            fechaHora[MAX_FECHA - 1] = '\0';
        }
    }
    
    const char* obtenerUrl() const {
        return url;
    }
    
    const char* obtenerFechaHora() const {
        return fechaHora;
    }
    
    bool esValida() const {
        return url[0] != '\0' && fechaHora[0] != '\0';
    }
    
    bool coincideUrl(const char* urlBuscado) const {
        return strcmp(url, urlBuscado) == 0;
    }
};

#endif