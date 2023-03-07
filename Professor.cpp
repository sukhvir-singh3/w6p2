#include <iostream>
#include <istream>
#include "Professor.h"
#include "Employee.h"

namespace sdds{
	Professor::Professor(std::istream& in): Employee(in){
		std::string department;
		getline(in, department, '\n');
		m_department = trim(department);
	}
	void Professor::display(std::ostream& out)const{
		Employee::display(out);
	}
	std::string Professor::status() const{
		return "Professor";
	}
	std::string Professor::department() const{
		return m_department;
	}
}
