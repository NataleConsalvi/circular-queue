
#include "circular_queue.h"
#include "catch2/catch2.hpp"


using namespace Nats;

TEST_CASE("Test 1: capacity < 0 ", "[circular_queue]") {

    REQUIRE_THROWS_AS(Nats::CircularQueue(-1), std::invalid_argument);
}

/*
TEST_CASE("square_root >= 0 should give positive result ", "[cxx_examples]") {
                
    REQUIRE(square_root(4.0) == Approx(2.0));


    // expects std::invalid_argument exception, if it is not thrown test fails        
    REQUIRE_THROWS_AS( square_root(-1.0), std::invalid_argument);

    REQUIRE(square_root(0.0) == Approx(0.0));
}
*/