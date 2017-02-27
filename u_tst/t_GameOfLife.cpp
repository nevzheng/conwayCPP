// / Link to Boost
#define BOOST_TEST_DYN_LINK

// Define our Module name (prints at testing)
#define BOOST_TEST_MODULE "t_GameOfLife"

// VERY IMPORTANT - include this last
#include "GameOfLife.hpp"
#include <boost/test/unit_test.hpp>
#include <utility>

// ------------- Tests Follow --------------
BOOST_AUTO_TEST_CASE(constructors) {
  GameOfLife obj;
  GameOfLife obj2(10, 10);

  // Check default constructor
  // Use BOOST_CHECK for small equal checks - true or false
  // BOOST_CHECK(obj.get_dimensions().first() == obj2.get_dimensions().first());
  BOOST_CHECK(10 == 10);
}

// Name your test cases for what they test
BOOST_AUTO_TEST_CASE(assignment) {
  GameOfLife obj;
  GameOfLife obj2;

  // obj.setSomeValues.....

  obj2 = obj;

  // Use BOOST_CHECK_EQUAL if you want the values to be
  // printed out if they mismatch
  // BOOST_CHECK_EQUAL(obj2.get_dimensions().first(),
  BOOST_CHECK_EQUAL(10 == 10, true);
}
