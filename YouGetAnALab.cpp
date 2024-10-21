#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

class Student {
public:
    string firstName;
    string lastName;
    int studentID;
    map<string, int> grades;

    Student(string first, string last, int id) : firstName(first), lastName(last), studentID(id) {}
};

class Assignment {
public:
    string name;
    int totalPoints;

    Assignment(string name, int points) : name(name), totalPoints(points) {}
};

class Gradebook {
private:
    vector<Student> students;
    vector<Assignment> assignments;

public:
    void addStudent(const string& firstName, const string& lastName, int studentID) {
        students.emplace_back(firstName, lastName, studentID);
    }

    void addAssignment(const string& name, int totalPoints) {
        assignments.emplace_back(name, totalPoints);
    }

    void assignGrade(int studentID, const string& assignmentName, int grade) {
        for (auto& student : students) {
            if (student.studentID == studentID) {
                student.grades[assignmentName] = grade;
                return;
            }
        }
        cout << "Student ID not found!\n";
    }

    void printReport() const {
        cout << left << setw(20) << "Student Name"
             << setw(15) << "Student ID"
             << "Grades\n";
        cout << std::string(60, '-') << '\n';

        for (const auto& student : students) {
            cout << left << setw(20) << (student.firstName + " " + student.lastName)
                << setw(15) << student.studentID;
            for (const auto& assignment : assignments) {
                auto it = student.grades.find(assignment.name);
                if (it != student.grades.end()) {
                    cout << it->second << " ";
                }
                else {
                    cout << "N/A ";
                }
            }
            cout << '\n';
        }
    }
};

int main() {
    Gradebook gradebook;

    gradebook.addStudent("John", "Doe", 1024);
    gradebook.addStudent("Jane", "Smith", 2048);

    gradebook.addAssignment("Math", 100);
    gradebook.addAssignment("Science", 100);

    gradebook.assignGrade(1024, "Math", 95);
    gradebook.assignGrade(1024, "Science", 88);
    gradebook.assignGrade(2048, "Math", 82);
    gradebook.assignGrade(2048, "Science", 89); 

    gradebook.printReport();

    return 0;
}