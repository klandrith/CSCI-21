#define CATCH_CONFIG_MAIN
#include "catch.hpp"

int divide(int numerator, int denominator) {
  if (denominator == 0) {
    return 0;
  }
  return numerator / denominator;
}

TEST_CASE("my first unit test") {
  CHECK(divide(1, 1) == 1);
  CHECK(divide(0, 1) == 0);
  CHECK(divide(1, 0) == 0); //divide by 0 crashes

  CHECK(divide(10, 5) == 2);
  CHECK(divide(5, 10) == 0);
}
