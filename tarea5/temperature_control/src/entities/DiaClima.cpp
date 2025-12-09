#include "../../includes/entities/DiaClima.h"

DiaClima::DiaClima() : fecha(""), temperatura(0.0) {}

DiaClima::DiaClima(std::string f, double t)
    : fecha(f), temperatura(t) {}
