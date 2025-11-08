#include "../include/AlmacenRepository.h"
#include <stdexcept>

using namespace std;

// Agrega un nuevo componente al repositorio con validación de duplicados
void AlmacenRepository::agregar(unique_ptr<IComponente> componente) {
  if (!componente)
    throw invalid_argument("Componente nulo");

  // Obtener el código antes de mover el puntero
  string codigo = componente->getCodigo();
  // Verificar que no exista un componente con el mismo código
  if (componentes.find(codigo) != componentes.end())
    throw runtime_error("Código duplicado: " + codigo);

  // Almacenar el componente usando su código como clave
  componentes[codigo] = move(componente);
}

// Busca un componente por su código único
IComponente *AlmacenRepository::buscar(const string &codigo) {
  auto it = componentes.find(codigo);
  return (it != componentes.end()) ? it->second.get() : nullptr;
}

// Filtra componentes usando un predicado (patrón Strategy)
vector<IComponente *>
AlmacenRepository::filtrar(function<bool(const IComponente *)> pred) {
  vector<IComponente *> resultado;
  // Iterar sobre todos los componentes y aplicar el filtro
  for (const auto &par : componentes) {
    if (pred(par.second.get())) {
      resultado.push_back(par.second.get());
    }
  }
  return resultado;
}

// Actualiza un componente aplicando una función de actualización
bool AlmacenRepository::actualizar(const string &codigo,
                                   function<void(IComponente *)> updater) {
  auto *componente = buscar(codigo);
  if (!componente)
    return false;      // Componente no encontrado
  updater(componente); // Aplicar la actualización
  return true;
}
