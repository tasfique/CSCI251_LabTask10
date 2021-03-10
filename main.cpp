//Name-Tasfique Enam
//Question 1
#include <iostream>
using namespace std;

class Employee;
class Student;

template<class T>
class ObjectContainer {
private:
    T object;
    int noOfDElements;
public:
    ObjectContainer(T , int);
    ~ObjectContainer();
    template<class A>
    friend ostream &operator<<(ostream &, const ObjectContainer<A> &);
    template<class A>
    friend istream &operator>>(istream &, ObjectContainer<A> &);
};

template<class T>
ObjectContainer<T>::ObjectContainer(T object, int noOfDElements) {
    this->object = object;
    this->noOfDElements = noOfDElements;
}

template<class T>
ObjectContainer<T>::~ObjectContainer() {
}

template<class T>
ostream &operator<<(ostream &output, const ObjectContainer<T> &OC) {
    output << "DISPLAY." << endl;
    output << OC.object;
    return output;
}

template<class T>
istream &operator>>(istream &input, ObjectContainer<T> &OC) {
    cout << "ENTER " << OC.noOfDElements << " items." << endl;
    input >> OC.object;
    return input;
}

class Employee{
    private:
        string id;
        float salary;
    public:
        Employee();
        friend ostream &operator<<(ostream &, const Employee &);
        friend istream &operator>>(istream &, Employee &);
    };

Employee::Employee() {
    id = "None";
    salary = 0;
}

ostream &operator<<(ostream &out, const Employee &e) {
    out << "ID: " << e.id << endl;
    out << "SALARY: " << e.salary << endl;
    return out;
}

istream &operator>>(istream &in, Employee &e) {
    cout << "ID: ";
    in >> e.id;
    cout << "SALARY: ";
    in >> e.salary;
    return in;
}

class Student{
private:
    string name;
    int subjectNum;
    string typeOfStudent;
public:
    Student();
    friend ostream &operator<<(ostream &, const Student &);
    friend istream &operator>>(istream &, Student &);
};

Student::Student() {
    name = "None";
    subjectNum = 0;
    typeOfStudent = "None";
}

ostream &operator<<(ostream &out, const Student &s) {
    out << "STUDENT NAME: " << s.name << endl;
    out << "SUB(s): " << s.subjectNum << endl;
    out << "STUDENT TYPE: " << s.typeOfStudent << endl;
    return out;
}

istream &operator>>(istream &in, Student &s) {
    cout << "NAME: ";
    in >> s.name;
    cout << "SUBJECT NUMBER(s): ";
    in >> s.subjectNum;
    cout << "STUDENT TYPE: ";
    in >> s.typeOfStudent;
    return in;
}

int main() {
    Employee employees[1];
    Student students[1];

    ObjectContainer<Employee> objectContainerEmployee(employees[0], 2);
    cin >> objectContainerEmployee;
    ObjectContainer<Student> objectContainerStudent(students[0], 3);
    cin >> objectContainerStudent;

    cout << objectContainerEmployee;
    cout << objectContainerStudent;
    return 0;
}
