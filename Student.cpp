#include <iostream>
#include <istream>
#include <iomanip>
#include <string>
#include <cctype>
#include "Student.h"
#include "Person.h"
#include "College.h"

namespace sdds{

	std::string Student::trim(const std::string& str) {
    		size_t first = str.find_first_not_of(' ');
    		if (std::string::npos == first) 
     		   return str;
   		 
   		 size_t last = str.find_last_not_of(' ');
   		 return str.substr(first, (last - first + 1));
	} 
	Student::Student(std::istream& istr){
		std::string name;
		std::string age;
		std::string id;
		std::string course_num;
		std::string* courses;

		std::getline(istr, name, ',');
		std::getline(istr, age, ',');
		std::getline(istr, id, ',');
		std::getline(istr, course_num, ',');

		bool not_a_number = false;

		    for (char c : trim(age))
        		if (!isdigit(c)) 
				not_a_number = true;
		
		m_id = trim(id);

		if(m_id[0] != 'S' || not_a_number){
			throw std::invalid_argument(trim(name) + "++Invalid record!");	
		}

		m_count = std::stoi(course_num);
		courses = new std::string[m_count];
		size_t loop = 0;

		while(loop < m_count){
			if(loop == (m_count - 1))
				std::getline(istr, courses[loop++], '\n');
			else
				std::getline(istr, courses[loop++], ',');
		}

		m_courses = new std::string[m_count];
		for(size_t i = 0u; i < m_count; i++)
			m_courses[i]= trim(courses[i]);  
		m_name = trim(name);
		m_age = trim(age);

		
		delete[] courses;
	}

	std::string Student::status()const{
		return "Student";
	}

	std::string Student::name()const{
		return m_name;
	}

	std::string Student::age()const{
		return m_age;
	}

	std::string Student::id()const{
		return m_id;
	}

	void Student::display(std::ostream& out)const{
		out << "| " << std::left << std::setw(10) << status() << " | "
	   	 << std::setw(10) << m_id << " | " 
	       << std::setw(20) << m_name << " | " 
	    	 << std::setw(3) << m_age << " |"; 
		if(Person::test == 1 || Person::test > 2){
			 for(size_t i = 0; i < m_count; i++){
				out << m_courses[i];	
				if(i != (m_count - 1))
					out << ',';
			}
		 }if(Person::test == 1 || Person::test == 2){
			out << std::endl;
		 }
		 
	}
}
