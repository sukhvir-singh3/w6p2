#ifndef Professor_H
#define Professor_H

#include <iostream>
#include "Employee.h"

namespace sdds{
	class Professor : public Employee{
		private:
			std::string m_department;			
		public:
			Professor(std::istream& in);
			void display(std::ostream& out) const;
			std::string status() const;
			std::string department() const;
	};
}
#endif
