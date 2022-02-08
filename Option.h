#ifndef OP_OPTION_H_
#define OP_OPTION_H_

#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

namespace op {
  class Option {
  public:
    /**
     * Create an option and set its name
     */
    Option(const std::string& name);

    /**
     * Get all options names
     */
    const std::vector<std::string>& getNames() const;

    /**
     * Get option value
     */
    const std::string& getValue() const;

    /**
     * Tell if the option expects a value
     */
    bool expectValue() const;

    /**
     * Set the default value
     */
    Option& setDefaultValue(const std::string& value);

    /**
     * Modify the option to expect a value
     */
    Option& hasValue();

    /**
     * Add an alias
     */
    Option& addAlias(const std::string &alias);

    /**
     * Modify the option to be mandatory
     */
    Option& setMandatory();

    /**
     * Tell if the option is mandatory
     */
    bool isMandatory() const;

    /**
     * Modify the option to be parsed
     */
    void parsed();

    /**
     * Check if arg is the name or an alias of option
     */
    bool operator==(const std::string& arg) const;
    bool operator!=(const std::string& arg) const;

    /**
     * Set the value to the option
     */
    Option& operator=(const std::string& value);

    /**
     * Tell if the option has been parsed
     */
    operator bool() const;

  private:
    std::vector<std::string> names;
    std::string val;
    bool mandatory = false;
    bool needValue = false;
    bool isParsed = false;
  };
}

#endif // OP_OPTION_H_
