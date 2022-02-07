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

TEST(OptionTest,OptionTestConstructorGoodWithManyNames){
  
}

TEST(OptionTest,OptionTestGetNames){

}

TEST(OptionTest,OptionTestGetNamesWithManyNames){

}

TEST(OptionTest,OptionTestGetValue){
  
}

TEST(OptionTest,OptionTestExpectValueTrue){

}

TEST(OptionTest,OptionTestExpectValueFalse){

}

TEST(OptionTest,OptionTestSetDefaultValue){

}

TEST(OptionTest,OptionTesthasValue){

}

TEST(OptionTest,OptionTestAddAlias){

}

TEST(OptionTest,OptionTestAddManyAlias){

}

TEST(OptionTest,OptionTestSetMandatoryTrue){

}

TEST(OptionTest,OptionTestSetMandatoryFalse){

}

TEST(OptionTest,OptionTestIsMandatoryTrue){

}

TEST(OptionTest,OptionTestIsMandatoryFalse){

}

TEST(OptionTest,OptionTestParsed){

}

TEST(OptionTest,OptionTestOperatorEQEQTrue){

}

TEST(OptionTest,OptionTestOperatorEQEQFalse){

}

TEST(OptionTest,OptionTestOperatorDiffTrue){

}

TEST(OptionTest,OptionTestOperatorDiffFalse){

}

TEST(OptionTest,OptionTestOperatorEQTrue){

}

TEST(OptionTest,OptionTestOperatorEQFalse){

}

TEST(OptionTest,OptionTestOperatorEQEQTrue){

}

TEST(OptionTest,OptionTestOperatorBoolTrue){

}

TEST(OptionTest,OptionTestOperatorBoolFalse){

}

