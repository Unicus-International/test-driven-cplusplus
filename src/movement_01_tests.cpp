#include "movement_01.cpp"

namespace movement_01 {

  const std::vector<lest::test> basic_tests {
    { CASE("Fibonacci numbers") {
      EXPECT( fibonacci_number( 0) ==                   0 );
      EXPECT( fibonacci_number( 1) ==                   1 );
      EXPECT( fibonacci_number( 2) ==                   1 );
      EXPECT( fibonacci_number( 3) ==                   2 );
      EXPECT( fibonacci_number( 4) ==                   3 );
      EXPECT( fibonacci_number( 5) ==                   5 );
      EXPECT( fibonacci_number( 6) ==                   8 );
      EXPECT( fibonacci_number( 7) ==                  13 );
      EXPECT( fibonacci_number( 8) ==                  21 );
      EXPECT( fibonacci_number(92) == 7540113804746346429 );
    } },
  } ;

  const std::vector<lest::test> extra_tests {
    { CASE("Lucas numbers") {
      EXPECT( lucas_number( 0)     ==                   2 );
      EXPECT( lucas_number( 1)     ==                   1 );
      EXPECT( lucas_number( 2)     ==                   3 );
      EXPECT( lucas_number( 3)     ==                   4 );
      EXPECT( lucas_number( 4)     ==                   7 );
      EXPECT( lucas_number( 5)     ==                  11 );
      EXPECT( lucas_number( 6)     ==                  18 );
      EXPECT( lucas_number( 7)     ==                  29 );
      EXPECT( lucas_number( 8)     ==                  47 );
      EXPECT( lucas_number(90)     == 6440026026380244498 );
    } },
  } ;

}
