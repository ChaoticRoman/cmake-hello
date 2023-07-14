#include <gtest/gtest.h>

#include "low/low.h"

TEST(LowTestSuite, MessageTest) {
  std::string result = message();
  EXPECT_EQ(result, "Hello!");
}
