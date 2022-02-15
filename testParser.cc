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
  Option opt=Option("command");
  Option opt2=Option("help");
  std::vector<std::string> test = opt.getNames();
  std::vector<std::string> test2 = opt2.getNames();
  EXPECT_EQ("command",test[0]);
  EXPECT_EQ("help",test2[0]);

  
}

TEST(OptionTest,OptionTestGetNames){
  Option opt=Option("command");
  opt.addAlias("cmd");
  std::vector<std::string> test = opt.getNames();
  EXPECT_EQ("command",test[0]);
  EXPECT_EQ("cmd",test[1]);
}

TEST(OptionTest,OptionTestGetNamesWithManyNames){
  Option opt=Option("command");
  opt.addAlias("cmd");
  opt.addAlias("c");
  std::vector<std::string> test = opt.getNames();
  EXPECT_EQ("command",test[0]);
  EXPECT_EQ("cmd",test[1]);
  EXPECT_EQ("c",test[2]);
}
TEST(OptionTest,OptionTestGetNamesError){
  Option opt=Option("command");
  opt.addAlias("cmd");
  opt.addAlias("c");
  std::vector<std::string> test = opt.getNames();
  EXPECT_NE("h",test[1]);
  EXPECT_NE("c",test[0]);
}

TEST(OptionTest,OptionTestGetValue){
  Option opt=Option("command");
  opt.setDefaultValue("c");
  std::string test = opt.getValue();
  EXPECT_EQ("c",test);
  EXPECT_NE("v",test);
  
}
TEST(OptionTest,OptionTestGetNoValue){
  Option opt=Option("command");
  EXPECT_THROW({opt.getValue();},std::runtime_error);
}
TEST(OptionTest,OptionTestGetNoValue2){
  Option opt=Option("command");
  opt.setDefaultValue("");
  EXPECT_THROW({opt.getValue();},std::runtime_error);
}

TEST(OptionTest,OptionTestSetDefaultValue){
  Option opt=Option("command");
  opt.setDefaultValue("c");
  std::string test=opt.getValue();
  EXPECT_EQ("c",test);
}

TEST(OptionTest,OptionTesthasValue){
  Option opt=Option("command");
  opt.setDefaultValue("c");
  EXPECT_TRUE(opt.expectValue());

}

TEST(OptionTest,OptionTestAddAlias){
  Option opt = Option("help");
  opt.addAlias("h");
  std::vector<std::string> test = opt.getNames();
  EXPECT_EQ("help",test[0]);
  EXPECT_EQ("h",test[1]);

}

TEST(OptionTest,OptionTestAddManyAlias){
  Option opt = Option("help");
  opt.addAlias("h");
  opt.addAlias("help_need");
  std::vector<std::string> test = opt.getNames();

  EXPECT_EQ("help",test[0]);
  EXPECT_EQ("h",test[1]);
  EXPECT_EQ("help_need",test[2]);

}

TEST(OptionTest,OptionTestSetMandatoryTrue){
  Option opt=Option("command");
  opt.setDefaultValue("c");
  opt.setMandatory();
  EXPECT_TRUE(opt.isMandatory());

}

TEST(OptionTest,OptionTestSetMandatoryFalse){
  Option opt=Option("command");
  opt.setDefaultValue("c");
  EXPECT_FALSE(opt.isMandatory());

}

TEST(OptionTest,OptionTestIsMandatoryTrue){
  Option opt=Option("command");
  opt.setDefaultValue("c");
  opt.setMandatory();
  EXPECT_TRUE(opt.isMandatory());
}

TEST(OptionTest,OptionTestIsMandatoryFalse){
  Option opt=Option("command");
  opt.setDefaultValue("c");
  EXPECT_FALSE(opt.isMandatory());
}

TEST(OptionTest,OptionTestParsed){
  Option opt=Option("command");
  opt.parsed();
  EXPECT_TRUE(opt.operator bool());

}
TEST(OptionTest,OptionTestNotParsed){
  Option opt=Option("command");
  EXPECT_FALSE(opt.operator bool());

}

TEST(OptionTest,OptionTestOperatorEQEQTrue){
  Option opt=Option("command");
  EXPECT_TRUE(opt.operator==("command"));
}

TEST(OptionTest,OptionTestOperatorEQEQTrueAlias){
  Option opt=Option("command");
  opt.addAlias("cmd");
  EXPECT_TRUE(opt.operator==("cmd"));
}

 
TEST(OptionTest,OptionTestOperatorEQEQFalse){
  Option opt=Option("commande");
  EXPECT_FALSE(opt.operator==("command"));
}

TEST(OptionTest,OptionTestOperatorEQEQFalseAlias){
  Option opt=Option("command");
  opt.addAlias("cmde");
  EXPECT_FALSE(opt.operator==("cmd"));
}


TEST(OptionTest,OptionTestOperatorDiffTrue){
  Option opt=Option("command");
  EXPECT_TRUE(opt.operator!=("cmd"));
  
}

TEST(OptionTest,OptionTestOperatorDiffFalse){
  Option opt=Option("command");
  EXPECT_FALSE(opt.operator!=("command")); 
}
TEST(OptionTest,OptionTestOperatorDiffTrueAlias){
  Option opt=Option("command");
  opt.addAlias("cmd");
  EXPECT_TRUE(opt.operator!=("cmde"));
  
}

TEST(OptionTest,OptionTestOperatorDiffFalseAlias){
  Option opt=Option("command");
  opt.addAlias("cmd");
  EXPECT_FALSE(opt.operator!=("cmd")); 
}

TEST(OptionTest,OptionTestOperatorEQTrue){
  Option opt=Option("command");
  opt.setDefaultValue("c");
  opt.operator=("d");
  EXPECT_EQ("d",opt.getValue());
  opt.operator=("f");
  EXPECT_EQ("f",opt.getValue());
}

TEST(OptionTest,OptionTestOperatorEQFalse){
  Option opt=Option("command");
  opt.setDefaultValue("c");
  opt.operator=("d");
  EXPECT_NE("c",opt.getValue());

}

TEST(OptionTest,OptionTestOperatorBoolTrue){
  Option opt=Option("command");
  opt.parsed();
  EXPECT_TRUE(opt.operator bool());

}

TEST(OptionTest,OptionTestOperatorBoolFalse){
  Option opt=Option("command");
  EXPECT_FALSE(opt.operator bool());
}


/*PARSER TEST*/ 



TEST(ParserTest,ParserTestContructorGoodByAlias){
  Parser p;
  EXPECT_EQ(p("h").getNames()[0], "help");
  EXPECT_EQ(p("h").getNames()[1], "h");
}

TEST(ParserTest,ParserTestContructorGood){
  Parser p;
  EXPECT_EQ(p("help").getNames()[0], "help");
  EXPECT_EQ(p("help").getNames()[1], "h");
}

TEST(ParserTest,ParserTestOperatorParWithOutAliasName){
  Parser p;
  p("OPTION");
  EXPECT_EQ(p("OPTION").getNames()[0], "OPTION");
  EXPECT_EQ(p("OPTION").getNames().size(),1);
}

TEST(ParserTest,ParserTestOperatorParWithOutAliasSize){
  Parser p;
  p("OPTION");
  EXPECT_EQ(p("OPTION").getNames().size(),1);
}

TEST(ParserTest,ParserTestOperatorParWithAliasName){
  Parser p;
  p("OPTION").addAlias("SUPER");

  EXPECT_EQ(p("OPTION").getNames()[0], "OPTION");
  EXPECT_EQ(p("OPTION").getNames()[1], "SUPER");
  EXPECT_EQ(p("SUPER").getNames()[0], "OPTION");
  EXPECT_EQ(p("SUPER").getNames()[1], "SUPER");
}

TEST(ParserTest,ParserTestOperatorParWithAliasSize){
  Parser p;
  p("OPTION").addAlias("SUPER");

  EXPECT_EQ(p("OPTION").getNames().size(),2);
  EXPECT_EQ(p("SUPER").getNames().size(),2);
}

TEST(ParserTest,ParserTestPrintHelpOnly){
  Parser p;
  p.printHelp(std::cout);
}

TEST(ParserTest,ParserTestPrintHelpWithOneOption){
  Parser p;
  p("OneOPTION");
  p.printHelp(std::cout);
}

TEST(ParserTest,ParserTestPrintHelpWithManyOptions){
  Parser p;
  p("OneOPTION");
  p("TwoOPTION");
  p("ThreeOPTION");
  p.printHelp(std::cout);
}

TEST(ParserTest,ParserTestPrintHelpWithManyOptionsAndOneAlias){
  Parser p;
  p("OneOPTION");
  p("OneOPTION").addAlias("p");
  p("TwoOPTION");
  p("ThreeOPTION");
  p.printHelp(std::cout);
}

TEST(ParserTest,ParserTestPrintHelpWithManyOptionsAndManyAlias){
  Parser p;
  p("OneOPTION");
  p("OneOPTION").addAlias("p");
  p("OneOPTION").addAlias("o");
  p("TwoOPTION");
  p("ThreeOPTION");
  p.printHelp(std::cout);
}

/*TEST(ParserTest,ParserTestGetPositionalArgumentCountGood){
  const char* argv[] = {
  (char *)"command ",
  (char *)"--option ",
  (char *)"bar ",
  (char *)"pos2 "
  };
  Parser p;
  p("option").hasValue().setDefaultValue("foo");
  p.parseCommandLine(sizeof(argv),argv);
  auto count = p.getPositionalArgumentCount();
  EXPECT_EQ(count,1);
}

TEST(ParserTest,ParserTestGetPositionalArgumentCountManyGood){
  const char* argv[] = {
  (char *)"command ",
  (char *)"--option ",
  (char *)"bar ",
  (char *)"-a",
  (char *)"pos1",
  (char *)"pos2 "
  };
  Parser p;
  p("option").hasValue().setDefaultValue("foo");
  p("alias").addAlias("a");
  p.parseCommandLine(sizeof(argv),argv);
  auto count = p.getPositionalArgumentCount();
  EXPECT_EQ(count,2);
}

TEST(ParserTest,ParserTestGetPositionalArgumentCountNotGood){
  const char* argv[] = {
  (char *)"command ",
  (char *)"--option ",
  (char *)"bar ",
  (char *)"-a",
  (char *)"pos1",
  (char *)"pos2 "
  };
  Parser p;
  p("option").hasValue().setDefaultValue("foo");
  p("alias").addAlias("a");
  p.parseCommandLine(sizeof(argv),argv);
  auto count = p.getPositionalArgumentCount();
  EXPECT_EQ(count,1);
}

TEST(ParserTest,ParserTestOperator2){

}*/
