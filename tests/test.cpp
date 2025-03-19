#define CATCH_CONFIG_MAIN
#include <../include/catch.hpp>
#include "../include/compressor.hpp"

TEST_CASE("Test RLE encoding"){
  Compressor c;
  SECTION("Encoding"){
    REQUIRE(c.encode("AAAABBBCCDAA") == "4A3B2C1D2A");
  }
  SECTION("Long encoding"){

  }
  SECTION("Short encoding"){

  }
  SECTION("Only repetition"){

  }
  SECTION("No repetition"){
  
  }
  SECTION("Ints only"){

  }
  SECTION("Edge: empty input"){

  }
}

