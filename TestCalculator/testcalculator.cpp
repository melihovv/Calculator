#include <gtest\gtest.h>
#include "../Calculator/driver.h"

class TestCalculator : public ::testing::Test
{
protected:
    melihovv::calculator::Driver driver;
};

TEST_F(TestCalculator, SomeExamples)
{
    std::istringstream iss1("-2+2+3");
    driver.switchInputStream(&iss1);
    ASSERT_EQ(3, driver.parse());

    std::istringstream iss2("-2");
    driver.switchInputStream(&iss2);
    ASSERT_EQ(-2, driver.parse());

    std::istringstream iss3("(1+2)*3");
    driver.switchInputStream(&iss3);
    ASSERT_EQ(9, driver.parse());

    std::istringstream iss4("2^4");
    driver.switchInputStream(&iss4);
    ASSERT_EQ(16, driver.parse());
}