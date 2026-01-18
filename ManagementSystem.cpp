#include <iostream>
#include <string>
#include <vector>

struct Student
{
    std::string name;
    int age;
    int grade;
};

void addStudent(std::vector<Student>& students)
{
    Student s;
    std::cout << "Name: ";
    std::cin >> s.name;

    std::cout << "Age: ";
    std::cin >> s.age;

    std::cout << "Grade: ";
    std::cin >> s.grade;

    students.push_back(s);
    std::cout << "Student added\n";
}

void PrintStudents(const std::vector<Student>& students)
{
    if (students.empty())
    {
        std::cout << "No students!\n";
        return;
    }

    for (int i = 0; i < students.size(); i++)
    {
        std::cout << i + 1 << ") "
            << students[i].name << " | "
            << students[i].age << " | "
            << students[i].grade << std::endl;
    }
}

void SearchByGrade(const std::vector<Student>& students)
{
    int minGrade;
    std::cout << "Enter minimal grade: ";
    std::cin >> minGrade;

    bool found = false;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].grade >= minGrade)
        {
            std::cout << students[i].name
                << " | " << students[i].grade << std::endl;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "Students not found\n";
    }
}

void ChangeGrade(std::vector<Student>& students)
{
    std::string name;
    std::cout << "Enter student name: ";
    std::cin >> name;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].name == name)
        {
            std::cout << "Enter new grade: ";
            std::cin >> students[i].grade;
            std::cout << "Grade updated\n";
            return;
        }
    }

    std::cout << "Student not found\n";
}

void DeleteName(std::vector<Student>& students)
{
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].name == name)
        {
            students.erase(students.begin() + i);
            std::cout << "Student deleted\n";
            return;
        }
    }

    std::cout << "Student not found\n";
}

int main()
{
    std::vector<Student> students;
    int choice;

    do
    {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Show all students\n";
        std::cout << "3. Search by grade\n";
        std::cout << "4. Change student grade\n";
        std::cout << "5. Delete student\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent(students);
            break;
        case 2:
            PrintStudents(students);
            break;
        case 3:
            SearchByGrade(students);
            break;
        case 4:
            ChangeGrade(students);
            break;
        case 5:
            DeleteName(students);
            break;
        case 0:
            std::cout << "Bye!\n";
            break;
        default:
            std::cout << "Wrong choice\n";
        }

    } while (choice != 0);

    return 0;
}
