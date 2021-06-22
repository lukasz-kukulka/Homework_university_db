#include "University.hpp"

#include <fstream>
#include <iostream>

University::University() {
    loadFromFile();
    for (int i = 0; i < 10; i++) {
        students.push_back(Student());
        saveToFile(i);
    }
    students[0].printBorderTop();
    for (auto stu : students) {
        
        stu.printStudent();
    }
    students[0].printBorderBotton();
}

void University::printMenu() {
    std::cout << " --------------------- \n";
    std::cout << "|  STUDENTS DATABASE  |\n";
    std::cout << " --------------------- \n";
    std::cout << "1. Add student\n";
    std::cout << "2. Show all students\n";
    std::cout << "3. Search students \n";
    std::cout << "4. Exit\n\n";
}

University::MenuOption University::menuEngine() {
    std::cout << "Please insert you choice: ";
    uint8_t choice = 0;
    std::cin >> choice;
    menuOption_ = static_cast<MenuOption>(choice);
    switch (menuOption_)
    {
        case MenuOption::AddStudents : {

        } break;
        case MenuOption::ShowStudent : {

        } break;
        case MenuOption::SearchStudents : {

        } break;
        case MenuOption::Exit : {

        } break;    
        default:
        break;
    }
    return menuOption_;
}

void University::addNewStudent() {
    insertStudentName();
    insertStudentSurname();
    insertStudentIndexNumber();
    insertStudentPeselNumber();
    insertStudentGender();
    students.push_back(Student(name_, surname_, address_, indexNumber_, peselNumber_, static_cast<Student::Gender>(gender_)));
}

void University::insertStudentName() {
    do {
        std::cout << "Please insert student name: ";
        std::cin >> name_;
        std::cout << '\n';
    } while (validatingName() == false);
}

bool University::validatingName() {
    //TODO
    return true;
}

void University::insertStudentSurname() {
    do {
        std::cout << "Please insert student surname: ";
        std::cin >> surname_;
        std::cout << '\n';
    } while (validatingSurname() == false);
}

bool University::validatingSurname() {
    //TODO
    return true;
}

void University::insertAddress() {
    do {
        std::cout << "Please insert student address: ";
        std::cin >> surname_;
        std::cout << '\n';
    } while (validatingAddress() == false);
}

bool University::validatingAddress() {
    //TODO
    return true;
}

void University::insertStudentIndexNumber() {
    do {
        std::cout << "Please insert student index number: ";
        std::cin >> indexNumber_;
        std::cout << '\n';
    } while (validatingIndexNumber() == false);
}

bool University::validatingIndexNumber() {
    //TODO
    return true;
}

void University::insertStudentPeselNumber() {
    do {
        std::cout << "Please insert student PESEL number: ";
        std::cin >> peselNumber_;
        std::cout << '\n';       
    } while (validatingPeselNumber() == false);
}

bool University::validatingPeselNumber() {
    //TODO
    return true;
}

void University::insertStudentGender() {
    do {
        std::cout << "Please insert student surname: ";
        std::cin >> gender_;
        std::cout << '\n';
    } while (validatingGender() == false);
}

bool University::validatingGender() {
    //TODO
    return true;
}

void University::showStudents() {

    //std::cout << 
}

void University::saveToFile(size_t indexStudent) {
    std::fstream file;
    file.open("records.txt", std::ios::out | std::ios::app);
    file << "[Student nr. : " << indexStudent + 1 << "]\n";
    file << students[indexStudent].getName() << "\n";
    file << students[indexStudent].getSurname() << "\n";
    file << students[indexStudent].getAddress() << "\n";
    file << students[indexStudent].getIndexNumber() << "\n";
    file << students[indexStudent].getPeselNumber() << "\n";
    file << students[indexStudent].getGender() << "\n\n";
    file.close();
}

void University::loadFromFile() {
    students.reserve(countRecord());
    int lineNo = 1;
	std::string line;
	std::fstream file;
	file.open("records.txt", std::ios::in);
	if (file.good() == false) {
		std::cout << "Created new file\n";
		file.open("records.txt", std::ios::out | std::ios::app);
	}
	while (getline(file, line)){
        switch (lineNo){
            case 2: { 
                name_ = line; 
                break;
                }
            case 3: { 
                surname_ = line; 
                break;
                }
            case 4: { 
                address_ = line; 
                break;
                }
            case 5: { 
                indexNumber_ = line; 
                break;
                }
            case 6: { 
                peselNumber_ = line; 
                break;
                }
            case 7: { 
                line.size() == 4 ? gender_ = 1 : gender_ = 0;
                break;
                }  
        }
        lineNo++;
        if (lineNo > 8) {
            lineNo = 1;
            students.push_back(Student(name_, surname_, address_, indexNumber_, peselNumber_, static_cast<Student::Gender>(gender_)));
        } 
	}
    file.close();
}

int University::countRecord() {
    int lineNo = 0;
	std::string line;
	std::fstream file;
	file.open("records.txt", std::ios::in);
	if (file.good() == false) {
		std::cout << "Created new file\n";
		file.open("records.txt", std::ios::out | std::ios::app);
	}
	while (getline(file, line)){
        lineNo++;
    }
    file.close();
	return lineNo / 8;
}

void University::searchStudent() {

}

void University::searchByPeselNumber() {

}