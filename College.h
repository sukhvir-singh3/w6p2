#ifndef College_H
#define College_H

#include <iostream>
#include <vector>
#include <list>
#include "Person.h"

namespace sdds{
	class College{
		private:
			std::vector<Person*> m_persons;
		public:
			~College();
			College() = default;
			College(const College& copy) = delete;
			College& operator=(const College& copy) = delete;
			College& operator +=(Person* thePerson);
			void display(std::ostream& out) const;

			template<typename T>
			void select(const T& test, std::list<const Person*>& persons){
				for(auto& person: persons){
					if(test(person))
						persons.push_back(person);	
				}
			}
	};
}
#endif
