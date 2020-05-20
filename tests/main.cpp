#include <gtest/gtest.h>
#include "test_insertChild.h"
#include "simple_test.h"
#include "other_tests.h"
//#include "second_test.h"

#include "test_save.h"
int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
