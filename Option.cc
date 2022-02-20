#include "Option.h"


#include <stdexcept>

namespace op {
  //the constructor of an Option
  Option::Option(const std::string& name) {
    names.push_back(name);
  }
  //to get the names of an option
  const std::vector<std::string>& Option::getNames() const {
    return names;
  }
  //to get the value of an option
  const std::string& Option::getValue() const {
    if(val == ""){
      throw std::runtime_error("Need a value");
    }else if(needValue == false){
      throw std::runtime_error("No need a value");
    }
    else{
    return val;
    }
  }
  //to know if an option has a expected value
  bool Option::expectValue() const {
    return this->needValue;
  }
  //to put a value by default
  Option& Option::setDefaultValue(const std::string& value) {
    needValue = true;
    val = value;
    return *this;
  }
  //to specify that the option has a value
  Option& Option::hasValue() {
    needValue = true;
    return *this;
  }
  //add an alias for the option
  Option& Option::addAlias(const std::string& alias) {
    names.push_back(alias);
    return *this;
  }
  //set the option mandatory
  Option& Option::setMandatory() {
    mandatory = true;
    return *this;
  }
  //to know if the option is mandatory
  bool Option::isMandatory() const {
    if(mandatory) return true;
    return false;
  }
  //to parsed the option
  void Option::parsed(){
    isParsed = true;
  }
  //to know if the arg has the same name than the option or the alias of an option
  bool Option::operator==(const std::string& arg) const {
    auto result = std::find(begin(this->getNames()),end(this->getNames()),arg);
    if(result != std::end(this->getNames())){
      return true;
    }else{
      return false;
    }
  }

  //to know if the arg hasn't the same name than the option or the alias of an option
  bool Option::operator!=(const std::string& arg) const {
    return !this->operator==(arg);
  }
  //to set the value to the option
  Option& Option::operator=(const std::string& value) {
    this->val = value;
    return *this;
  }
  //to kow if the option is parsed
  Option::operator bool() const {
    return isParsed;
  }
}
