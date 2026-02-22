#ifndef EXPENSE_MANAGER_H
#define EXPENSE_MANAGER_H

#include <vector>
#include <map>
#include "Expense.h"

#define SUCCESS 0
#define FAILURE -1

class ExpenseManager
{
private:
  vector<Expense> expenses;
  const string FILE_NAME = "expenses.csv";

public:
  ExpenseManager();  /* Constructor */
  ~ExpenseManager(); /* Destructor */

  void addExpense();
  int viewExpenses() const;
  void showCategorySummary() const;
  void showTotalExpense() const;
  void editExpense();
  void deleteExpense();
  void searchExpense() const;

  void saveToCSV() const;
  void loadFromCSV();
};

#endif