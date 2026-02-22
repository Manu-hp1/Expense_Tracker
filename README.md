# 💰 Expense Tracker using C

A **menu-driven Expense Tracker application developed in C**, designed to record, manage, and analyze daily expenses using **file-based persistent storage**.

This project demonstrates strong fundamentals in **C programming, structures, file handling, and modular design**.

---

## 🚀 Project Description

The Expense Tracker allows users to efficiently manage their daily expenses through a simple command-line interface.

Users can add expenses, categorize them, view all records, and generate summaries. All data is stored in a file, ensuring persistence across multiple executions.

This project focuses on applying core C programming concepts to solve a real-world financial tracking problem.

---

## 🎯 Objective

- Develop a file-based expense management system  
- Apply structures and file handling in C  
- Practice modular programming and input validation  
- Build a practical real-world console application  

---

## ✨ Features

- Add new expense records  
- Categorize expenses (Food, Travel, Utilities, etc.)  
- View all stored expenses  
- Display category-wise summary  
- Calculate total expenses  
- File-based persistent storage  
- Menu-driven user interface  

---

## 🛠️ Technologies & Concepts Used

- **C Programming**
- **Structures**
- **File Handling (fopen, fprintf, fscanf, fclose)**
- **Pointers and Arrays**
- **Modular Programming**
- **Input Validation**
- **Control Flow Logic**

---

## 🧠 How the Application Works

- Expense data is stored using a **structure** (Date, Category, Amount, Notes).
- Records are written to a file (CSV/Text format) using file handling functions.
- On program start, existing data is loaded from the file.
- Each feature (add, view, summary) is handled through separate functions.
- Input validation ensures data correctness and prevents invalid entries.

---

## 📂 Project Structure

```
ExpenseTracker/
├── main.c
├── expense.c
├── expense.h
├── file.c
├── file.h
└── expenses.csv
```

---

## ▶️ Compilation and Execution

### Compile:
```bash
gcc *.c -o expense_tracker
```

### Run:
```bash
./expense_tracker
```

---

## 🧪 Sample Usage

```
===== Expense Tracker =====
1. Add Expense
2. View Expenses
3. Category Summary
4. Exit

Enter choice: 1
Enter Date: 21-02-2026
Enter Category: Food
Enter Amount: 250
Enter Notes: Lunch

Expense added successfully!
```

---

## 📊 Key Functionalities

- Dynamic expense recording  
- File-based data persistence  
- Category-wise aggregation  
- Total expense calculation  
- Structured and modular implementation  

---

## 📈 Learning Outcome

This project strengthened my understanding of:

- Structures and data organization  
- File handling and persistent storage  
- Writing modular and maintainable C code  
- Implementing real-world problem-solving logic  

It enhanced my debugging skills and improved my confidence in developing console-based applications.

---

## 👨‍💻 Author

**Manu H P**  
Embedded Systems Enthusiast  
Skilled in C Programming, Linux, and System-Level Concepts  

---

## 📎 GitHub Repository

```
https://github.com/Manu-hp1/Expense_Tracker
```

---

## 📄 License

This project is developed for learning and educational purposes.
