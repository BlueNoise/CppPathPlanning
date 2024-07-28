#include <gtest/gtest.h>

int addTwoNumbers(int v1, int v2)
{
    return v1 + v2;
}

TEST(BasicFunctionTest, AddTwoNumbers)
{
    EXPECT_EQ(addTwoNumbers(2, 3), 5);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}