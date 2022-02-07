#include <gtest/gtest.h>

#include "Option.h"
#include "Parser.h"

using namespace op;
int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(OptionTest,OptionTestConstructorGood){
  Option opt = opt;
  std::vector<std::string> test = opt.getNames();
  EXPECT_EQ("help",test[0]);
}
