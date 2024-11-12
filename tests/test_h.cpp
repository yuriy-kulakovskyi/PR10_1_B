#include <gtest/gtest.h>
#include "../include/functions.h"
#include "../include/structures.h"

TEST(CountTest, HandleCount) {
  const int N = 1;
  Student s[N] = {{"Кулаковський", 1, INFORMATIONAL_SYSTEMS_AND_TECHNOLOGIES, 5, 5, 5}};
  EXPECT_EQ(3, Count(s, N));
}