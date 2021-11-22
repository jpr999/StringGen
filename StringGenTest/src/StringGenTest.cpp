#include <gtest/gtest.h>
#include <include/stringgenlib.h>

// Demonstrate some basic assertions.
TEST(StringGenTest, Stringgen1)
{
    EXPECT_EQ(1, generate(1).length());
}    


TEST(StringGenTest, Stringgen20)
{
    EXPECT_EQ(20, generate(20).length());
}    

TEST(StringGenTest, Stringgen80)
{
    EXPECT_EQ(80, generate(80).length());
}    

TEST(StringGenTest, Stringgen42)
{
    EXPECT_EQ(42, generate(42).length());
}    

TEST(StringGenTest, Stringgen_11)
{
    EXPECT_EQ(0, generate(-11).length());
}    

TEST(StringGenTest, Stringgen100)
{
    EXPECT_EQ(100, generate(100).length());
}    

TEST(StringGenTest, Stringgen15)
{
    EXPECT_EQ(15, generate(15).length());
}    

TEST(StringLenTest, StringLen_cchar)
{
    EXPECT_EQ(10, utf8_strlen("Hello World"));
}    

