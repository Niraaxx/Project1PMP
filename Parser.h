#ifndef OP_PARSER_H_
#define OP_PARSER_H_

#include <iostream>
#include <vector>
#include <string.h>
#include <regex.h>

#include "Option.h"

namespace op {
  class Parser {
  public:
    void parseCommandLine(int argc, const char* const argv[]);
    void printHelp(std::ostream& stream = std::cout) const;
    std::size_t getPositionalArgumentCount() const;

    Option& operator()(const std::string& name);
    const std::string& operator[](std::size_t i) const;

  private:
    Option& Parser::parser(const std::string& name);
    Parser::Parser();
    std::vector<Option> options;
    std::vector<std::string> argPositionnels;
  };
}

#endif // OP_PARSER_H_
