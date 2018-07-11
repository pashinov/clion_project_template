#include <gtest/gtest.h>

#include <swap.hpp>

TEST(BasicTestStr, SwapTest)
{
    std::string str1 = "One"; std::string str2 = "Two";
    cpp_project_template::swap(str1, str2);
    ASSERT_EQ(str1, "Two");
    ASSERT_EQ(str2, "One");
}

TEST(BasicTestInteger, SwapTest)
{
    std::int32_t val1 = 10; std::int32_t val2 = 20;
    cpp_project_template::swap(val1, val2);
    ASSERT_EQ(val1, 20);
    ASSERT_EQ(val2, 10);
}
