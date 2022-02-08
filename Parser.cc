#include "Parser.h"

#include <algorithm>
#include <stdexcept>

namespace op {
  void Parser::parseCommandLine(int argc, const char* const argv[]) {
    /*for(int i =0; i<=argc;i++){
      if((argv[i+1][0] == "-" || argv[i+1][1] == "-"){
        options.push_back(argv[i+1]);
      }else{
        argPositionnels.push_back(argv[i+1]);
      }
    }*/
  }

  void Parser::printHelp(std::ostream& stream) const {
    stream << "Usage:\n";
    /*for(int i =0; i< argc ;i++){
      stream << "\t--" << argv[i+1] << "\n"
    }*/

    stream << "\t --help|-h\n";
  }

  std::size_t Parser::getPositionalArgumentCount() const {
    return argPositionnels.size();
  }

  Option& Parser::operator()(const std::string& name) {
    auto result = std::find(begin(options),end(options),name);
    if(result != std::end(options)){
      return *result;
    }
  }

  const std::string& Parser::operator[](std::size_t i) const {
    return argPositionnels.at(i);
  }
}
