#include <gtest/gtest.h>
#include "converter.hpp"
#include "validator.hpp"

TEST(ConverterTest, CstringToDouble) {
    EXPECT_DOUBLE_EQ(Converter::cstringToDouble("123.456"), 123.456);
    EXPECT_DOUBLE_EQ(Converter::cstringToDouble("-123.456"), -123.456);
    EXPECT_DOUBLE_EQ(Converter::cstringToDouble("0.0"), 0.0);
    EXPECT_DOUBLE_EQ(Converter::cstringToDouble("999999.999"), 999999.999);
    EXPECT_DOUBLE_EQ(Converter::cstringToDouble("-0.000001"), -0.000001);
}

TEST(ConverterTest, HexToDouble) {
    EXPECT_DOUBLE_EQ(Converter::hexToDouble("0x1A"), 26.0);
    EXPECT_DOUBLE_EQ(Converter::hexToDouble("0xF.8"), 15.5);
    EXPECT_DOUBLE_EQ(Converter::hexToDouble("0x0"), 0.0);
    EXPECT_DOUBLE_EQ(Converter::hexToDouble("0xA.BC"), 10.734375);
}

TEST(ConverterTest, DoubleToCstring) {
    char buffer[100];

    Converter::doubleToCstring(123.456, buffer, 3);
    EXPECT_STREQ(buffer, "123.456");

    Converter::doubleToCstring(-123.456, buffer, 3);
    EXPECT_STREQ(buffer, "-123.456");

    Converter::doubleToCstring(0.0, buffer, 6);
    EXPECT_STREQ(buffer, "0.000000");

    Converter::doubleToCstring(999999.99, buffer, 2);
    EXPECT_STREQ(buffer, "999999.99");

    Converter::doubleToCstring(-0.000001, buffer, 6);
    EXPECT_STREQ(buffer, "-0.000001");
}

TEST(ValidatorTest, IsDecimal) {
    EXPECT_TRUE(Validator::isDecimal("123.456"));
    EXPECT_TRUE(Validator::isDecimal("-123.456"));
    EXPECT_TRUE(Validator::isDecimal("0.0"));
    EXPECT_FALSE(Validator::isDecimal("123..456"));
    EXPECT_FALSE(Validator::isDecimal("abc.456"));
    EXPECT_FALSE(Validator::isDecimal(""));
}

TEST(ValidatorTest, IsHexadecimal) {
    EXPECT_TRUE(Validator::isHexadecimal("0x1A"));
    EXPECT_TRUE(Validator::isHexadecimal("0xF.8"));
    EXPECT_TRUE(Validator::isHexadecimal("0xA"));
    EXPECT_FALSE(Validator::isHexadecimal("1A"));
    EXPECT_FALSE(Validator::isHexadecimal("0x"));
    EXPECT_FALSE(Validator::isHexadecimal("0xZ"));
}

TEST(ValidatorTest, IsValidNumber) {
    EXPECT_TRUE(Validator::isValidNumber("123.456"));
    EXPECT_TRUE(Validator::isValidNumber("-123.456"));
    EXPECT_TRUE(Validator::isValidNumber("0x1A"));
    EXPECT_TRUE(Validator::isValidNumber("0xF.8"));
    EXPECT_FALSE(Validator::isValidNumber("abc"));
    EXPECT_FALSE(Validator::isValidNumber("123..456"));
    EXPECT_FALSE(Validator::isValidNumber("0xZ"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
