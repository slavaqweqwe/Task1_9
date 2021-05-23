
#include <gtest/gtest.h>
#include "task.h"
using namespace testspace;
TEST(task_lib_test, Hamming)
{
    Hamming74 D;
    std::vector<uint8_t> in = { 1, 2, 3, 4 };
    std::vector<uint8_t> teor = { 11, 128, 5, 208, 1, 156, 0 };
    std::vector<uint8_t> En = D.Encode(in);
    ASSERT_EQ(En, teor);
}
TEST(task_lib_test, Hamming2)
{
    Hamming74 Ham;
    ICoder* pICoder = &Ham;
    std::vector<uint8_t> in = { 1, 2, 3, 4 };
    std::vector<uint8_t> teor = { 11, 128, 5, 208, 1, 156, 0 };
    std::vector<uint8_t> En = pICoder->Encode(in);
    ASSERT_EQ(En, teor);
}
TEST(task_lib_test, Diff)
{
    DiffCode D;
    std::vector<uint8_t> in = { 1, 2, 3, 4 };
    std::vector<uint8_t> teor = { 255, 1, 1, 252 };
    std::vector<uint8_t> En = D.Encode(in);
    ASSERT_EQ(En, teor);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}