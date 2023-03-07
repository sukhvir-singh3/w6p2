#include <iostream>
#include <iomanip>
#include <istream>
#include <stdexcept>
#include "Employee.h"

namespace sdds{

	Employee::Employee(std::istream& istr){
		std::string name;
		std::string age;
		std::string id;

		std::getline(istr, name, ',');
		std::getline(istr, age, ',');
		std::getline(istr, id, '\n');

		m_name = trim(name);
		m_id = trim(id);
		m_age = trim(age);

		if(m_id[0] != 'E' || !(std::stoi(m_age))){
			throw std::invalid_argument(name + "++Invalid record!");	
		}
	}

	std::string Employee::status() const{
		return "Employee"; 
	}

	std::string Employee::name() const{
		return m_name;
	}
	
	std::string Employee::id() const{
		return m_id;
	}

	std::string Employee::age() const{
		return m_age;
	}

	std::string Employee::trim(const std::string& str) {
    		size_t first = str.find_first_not_of(' ');
    		if (std::string::npos == first) 
     		   return str;
   		 
   		 size_t last = str.find_last_not_of(' ');
   		 return str.substr(first, (last - first + 1));
	} 

	void Employee::display(std::ostream& out)const{
			out << "| " << std::left << std::setw(10) << status() << " | "
		   	 << std::setw(10) << m_id << " | " 
		       << std::setw(20) << m_name << " | " 
		    	 << std::setw(3) << m_age << " | " << std::endl;
	}
}
