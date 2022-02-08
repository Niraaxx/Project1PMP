#include "Option.h"


#include <stdexcept>

namespace op {

  Option::Option(const std::string& name) {
    names.push_back(name);
  }

  const std::vector<std::string>& Option::getNames() const {
    return names;
  }

  const std::string& Option::getValue() const {
    return val;
  }

  bool Option::expectValue() const {
    return this->needValue;
  }

  Option& Option::setDefaultValue(const std::string& value) {
    val = value;
    return *this;
  }

  Option& Option::hasValue() {
    needValue = true;
    return *this;
  }

  Option& Option::addAlias(const std::string& alias) {
    names.push_back(alias);
    return *this;
  }

  Option& Option::setMandatory() {
    mandatory = true;
    return *this;
  }

  bool Option::isMandatory() const {
    if(mandatory) return true;
    return false;
  }

  void Option::parsed(){
    isParsed = true;
  }

  bool Option::operator==(const std::string& arg) const {
    auto result = std::find(begin(this->getNames()),end(this->getNames()),arg);
    if(result != std::end(this->getNames())){
      return true;
    }else{
      return false;
    }
  }

  bool Option::operator!=(const std::string& arg) const {
    return !this->operator==(arg);
  }

  Option& Option::operator=(const std::string& value) {
    this->val = value;
    return *this;
  }

  Option::operator bool() const {
    return isParsed;
  }
}
