# Payroll Management System

A simple **Payroll Management System** built using **C++**.  
This project allows you to manage employees, calculate salaries, and generate reports.

---

## ✨ Features
- Add Employee (with Name, ID, Email, and Salary)
- Remove Employee by ID
- Update Employee Details
- Search Employee by ID
- Print Salary Report (also saved to `salary_report.txt`)
- Input Validation (avoids invalid inputs)
- Clean tabular salary report using `setw`

---

## 📂 Project Structure
```
payroll-management-system/
│── PayRole.cpp           # Main source code
│── salary_report.txt     # Salary report file (auto-generated)
│── README.md             # Documentation

```

---

## ⚙️ How to Run
1. Open terminal and navigate to the project folder:
   ```bash
   cd payroll-management-system
   ```
2. Compile the code using g++:
   ```bash
   g++ PayRole.cpp -o payroll
   ```
3. Run the program:
   ```bash
   ./payroll
   ```

---

## 📜 Example Menu
```
----- Payroll System by Aman -----
1. Add Employee
2. Remove Employee
3. Change Employee Details
4. Print Salary Report
5. Search Employee
6. Exit
Choose:
```

---

## 🖼️ Sample Output (Salary Report)
```
----- Salary Report -----
Name                 ID     Email                        Salary
-----------------------------------------------------------------
Aman Kumar           1      amankumar@gmail.com          20000
Kumar Chaurasiya     2      chaursiay33223r2gail.com     234324

Total Salary:        254324

```

---

## 📌 Requirements
- C++ Compiler (e.g., g++)
- Works on Linux, macOS, and Windows (with MinGW)

---

## 👨‍💻 Author
**Aman Kumar**  
GitHub: [Amanc77](https://github.com/Amanc77)

---
