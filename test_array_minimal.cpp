#define BOOST_TEST_MODULE multidimensional_array_test

#ifdef HEADER_ONLY
#   include <boost/test/included/unit_test.hpp>
#else
#   include <boost/test/unit_test.hpp>
#endif


#include "multidimensional/array.hpp"

BOOST_AUTO_TEST_SUITE( test_suite1 )

BOOST_AUTO_TEST_CASE(test_basics)
{
    util::MultiDimArray<unsigned int, 3, 3, 3>::type ints;

    ints[1][1][1] = 111;//    assert(ints[1][1][1] == 111);
    ints[1][2][3] = 123;
    ints[2][2][2] = 222;
    ints[4][4][4] = 444;
    ints[8][8][8] = 888;


    BOOST_TEST_MESSAGE("Testing correct value(s)...");
    BOOST_REQUIRE_EQUAL( ints[1][1][1], 111 );

    BOOST_TEST_MESSAGE("Test out-of-range...");
    BOOST_REQUIRE_THROW( ints.at(3).at(3).at(3);, std::out_of_range );

    BOOST_TEST_MESSAGE("Test out-of-range not detected...");
    BOOST_REQUIRE_NO_THROW( ints[3][3][3] );

}

BOOST_AUTO_TEST_SUITE_END()
