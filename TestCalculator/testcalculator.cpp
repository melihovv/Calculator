#include <gtest\gtest.h>
#include "../Calculator/driver.h"

class TestCalculator : public ::testing::Test
{
protected:
    melihovv::calculator::Driver driver_;
};

TEST_F(TestCalculator, SomeExamples)
{
    std::istringstream iss1("-2+2+3");
    driver_.switchInputStream(&iss1);
    ASSERT_EQ(3, driver_.parse());

    std::istringstream iss2("-2");
    driver_.switchInputStream(&iss2);
    ASSERT_EQ(-2, driver_.parse());

    std::istringstream iss3("(1+2)*3");
    driver_.switchInputStream(&iss3);
    ASSERT_EQ(9, driver_.parse());

    std::istringstream iss4("2^4");
    driver_.switchInputStream(&iss4);
    ASSERT_EQ(16, driver_.parse());
}