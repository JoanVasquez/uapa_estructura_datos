#ifndef DIACLIMA_H
#define DIACLIMA_H

#include <string>

class DiaClima {
public:
    std::string fecha;
    double temperatura;
    
    DiaClima();
    DiaClima(std::string f, double t);
};

#endif
