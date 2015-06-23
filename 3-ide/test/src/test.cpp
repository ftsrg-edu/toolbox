#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE AddTester
#include <boost/test/unit_test.hpp>

int add(int i, int j)
{
    return i + j;
}

BOOST_AUTO_TEST_CASE(testAdd1)
{
    BOOST_CHECK(add(2, 2) == 4);
}

BOOST_AUTO_TEST_CASE(testAdd2)
{
    BOOST_CHECK(add(2, 3) == 5);
}
