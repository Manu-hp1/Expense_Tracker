#include <iostream>
#include "ExpenseManager.h"

using namespace std;

int main()
{
  ExpenseManager manager;
  int choice;

  while (1)
  {
    cout << "\033[1;97m\n============================== 📋 Expense Tracker ==============================\n"
         << "1] 💸 Add Expense\n"
         << "2] 👀 View Expenses\n"
         << "3] 📊 Category Summary\n"
         << "4] 💰 Total Expenses\n"
         << "5] ✏️  Edit Expense\n"
         << "6] 🗑️  Delete Expense\n"
         << "7] 🔍  Search Expense\n"
         << "8] 🚪 Exit\n"
         << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      manager.addExpense();
      break;
    case 2:
      manager.viewExpenses();
      break;
    case 3:
      manager.showCategorySummary();
      break;
    case 4:
      manager.showTotalExpense();
      break;
    case 5:
      manager.editExpense();
      break;
    case 6:
      manager.deleteExpense();
      break;
    case 7:
      manager.searchExpense();
      break;
    case 8:
      return 0;
    default:
      cout << "\033[1;91mInvalid choice!!\033[1;97m\n";
    }
  }
}