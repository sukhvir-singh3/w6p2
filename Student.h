#ifndef Student_H
#define Student_H

#include <iostream>
#include "Person.h"
#include "College.h"

namespace sdds{
	class College;
	class Student: public Person{
		private:
			std::string m_name;
			std::string m_age;
			std::string m_id;
			std::string* m_courses;
			size_t m_count;
		public:
			int test = 2;
			Student(const Student& copy) = delete;
			Student& operator=(const Student& copy) = delete;
			Student(std::istream& istr);
			std::string status() const;
			std::string name() const;
			std::string age() const;
			std::string id() const;
			void display(std::ostream& out) const;
			std::string trim(const std::string& str);
	};
}
#endif
