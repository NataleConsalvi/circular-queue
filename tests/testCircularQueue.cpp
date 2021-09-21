
#include "circular_queue.h"
#include "catch2/catch2.hpp"


using namespace Nats;

TEST_CASE("Test 1: capacity < 0 ", "[circular_queue]") {

    REQUIRE_THROWS_AS(Nats::CircularQueue(-1), std::invalid_argument);
}

TEST_CASE("Test 2: get_capacity ", "[circular_queue]") {

    Nats::CircularQueue q(5);
    int cap = q.get_capacity();
    REQUIRE(cap == 5);
}

TEST_CASE("Test 3: get_size ", "[circular_queue]") {

    Nats::CircularQueue q(5);
    int cap = q.get_size();
    REQUIRE(cap == 0);

    q.enqueue('a');
    cap = q.get_size();
    REQUIRE(cap == 1);
}

TEST_CASE("Test 4: isEmpty ", "[circular_queue]") {

    Nats::CircularQueue q(5);
    bool t = q.isEmpty();
    REQUIRE(t == true);

    q.enqueue('a');
    t = q.isEmpty();
    REQUIRE(t == false);
}

TEST_CASE("Test 5: top ", "[circular_queue]") {

    Nats::CircularQueue q(5);
    REQUIRE_THROWS_AS(q.top(), std::runtime_error);

    q.enqueue('a');
    char c = q.top();
    REQUIRE(c == 'a');

    q.enqueue('Z');
    q.dequeue();
    c = q.top();
    REQUIRE(c == 'Z');
}

TEST_CASE("Test 6: enqueue ", "[circular_queue]") {

    Nats::CircularQueue q(2);

    q.enqueue('a');
    char c = q.top();
    REQUIRE(c == 'a');

    q.enqueue('b');
    int j = q.get_size();
    REQUIRE(j == 2);

    REQUIRE_THROWS_AS(q.enqueue('d'), std::runtime_error);
}

TEST_CASE("Test 7: dequeue ", "[circular_queue]") {

    Nats::CircularQueue q(2);

    q.enqueue('a');
    char c = q.dequeue();
    REQUIRE(c == 'a');
    int j = q.get_size();
    REQUIRE(j == 0);

    REQUIRE_THROWS_AS(q.dequeue(), std::runtime_error);
}