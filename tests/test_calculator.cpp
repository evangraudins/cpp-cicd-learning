#include <gtest/gtest.h>

#include "math/calculator.h"

class CalculatorTest : public ::testing::Test {
protected:
    math::Calculator calc;
};

TEST_F(CalculatorTest, Add) {
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(-1, 1), 0);
    EXPECT_EQ(calc.add(0, 0), 0);
}

TEST_F(CalculatorTest, Subtract) {
    EXPECT_EQ(calc.subtract(10, 3), 7);
    EXPECT_EQ(calc.subtract(0, 5), -5);
}

TEST_F(CalculatorTest, Multiply) {
    EXPECT_EQ(calc.multiply(4, 5), 20);
    EXPECT_EQ(calc.multiply(-2, 3), -6);
    EXPECT_EQ(calc.multiply(0, 100), 0);
}

TEST_F(CalculatorTest, Divide) {
    EXPECT_DOUBLE_EQ(calc.divide(10.0, 2.0), 5.0);
    EXPECT_NEAR(calc.divide(22.0, 7.0), 3.14285, 0.0001);
}

TEST_F(CalculatorTest, DivideByZeroThrows) {
    EXPECT_THROW(calc.divide(1.0, 0.0), std::invalid_argument);
}
