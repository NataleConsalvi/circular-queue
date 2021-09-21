
#include "circular_queue.h"
#include "catch2/catch2.hpp"


using namespace Nats;

TEST_CASE("Test 1: capacity < 0 ", "[circular_queue]") {

    REQUIRE_THROWS_AS(Nats::CircularQueue(-1), std::invalid_argument);
}
