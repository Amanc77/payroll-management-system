#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

class Employee {
public:
    int id;
    string name;
    string address;
    double salary;

    void input() {
        while (true) {
            cout << "Enter ID: ";
            if (cin >> id && id > 0) break;
            cout << "Invalid input. Please enter a positive integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter address: ";
        getline(cin, address);

        while (true) {
            cout << "Enter monthly salary: ";
            if (cin >> salary && salary >= 0) break;
            cout << "Invalid input. Please enter a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void show() const {
        cout << name << "\t" << id << "\t" << address << "\t" << salary << endl;
    }
};

class Payroll {
private:
    vector<Employee> employees;

    void show_menu() {
        cout << "\n----- Payroll System by Aman -----\n";
        cout << "1. Add Employee\n";
        cout << "2. Remove Employee\n";
        cout << "3. Print Salary Report\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
    }

    void add_employee() {
        Employee emp;
        emp.input();
        employees.push_back(emp);
        cout << "Employee added!\n";
    }

    void remove_employee() {
        int id;
        while (true) {
            cout << "Enter ID: ";
            if (cin >> id) break;
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (size_t i = 0; i < employees.size(); i++) {
            if (employees[i].id == id) {
                employees.erase(employees.begin() + i);
                cout << "Employee removed!\n";
                return;
            }
        }
        cout << "Employee not found!\n";
    }

    void print_report() {
        double total = 0;
        ofstream file("salary_report.txt");

        cout << "\n----- Salary Report -----\n";
        cout << "Name\tID\tAddress\tSalary\n";
        cout << "------------------------\n";

        if (file.is_open()) {
            file << "----- Salary Report -----\n";
            file << "Name\tID\tAddress\tSalary\n";
            file << "------------------------\n";
        }

        if (employees.empty()) {
            cout << "No employees found.\n";
            if (file.is_open()) file << "No employees found.\n";
        }

        for (const auto& emp : employees) {
            emp.show();
            total += emp.salary;
            if (file.is_open()) {
                file << emp.name << "\t" << emp.id << "\t"
                     << emp.address << "\t" << emp.salary << "\n";
            }
        }

        cout << "\nTotal Salary: " << total << endl;

        if (file.is_open()) {
            file << "\nTotal Salary: " << total << "\n";
            file.close();
            cout << "Report saved to salary_report.txt\n";
        }
    }

public:
    void run() {
        int choice;
        do {
            show_menu();
            while (!(cin >> choice)) {
                cout << "Invalid input. Please enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                show_menu();
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {
                case 1: add_employee(); break;
                case 2: remove_employee(); break;
                case 3: print_report(); break;
                case 4: cout << "Exiting...\n"; break;
                default: cout << "Wrong choice! Try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    Payroll payroll;
    payroll.run();
    return 0;
}
