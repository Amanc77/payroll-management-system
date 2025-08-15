#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <iomanip> // For setw
using namespace std;

// Employee details
class Employee {
public:
    int id;
    string name;
    string email;
    double salary;

    void input() {
        while (true) {
            cout << "Enter ID: ";
            if (cin >> id && id > 0) break;
            cout << "Invalid input. Enter a positive integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter email: ";
        getline(cin, email);

        while (true) {
            cout << "Enter monthly salary: ";
            if (cin >> salary && salary >= 0) break;
            cout << "Invalid input. Enter a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void show() const {
        cout << left << setw(20) << name
             << setw(10) << id
             << setw(30) << email
             << setw(10) << salary
             << endl;
    }
};

// Payroll management
class Payroll {
private:
    vector<Employee> employees;

    void show_menu() {
        cout << "\n----- Payroll System by Aman -----\n";
        cout << "1. Add Employee\n2. Remove Employee\n3. Change Employee Details\n4. Print Salary Report\n5. Search Employee\n6. Exit\nChoose: ";
    }

    void add_employee() {
        Employee emp;
        emp.input();
        employees.push_back(emp);
        cout << "Employee added!\n";
    }

    void remove_employee() {
        int id;
        cout << "Enter ID: ";
        if (!(cin >> id)) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
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

    void change_employee() {
        int id;
        cout << "Enter ID: ";
        if (!(cin >> id)) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (Employee& emp : employees) {
            if (emp.id == id) {
                cout << "Enter new details:\n";
                emp.input();
                cout << "Employee updated!\n";
                return;
            }
        }
        cout << "Employee not found!\n";
    }

    void print_report() {
        double total = 0;
        ofstream file("salary_report.txt");

        cout << "\n----- Salary Report -----\n";
        cout << left << setw(20) << "Name"
             << setw(10) << "ID"
             << setw(30) << "Email"
             << setw(10) << "Salary" << "\n";
        cout << string(70, '-') << "\n";

        if (file.is_open()) {
            file << left << setw(20) << "Name"
                 << setw(10) << "ID"
                 << setw(30) << "Email"
                 << setw(10) << "Salary" << "\n";
            file << string(70, '-') << "\n";
        }

        if (employees.empty()) {
            cout << "No employees found.\n";
            if (file.is_open()) file << "No employees found.\n";
        }

        for (const auto& emp : employees) {
            emp.show();
            total += emp.salary;
            if (file.is_open()) {
                file << left << setw(20) << emp.name
                     << setw(10) << emp.id
                     << setw(30) << emp.email
                     << setw(10) << emp.salary << "\n";
            }
        }

        cout << "\nTotal Salary:\t" << total << endl;
        cout << "----- Created by Aman -----\n";

        if (file.is_open()) {
            file << "\nTotal Salary:\t" << total << "\n";
            file << "----- Created by Aman -----\n";
            file.close();
            cout << "Report saved to: salary_report.txt\n";
            system("pwd");
        } else {
            cout << "Error saving report to file!\n";
        }
    }

    void search_employee() {
        int id;
        cout << "Enter Employee ID to search: ";
        if (!(cin >> id)) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (const auto& emp : employees) {
            if (emp.id == id) {
                cout << "\nEmployee Found:\n";
                cout << left << setw(20) << "Name"
                     << setw(10) << "ID"
                     << setw(30) << "Email"
                     << setw(10) << "Salary" << "\n";
                cout << string(70, '-') << "\n";
                emp.show();
                return;
            }
        }
        cout << "Employee not found!\n";
    }

public:
    void run() {
        int choice;
        do {
            show_menu();
            if (!(cin >> choice)) {
                cout << "Invalid input.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {
                case 1: add_employee(); break;
                case 2: remove_employee(); break;
                case 3: change_employee(); break;
                case 4: print_report(); break;
                case 5: search_employee(); break;
                case 6: cout << "Exiting...\n"; break;
                default: cout << "Wrong choice! Try again.\n";
            }
        } while (choice != 6);
    }
};

int main() {
    Payroll payroll;
    payroll.run();
    return 0;
}
