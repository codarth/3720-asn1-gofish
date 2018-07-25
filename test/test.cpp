#include "gtest/gtest.h"
#include "gmock/gmock.h"

int main(int argc, char** argv)
{
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();

    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();

}

