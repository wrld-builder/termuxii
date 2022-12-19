#include <exception>

#define DEBUG true  // put it in false to unable debug-mode

#define EXCEPTION_NUMBER_NOT_IN_FIELD "Exception: number not in field range"
#define EXCEPTION_NUMBER_NOT_IN_FIELD_CODE 1
#define EXCEPTION_FIELD_ELEMENT_IS_NULL "Exception: field element is null"
#define EXCEPTION_FIELD_ELEMENT_IS_NULL_CODE 2
#define EXCEPTION_ADD_IN_DIFF_FIELDS "Exception: trying to add element in different fields"
#define EXCEPTION_ADD_IN_DIFF_FIELDS_CODE 3

namespace OverrideExceptions {

class NumberNotInField : public std::exception {
 public:
  inline const char* what() const noexcept override { return EXCEPTION_NUMBER_NOT_IN_FIELD; }
};

class FieldElementIsNull : public std::exception {
 public:
  inline const char* what() const noexcept override { return EXCEPTION_FIELD_ELEMENT_IS_NULL; }
};

class AdditionInDifferentFields : public std::exception {
 public:
  inline const char* what() const noexcept override { return EXCEPTION_ADD_IN_DIFF_FIELDS; }
};

}  // namespace OverrideExceptions