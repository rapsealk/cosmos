#include <gtest/gtest.h>

#include <cfloat>

TEST(InfiniteTestSuite, InfiniteDouble)
{
    double inf = std::numeric_limits<double>::infinity();

    ASSERT_TRUE(inf > DBL_MAX);
    ASSERT_FALSE(inf < DBL_MAX);
    ASSERT_FALSE(inf == DBL_MAX);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}