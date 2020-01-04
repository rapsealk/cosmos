#include <gtest/gtest.h>

#define FUNCTION_RETURN_CODE 200

int function() { return FUNCTION_RETURN_CODE; }

int (*function_)();

TEST(FunctionAsParameterTestSuite, FunctionAsParameter)
{
    function_ = function;
    ASSERT_EQ(function_(), FUNCTION_RETURN_CODE);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}