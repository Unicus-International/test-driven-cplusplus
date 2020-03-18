#include "movement_02.hpp"

namespace movement_02 {

  struct energy {
    enum struct scale {
      kJ,
      kcal,
    };

    constexpr energy(double v, scale s) : _value { v }, _scale { s } { }

    constexpr energy convert(scale target_scale) {
      return { 0, scale::kcal };
    }

    constexpr double value(scale target_scale) {
      return 0;
    }

    const double _value;
    const scale _scale;
  };

}
