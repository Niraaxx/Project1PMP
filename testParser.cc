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
  std::vector<std::string> test2 = opt2.getNames();
  EXPECT_EQ("command",test[0]);
  EXPECT_EQ("help",test2[0]);

  
}

TEST(OptionTestGetNames,OptionTest){
}

TEST(OptionTestGetNamesWithManyNames,OptionTest){
  


}

TEST(OptionTestGetValue,OptionTest){
  Option opt=Option("command");
  opt.setDefaultValue("c");
  std::string test = opt.getValue();
  EXPECT_EQ("c",test);
  
}
TEST(OptionTestGetNoValue,OptionTest){
  // Option opt=Option("command");
  // std::string test = opt.getValue();
  //EXPECT_EQ(std::runtime_error,test);
  
}

TEST(OptionTestExpectValueTrue,OptionTest){
  // Option opt=Option("command");
  // opt.operator=("c");
  // EXPECT_TRUE(opt.expectValue());

}

TEST(OptionTestExpectValueFalse,OptionTest){
  Option opt=Option("command");
  EXPECT_FALSE(opt.expectValue());

}

TEST(OptionTestSetDefaultValue,OptionTest){
  Option opt=Option("command");
  opt.setDefaultValue("c");
  std::string test=opt.getValue();
  EXPECT_EQ("c",test);
}

TEST(OptionTesthasValue,OptionTest){
  Option opt=Option("command");
  opt.setDefaultValue("c");
  EXPECT_TRUE(opt.expectValue());

}

TEST(OptionTestAddAlias,OptionTest){
  Option opt = Option("help");
  opt.addAlias("-h");
  std::vector<std::string> test = opt.getNames();
  EXPECT_EQ("help",test[0]);
  EXPECT_EQ("-h",test[1]);

}

TEST(OptionTestAddManyAlias,OptionTest){
  Option opt = Option("help");
  opt.addAlias("-h");
  opt.addAlias("--help");
  std::vector<std::string> test = opt.getNames();

  EXPECT_EQ("help",test[0]);
  EXPECT_EQ("-h",test[1]);
  EXPECT_EQ("--help",test[2]);

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

