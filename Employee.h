#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include "Person.h"

namespace sdds{
	class Employee : public Person{
		private:
			std::string m_name;
			std::string m_age;
			std::string m_id;
		public:
			Employee();
			Employee(std::istream& istr);	
			std::string status() const;
			std::string name() const;
			std::string id() const;
			std::string age() const;
			void display(std::ostream& out) const;
			std::string trim(const std::string& str);
	};
}
#endif
