#ifndef VALIDADOR_TAREA_SERVICIO_H
#define VALIDADOR_TAREA_SERVICIO_H

#include <cstring>

// Servicio: Validador de tareas
class ValidadorTareaServicio {
public:
    bool esNombreValido(const char* nombre) const {
        if (nombre == nullptr || strlen(nombre) == 0) {
            return false;
        }
        
        if (strlen(nombre) > 200) {
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
    
    bool esPrioridadValida(int prioridad) const {
        return prioridad >= 1 && prioridad <= 10;
    }
    
    bool esTareaValida(const char* nombre, int prioridad) const {
        return esNombreValido(nombre) && esPrioridadValida(prioridad);
    }
};

#endif