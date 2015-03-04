#ifndef BLASTED_CITY_COMPONENTS_LOCALINPUTIMPLEMENTATION_H_
#define BLASTED_CITY_COMPONENTS_LOCALINPUTIMPLEMENTATION_H_

#include "InputComponent.h"

#include "../global.h"

namespace blasted_city {

class LocalInputImplementation : public InputComponent
{
 public:
  LocalInputImplementation();
  ~LocalInputImplementation();

  void Init();

 private:
  virtual void UpdateImpl(Entity &entity) override;
};

} // namespace blasted_city

#endif // BLASTED_CITY_COMPONENTS_LOCALINPUTIMPLEMENTATION_H_
