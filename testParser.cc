#include <gtest/gtest.h>

#include "Option.h"
#include "Parser.h"

using namespace op;
int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(OptionTest,OptionTestConstructorGood){
  Option opt = Option("help");
  std::vector<std::string> test = opt.getNames();
  EXPECT_EQ("help",test[0]);
}

TEST(OptionTestConstructorGoodWithManyNames,OptionTest){
  Option opt=Option("command");
  Option opt2=Option("help");
  std::vector<std::string> test = opt.getNames();
  EXPECT_EQ("command",test[0]);

  
}

TEST(OptionTestGetNames,OptionTest){

}

TEST(OptionTestGetNamesWithManyNames,OptionTest){

}

TEST(OptionTestGetValue,OptionTest){
  
}

TEST(OptionTestExpectValueTrue,OptionTest){

}

TEST(OptionTestExpectValueFalse,OptionTest){

}

TEST(OptionTestSetDefaultValue,OptionTest){

}

TEST(OptionTesthasValue,OptionTest){

}

TEST(OptionTestAddAlias,OptionTest){

}

TEST(OptionTestAddManyAlias,OptionTest){

}

TEST(OptionTestSetMandatoryTrue,OptionTest){

}

TEST(OptionTestSetMandatoryFalse,OptionTest){

}

TEST(OptionTestIsMandatoryTrue,OptionTest){

}

TEST(OptionTestIsMandatoryFalse,OptionTest){

}

TEST(OptionTestParsed,OptionTest){

}

TEST(OptionTestOperatorEQEQTrue,OptionTest){

}

TEST(OptionTestOperatorEQEQFalse,OptionTest){

}

TEST(OptionTestOperatorDiffTrue,OptionTest){

}

TEST(OptionTestOperatorDiffFalse,OptionTest){

}

TEST(OptionTestOperatorEQTrue,OptionTest){

}

TEST(OptionTestOperatorEQFalse,OptionTest){

}

TEST(OptionTestOperatorBoolTrue,OptionTest){

}

TEST(OptionTestOperatorBoolFalse,OptionTest){

}

