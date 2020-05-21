#include <gtest/gtest.h>
#include "test_insertChild.h"
#include "simple_test.h"
#include "other_tests.h"
#include "test_deleteRow.h"
#include "test_save.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
