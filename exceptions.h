#include <exception>

#define DEBUG true  // put it in false to unable debug-mode

#define EXCEPTION_NUMBER_NOT_IN_FIELD "Exception: number not in field range"
#define EXCEPTION_NUMBER_NOT_IN_FIELD_CODE 1
#define EXCEPTION_FIELD_ELEMENT_IS_NULL "Exception: field element is null"
#define EXCEPTION_FIELD_ELEMENT_IS_NULL_CODE 2
#define EXCEPTION_ADD_IN_DIFF_FIELDS "Exception: trying to __add__ element in different fields"
#define EXCEPTION_ADD_IN_DIFF_FIELDS_CODE 3
#define EXCEPTION_SUB_IN_DIFF_FIELDS "Exception: trying to __sub__ element in different fields"
#define EXCEPTION_SUB_IN_DIFF_FIELDS_CODE 4
#define EXCEPTION_MUL_IN_DIFF_FIELDS "Exception: trying to __mul__ element in different fields"
#define EXCEPTION_MUL_IN_DIFF_FIELDS_CODE 5
#define EXCEPTION_TRUEDIV_IN_DIFF_FIELDS "Exception: trying to __truediv__ element in different fields"
#define EXCEPTION_TRUEDIV_IN_DIFF_FIELDS_CODE 6
#define EXCEPTION_POINT_NOT_IN_THE_CURVE "Exception: point is not on the curve"
#define EXCEPTION_POINT_NOT_IN_THE_CURVE_CODE 7

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

class SubInDifferentFields : public std::exception {
 public:
  inline const char* what() const noexcept override { return EXCEPTION_ADD_IN_DIFF_FIELDS; }
};

class MulInDifferentFields : public std::exception {
 public:
  inline const char* what() const noexcept override { return EXCEPTION_MUL_IN_DIFF_FIELDS; }
};

class TrueDivInDifferentFields : public std::exception {
 public:
  inline const char* what() const noexcept override { return EXCEPTION_TRUEDIV_IN_DIFF_FIELDS; }
};

class PointNotOntheCurve : public std::exception {
 public:
  inline const char* what() const noexcept override { return EXCEPTION_POINT_NOT_IN_THE_CURVE; }
};

}  // namespace OverrideExceptions