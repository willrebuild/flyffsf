
//  Copyright Daniel James 2006. Use, modification, and distribution are
//  subject to the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// This checks that template code implemented using hash_fwd will work.

#include "./hash_fwd_test.hpp"

#include <boost/detail/lightweight_test.hpp>

#if defined(TEST_EXTENSIONS) && !defined(TEST_STD_INCLUDES)

#include <boost/functional/hash.hpp>
#include <string>

void fwd_test1()
{
    test::test_type1<int> x(5);
    test::test_type1<std::string> y("Test");

    HASH_NAMESPACE::hash<int> hasher_int;
    HASH_NAMESPACE::hash<std::string> hasher_string;
    HASH_NAMESPACE::hash<test::test_type1<int> > hasher_test_int;
    HASH_NAMESPACE::hash<test::test_type1<std::string> > hasher_test_string;

    BOOST_TEST(hasher_int(5) == hasher_test_int(x));
    BOOST_TEST(hasher_string("Test") == hasher_test_string(y));
}

void fwd_test2()
{
    test::test_type2<int> x(5, 10);
    test::test_type2<std::string> y("Test1", "Test2");

    std::size_t seed1 = 0;
    HASH_NAMESPACE::hash_combine(seed1, 5);
    HASH_NAMESPACE::hash_combine(seed1, 10);

    std::size_t seed2 = 0;
    HASH_NAMESPACE::hash_combine(seed2, std::string("Test1"));
    HASH_NAMESPACE::hash_combine(seed2, std::string("Test2"));

    HASH_NAMESPACE::hash<test::test_type2<int> > hasher_test_int;
    HASH_NAMESPACE::hash<test::test_type2<std::string> > hasher_test_string;

    BOOST_TEST(seed1 == hasher_test_int(x));
    BOOST_TEST(seed2 == hasher_test_string(y));
}

void fwd_test3()
{
    std::vector<int> values1;
    values1.push_back(10);
    values1.push_back(15);
    values1.push_back(20);
    values1.push_back(3);

    std::vector<std::string> values2;
    values2.push_back("Chico");
    values2.push_back("Groucho");
    values2.push_back("Harpo");
    values2.push_back("Gummo");
    values2.push_back("Zeppo");

    test::test_type3<int> x(values1.begin(), values1.end());
    test::test_type3<std::string> y(values2.begin(), values2.end());

    std::size_t seed1 = HASH_NAMESPACE::hash_range(values1.begin(), values1.end());
    HASH_NAMESPACE::hash_range(seed1, values1.begin(), values1.end());

    std::size_t seed2 = HASH_NAMESPACE::hash_range(values2.begin(), values2.end());
    HASH_NAMESPACE::hash_range(seed2, values2.begin(), values2.end());

    HASH_NAMESPACE::hash<test::test_type3<int> > hasher_test_int;
    HASH_NAMESPACE::hash<test::test_type3<std::string> > hasher_test_string;

    BOOST_TEST(seed1 == hasher_test_int(x));
    BOOST_TEST(seed2 == hasher_test_string(y));
}

#endif

int main()
{
#ifdef TEST_EXTENSIONS
    fwd_test1();
    fwd_test2();
    fwd_test3();
#endif
    return boost::report_errors();
}

