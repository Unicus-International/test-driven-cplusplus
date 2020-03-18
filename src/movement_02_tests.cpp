#include "movement_02.cpp"

#include <cmath>

namespace movement_02 {

  namespace {

    constexpr double ε = 1.0e-5;

  }

  const std::vector<lest::test> basic_tests {
    { CASE("kilocalories => kilojoules") {
        EXPECT( std::abs(energy(  0.0, energy::scale::kcal ).value( energy::scale::kJ ) -  0.0  ) < ε );
        EXPECT( std::abs(energy(  1.0, energy::scale::kcal ).value( energy::scale::kJ ) -  4.184) < ε );
        EXPECT( std::abs(energy( 10.0, energy::scale::kcal ).value( energy::scale::kJ ) - 41.84 ) < ε );
    } },
    { CASE("kilojoules => kilocalories") {
        EXPECT( std::abs(energy(  0.0, energy::scale::kJ ).value( energy::scale::kcal ) -  0.0  ) < ε );
        EXPECT( std::abs(energy(  1.0, energy::scale::kJ ).value( energy::scale::kcal ) -  0.239) < ε );
        EXPECT( std::abs(energy( 10.0, energy::scale::kJ ).value( energy::scale::kcal ) -  2.39 ) < ε );
    } },
  } ;

  const std::vector<lest::test> extra_tests {
    { CASE("Lucas numbers") {
      EXPECT( 1 == 1 );
    } },
  } ;

}
