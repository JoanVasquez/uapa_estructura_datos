#pragma once
#include "IAlmacenRepository.h"
#include <unordered_map>

using namespace std;

class AlmacenRepository : public IAlmacenRepository {
private:
  unordered_map<string, unique_ptr<IComponente>> componentes;

public:
  void agregar(unique_ptr<IComponente> componente) override;
  IComponente *buscar(const string &codigo) override;
  vector<IComponente *>
  filtrar(function<bool(const IComponente *)> pred) override;
  bool actualizar(const string &codigo,
                  function<void(IComponente *)> updater) override;
};
