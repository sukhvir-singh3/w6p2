#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "Person.h"
#include "Utilities.h"
#include "Utilities.h"
#include "College.h"
#include "College.h"

void loadData(const char* filename, sdds::College& theCollege)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cout << "ERROR: Cannot open file [" << filename << "].\n";
		return;
	}
	sdds::Person* thePerson = nullptr;
	while (file)
	{
		try{
		thePerson = sdds::buildInstance(file);
		if (thePerson)
			theCollege += thePerson;
		}catch(std::invalid_argument& e){
			std::cout << e.what() << std::endl;
		}
	}
}


int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::College theCollege;
	loadData(argv[1], theCollege);
	theCollege.display(std::cout);

	std::list<const sdds::Person*> persons;
	{
		// TODO: Create a lambda expression that receives as parameter `const sdds::Person*`
		//         and returns true if the person is student.
		auto students = [](const sdds::Person* person) { return person->status() == "S" || person->status() == "s"; };
		theCollege.select(students, persons);
	
		std::cout << "|                                        Test #3 Students in the college!                                              |\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
		for (auto it = persons.begin(); it != persons.end(); ++it)
		{
			(*it)->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
	}

	persons.clear();
	{
		// TODO: Create a lambda expression that receives as parameter `const sdds::Person*`
		//         and returns true if the person is professor.
		auto professors = [](const sdds::Person* person) { return person->status() == "p" || person->status() == "P"; };

		theCollege.select(professors, persons);
	
		std::cout << "|                                        Test #4 Professors in the college!                                            |\n";
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";		
		for (const auto person : persons)
		{
			person->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
	}

	return 0;
}
