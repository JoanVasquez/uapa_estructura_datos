#pragma once
#include "IComponente.h"
#include <functional>
#include <memory>
#include <vector>

using namespace std;

class IAlmacenRepository {
public:
  virtual ~IAlmacenRepository() = default;
  virtual void agregar(unique_ptr<IComponente> componente) = 0;
  virtual IComponente *buscar(const string &codigo) = 0;
  virtual vector<IComponente *>
  filtrar(function<bool(const IComponente *)> pred) = 0;
  virtual bool actualizar(const string &codigo,
                          function<void(IComponente *)> updater) = 0;
};
