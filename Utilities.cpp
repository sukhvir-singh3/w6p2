#include <iostream>
#include "Utilities.h"

namespace sdds{
	Person* buildInstance(std::istream& in){
		std::string line; 
		std::getline(in, line);
		std::stringstream ss(line);	
		char status;
		ss >> status;
		if(status == 'E' || status == 'e'){
			ss.ignore();
			return new Employee(ss);
		}
		else if(status == 's' || status == 'S'){
			ss.ignore();
			return new Student(ss);
		}
		return nullptr;
	}
}