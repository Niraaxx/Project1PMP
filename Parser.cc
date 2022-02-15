#include "Parser.h"

#include <algorithm>
#include <stdexcept>

namespace op {

  Parser::Parser(){
    Option helpOpt = Option("help");
    helpOpt.addAlias("h");
    options.push_back(helpOpt);
  }

  void Parser::parseCommandLine(int argc, const char* const argv[]) {
    for(int i =1; i<=argc;i++){
      std::string opt = (std::string) argv[i];
      if((strcmp(&opt.at(0),"-") == 0) && (strcmp(&opt.at(1),"-") == 0)
      /*(strncmp(&argv[i][0],"-",1) == 0) || (strncmp(&argv[i][1],"-",1) == 0)*/){
        for(int j=0; j< options.size();j++){
          if(options[i].operator!=(opt.substr(opt.find("-")+2))){
            Option optObj = operator()(opt);
            if(optObj.expectValue()){
              optObj.operator=(argv[i+1]);
              i++;
            }
            optObj.parsed();
            options.push_back(opt);
          }else{
            throw std::runtime_error("Not an option");
          }
        }
      }else if((strcmp(&opt.at(0),"-") == 0)){
        for(int j=0; j< options.size();j++){
          if(options[i].operator!=(opt.substr(opt.find("-")+1))){
            Option optObj = operator()(opt);
            if(optObj.expectValue()){
              optObj.operator=(argv[i+1]);
              i++;
            }
            optObj.parsed();
            options.push_back(opt);
          }else{
            throw std::runtime_error("Not an option");
          }
        }
      }
      else{
        argPositionnels.push_back(opt);
      }
    }

    //Check if parsed
    for(int i = 0;i < options.size();i++){
      if(options[i].isMandatory() && !options[i].operator bool()){
        throw std::runtime_error("Option mandatory not parsed");
      }
    }
  }

  void Parser::printHelp(std::ostream& stream) const {
    stream << "Usage:\n";
    for(int i =1; i< options.size() ;i++){
      stream << "\t--" << options[i].getNames().at(0);
      if(options[i].getNames().size()>1){
        for(int j =1; j <options[i].getNames().size();j++){
           stream <<"|-"<< options[i].getNames().at(j);
        }
      }
      stream << "\n";
    }
    stream << "\t--"<< options[0].getNames().at(0) <<" |-"<< options[0].getNames().at(1) <<"\n";
  }

  std::size_t Parser::getPositionalArgumentCount() const {
    return argPositionnels.size();
  }

  Option& Parser::operator()(const std::string& name) {
    for(auto &option : this->options){
      if(option == name){
        return option;
      }
    }
    options.emplace_back(name);
    return options.back();
  }

  const std::string& Parser::operator[](std::size_t i) const {
    if(i >= getPositionalArgumentCount()) throw std::out_of_range("Positional argument doesn't exist");
    return argPositionnels[i];
  }
}
