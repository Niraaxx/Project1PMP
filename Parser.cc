#include "Parser.h"

#include <algorithm>
#include <stdexcept>

namespace op {
  //Constructor of the Parser
  Parser::Parser(){
    Option helpOpt = Option("help");
    helpOpt.addAlias("h");
    options.push_back(helpOpt);
  }
  //read the option on the line command
  void Parser::parseCommandLine(int argc, const char* const argv[]) {
    //browse the line command
    for(int i =0; i<argc;i++){  
      std::string opt = (std::string) argv[i];
      std::string opt1=opt.substr(0,1);
      std::string opt2=opt.substr(1,1);
      //check if there are two -
      if((opt1.compare("-")==0)&&(opt2.compare("-")==0)){
        //browse the option
        for(int j=0; j< options.size();j++){
          //if it's a new option
          if(options[j].operator!=(opt.substr(opt.find("-")+2))){   
            Option optObj = operator()(opt);

            //check if this option expect a value 
            if(optObj.expectValue()){
              optObj.operator=(argv[i+1]);
              i++;
            }
            //parsed the option and then add the option in the list of option
            optObj.parsed();
            options.push_back(opt);
          }else{
            throw std::runtime_error("Not an option");
          }
        }
      //check if there is a - 
      }else if(opt1.compare("-")==0){

        //browse the list of option
        for(int j=0; j< options.size();j++){

          //if the option doesn't exit in the list
          if(options[j].operator!=(opt.substr(opt.find("-")+1))){
            Option optObj = operator()(opt);

            //check if the option expect a value
            if(optObj.expectValue()){
              optObj.operator=(argv[i+1]);
              i++;
            }
            //parsed and add the option in the list of options
            optObj.parsed();
            options.push_back(opt);
          }else{
            throw std::runtime_error("Not an option");
          }
        }
       }
       //if there is no - it is a value 
      else{
        //std::cout << "premier element de option "<<opt.substr(0,1)<<" deuxieme element de l'option "<<opt.substr(1,1) <<"\n";

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
  //print the help 
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
  //it's a function to know the number of positional arguments
  std::size_t Parser::getPositionalArgumentCount() const {
    return argPositionnels.size();
  }
  //it's to get the option by it's name
  Option& Parser::operator()(const std::string& name) {
    for(auto &option : this->options){
      if(option == name){
        return option;
      }
    }
    options.emplace_back(name);
    return options.back();
  }
  //to determinate if the positional argument exist 
  const std::string& Parser::operator[](std::size_t i) const {
    if(i >= getPositionalArgumentCount()) throw std::out_of_range("Positional argument doesn't exist");
    return argPositionnels[i];
  }
}
