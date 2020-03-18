#include "movement_02.hpp"

namespace movement_02 {

  struct energy {
    enum struct scale {
      kJ,
      kcal,
    };

    static constexpr double factor { 4.184 } ;

    constexpr energy(double v, scale s) : _value { v }, _scale { s } { }

    constexpr energy convert(scale target_scale) {
      return { 0.0, target_scale } ;
    }

    constexpr double value(scale target_scale) {
      return 0.0;
    }

    const double _value;
    const scale _scale;
  };

}
