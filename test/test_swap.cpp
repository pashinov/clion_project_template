#include <gtest/gtest.h>

#include <swap/swap.hpp>

TEST(BasicTest, SwapTest) {
    std::string str1 = "Hello"; std::string str2 = "World";
    cpp_project_template::swap(str1, str2);
    ASSERT_EQ(str1, "World");
    ASSERT_EQ(str2, "Hello");
}
