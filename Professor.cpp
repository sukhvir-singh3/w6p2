#include <iostream>
#include <istream>
#include "Professor.h"
#include "Person.h"
#include "Employee.h"

namespace sdds{
	Professor::Professor(std::istream& in): Employee(in){
		std::string department;
		getline(in, department, '\n');
		m_department = trim(department);
	}
	void Professor::display(std::ostream& out)const{
		Employee::display(out);
		if(Person::test == 1 || Person::test > 2){
		out << m_department << "| "
		    << "Professor" ;
		 }if(Person::test == 1 || Person::test == 2){
			out << std::endl; 
		 }
	}
	std::string Professor::status() const{
		return "Professor";
	}
	std::string Professor::department() const{
		return m_department;
	}
}
