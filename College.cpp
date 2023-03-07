#include <iostream>
#include <ostream>
#include <vector>
#include <iomanip>
#include "College.h"
#include "Person.h"

namespace sdds{
	College::~College(){
		for(size_t i = 0; i < m_persons.size(); i++)
			delete m_persons[i];
	}
	College& College::operator +=(Person* thePerson){
		m_persons.push_back(thePerson);
		return *this;
	}

	void College::display(std::ostream& out)const{
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
		out << "|                                        Test #1 Persons in the college!                                               |" << std::endl;
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
		for(size_t i = 0; i < m_persons.size(); i++){
			m_persons[i]->display(out);
		}
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
		out << "|                                        Test #2 Persons in the college!                                               |" << std::endl;
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
		for(auto i = m_persons.begin(); i != m_persons.end(); i++){
			(*i)->display(out);
		}
		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
	}
}
