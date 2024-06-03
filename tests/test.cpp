// Copyright (2024) ultralapse


#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(theone) {
    BOOST_CHECK_EQUAL(1, 1);
}
