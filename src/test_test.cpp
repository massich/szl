#include <gtest/gtest.h>

TEST(foo,bar){std::cout << "hi" << std::endl;}

int main(int ac, char* av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}

