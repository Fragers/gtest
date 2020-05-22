#include <gtest/gtest.h>
#include "test_insertChild.h"
#include "simple_test.h"
#include "other_tests.h"
#include "test_deleteRow.h"
#include "test_save.h"

int main(int argc, char *argv[])
{

        QApplication a(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    a.exit(0);
    return RUN_ALL_TESTS();
}
