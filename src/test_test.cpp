#include <gtest/gtest.h>
#include "common/szl.h"
#include "tests/unit/szl_operation.h"
//#include "tests/integration/szl_thread.h"

int main(int ac, char* av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}

