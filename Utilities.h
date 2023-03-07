#ifndef Utilities_H
#define Utilities_H

#include <iostream>
#include <sstream>
#include <string>
#include "Person.h"
#include "Employee.h"
#include "Student.h"

namespace sdds{
	Person* buildInstance(std::istream& in);
}
#endif
