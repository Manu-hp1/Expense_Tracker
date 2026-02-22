#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <unistd.h>
#include "ExpenseManager.h"

using namespace std;

string repeat(const string &s, int count)
{
  string result;
  for (int i = 0; i < count; ++i)
    result += s;
  return result;
}

ExpenseManager::ExpenseManager()
{
  loadFromCSV();
}

ExpenseManager::~ExpenseManager()
{
  saveToCSV();
}

void ExpenseManager::addExpense()
{
  double amount;
  string category, note;

  cout << "Enter amount: ";

  while (!(cin >> amount) || amount <= 0)
  {
    cout << "Invalid amount. Enter positive number: ";
    cin.clear();
    cin.ignore(10000, '\n');
  }
  cin.ignore();

  cout << "Enter category: ";
  getline(cin, category);

  cout << "Enter note: ";
  getline(cin, note);

  expenses.emplace_back(amount, category, note);
  cout << "|\033[1;92mExpense added successfuuly.\033[1;97m\n";
}

int ExpenseManager::viewExpenses() const
{
  if (expenses.empty())
  {
    cout << "|\033[1;91mNo expenses recorded.\033[1;97m\n";
    return FAILURE;
  }
  /*
    const string CYAN = "\033[1;36m";
    const string WHITE = "\033[1;97m";
    const string RESET = "\033[0m";

    const int W1 = 6;
    const int W2 = 15;
    const int W3 = 20;
    const int W4 = 30;

    cout << CYAN
         << "\n╔" << repeat("═", W1)
         << "╦" << repeat("═", W2)
         << "╦" << repeat("═", W3)
         << "╦" << repeat("═", W4)
         << "╗\n";

    cout << "║" << RESET
         << WHITE << setw(W1) << left << " No "
         << CYAN << "║" << RESET
         << WHITE << setw(W2) << left << " 💰 Amount"
         << CYAN << "║" << RESET
         << WHITE << setw(W3) << left << " 📂 Category"
         << CYAN << "║" << RESET
         << WHITE << setw(W4) << left << " 📝 Note"
         << CYAN << "║\n";

    cout << CYAN
         << "╠" << repeat("═", W1)
         << "╬" << repeat("═", W2)
         << "╬" << repeat("═", W3)
         << "╬" << repeat("═", W4)
         << "╣\n";

    int i = 1;
    for (const auto &e : expenses)
    {
      cout << "║" << RESET
           << WHITE << setw(W1) << left << i++
           << CYAN << "║" << RESET
           << WHITE << setw(W2) << left << ("₹ " + to_string(e.getAmount()))
           << CYAN << "║" << RESET
           << WHITE << setw(W3) << left << e.getCategory()
           << CYAN << "║" << RESET
           << WHITE << setw(W4) << left << e.getNote()
           << CYAN << "║\n";
    }

    cout << CYAN
         << "╚" << repeat("═", W1)
         << "╩" << repeat("═", W2)
         << "╩" << repeat("═", W3)
         << "╩" << repeat("═", W4)
         << "╝\n"
         << RESET;
    */
  cout << "\n\033[1;36m╔═══════════════╦═══════════════════════════════════════╦═══════════════════════════════╦══════════════════════════════════════════╗\033[0m\n";
  cout << "\033[1;36m║               ║\t\t\t\t\t║\t\t\t\t║\t\t\t\t\t   ║\033[0m\n";
  cout << "\033[1;36m║     \033[1;37mS.NO.\033[0m     \033[1;36m║\033[0m\t\t"
       << "\U0001F4B0 \033[1;37mAMOUNT\033[0m  \t\t"
       << "\033[1;36m║\033[0m\t"
       << "\U0001F4C2 \033[1;37mCATEGORY\033[0m\t\t"
       << "\033[1;36m║\033[0m\t   "
       << "\U0001F4DD \033[1;37m"
       << left << setw(29) << "NOTE"
       << "\033[0m\033[1;36m║\033[0m\n";
  printf("\033[1;36m║               ║\t\t\t\t\t║\t\t\t\t║%-42c║\033[0m\n", ' ');
  int i = 1;
  for (const auto &e : expenses)
  {
    cout << "\033[1;36m╠═══════════════╬═══════════════════════════════════════╬═══════════════════════════════╬══════════════════════════════════════════╣\033[0m\n";
    usleep(100000); // small delay of 100000µs
    cout << "\033[1;36m║       \033[1;97m"
         << left << setw(3) << i++
         << "\t\033[1;36m║\t\t"
         << "₹ \033[1;97m"
         << left << setw(22) << e.getAmount()
         << "\033[1;36m║\t"
         << "\033[1;97m\U0001F4C2 "
         << left << setw(21) << e.getCategory()
         << "\033[1;36m║\t   "
         << "\033[1;97m\U0001F4DD "
         << left << setw(29) << e.getNote()
         << "\033[1;36m║\033[0m"
         << endl;
  }
  cout << "\033[1;36m╚═══════════════╩═══════════════════════════════════════╩═══════════════════════════════╩══════════════════════════════════════════╝\033[0m\n";
  return SUCCESS;
}

void ExpenseManager::showCategorySummary() const
{
  if (expenses.empty())
  {
    cout << "No expenses found!\n";
    return;
  }

  map<string, double> summary;
  for (const auto &e : expenses)
  {
    summary[e.getCategory()] += e.getAmount();
  }

  const string CYAN = "\033[1;36m";
  const string WHITE = "\033[1;97m";
  const string RESET = "\033[0m";

  const int W1 = 6;
  const int W2 = 25;
  const int W3 = 15;

  cout << CYAN
       << "\n╔" << repeat("═", W1)
       << "╦" << repeat("═", W2)
       << "╦" << repeat("═", W3)
       << "╗\n";

  cout << "║" << RESET
       << WHITE << setw(W1) << left << " No "
       << CYAN << "║" << RESET
       << WHITE << setw(W2) << left << " 📂 Category"
       << CYAN << "║" << RESET
       << WHITE << setw(W3) << left << " 💰 Total"
       << CYAN << "║\n";

  cout << CYAN
       << "╠" << repeat("═", W1)
       << "╬" << repeat("═", W2)
       << "╬" << repeat("═", W3)
       << "╣\n";

  int i = 1;
  for (const auto &p : summary)
  {
    cout << "║" << RESET
         << WHITE << setw(W1) << left << i++
         << CYAN << "║" << RESET
         << WHITE << setw(W2) << left << p.first
         << CYAN << "║" << RESET
         << WHITE << setw(W3) << left << ("₹ " + to_string(p.second))
         << CYAN << "║\n";
  }

  cout << CYAN
       << "╚" << repeat("═", W1)
       << "╩" << repeat("═", W2)
       << "╩" << repeat("═", W3)
       << "╝\n"
       << RESET;
}

void ExpenseManager::showTotalExpense() const
{
  if (expenses.empty())
  {
    cout << "|\033[1;91mNo expenses recorded.\033[1;97m\n";
    return;
  }

  double total = 0;

  for (const auto &e : expenses)
  {
    total += e.getAmount();
  }

  const string GREEN = "\033[1;92m";
  const string RESET = "\033[0m";
  cout << "\n=====================================\n";
  cout << GREEN << "💰 TOTAL EXPENSE : ₹ " << total << RESET << endl;
  cout << "=====================================\n";
}

void ExpenseManager::editExpense()
{
  if(viewExpenses() == FAILURE)
  {
    return;
  }
  size_t index;

  cout << "Enter expense number to edit: ";
  cin >> index;

  if (index < 1 || index > expenses.size())
  {
    cout << "|\033[1;91mInvalid selection.\033[1;97m\n";
    return;
  }

  Expense &e = expenses[index - 1];

  double amt;
  string cat, nt;

  cout << "New amount: ";
  cin >> amt;
  cin.ignore();

  cout << "New category: ";
  getline(cin, cat);

  cout << "New note: ";
  getline(cin, nt);

  e.setAmount(amt);
  e.setCategory(cat);
  e.setNote(nt);

  cout << "|\033[1;92mExpenses updated\033[0m\n";
}

void ExpenseManager::deleteExpense()
{
  if(viewExpenses() == FAILURE)
  {
    return;
  }
  size_t index;

  cout << "Enter expense number to delete: ";
  cin >> index;

  if (index < 1 || index > expenses.size())
  {
    cout << "|\033[1;91mInvalid selection\033[0m\n";
    return;
  }

  expenses.erase(expenses.begin() + (index - 1));
  cout << "|\033[38;5;208mExpense deleted.\033[0m\n";
}

void ExpenseManager::searchExpense() const
{
  if (expenses.empty())
  {
    cout << "No expenses recorded.\n";
    return;
  }
  string keyword;
  cin.ignore();

  cout << "Enter keyword: ";
  getline(cin, keyword);

  string lowerkeyword = keyword;

  bool found = false;

  for (const auto &e : expenses)
  {
    if (e.getCategory().find(keyword) != string::npos || e.getNote().find(keyword) != string::npos)
    {
      cout << "₹" << e.getAmount() << " | "
           << e.getCategory() << " | "
           << e.getNote() << endl;
      found = true;
    }
  }

  if (!found)
  {
    cout << "|\033[1;91mNo matching record found.\033[0m\n";
  }
}

void ExpenseManager::saveToCSV() const
{
  ofstream file(FILE_NAME);
  file << "Amount,Category,Note\n";

  for (const auto &e : expenses)
  {
    file << e.getAmount() << ","
         << e.getCategory() << ","
         << e.getNote() << "\n";
  }
}

void ExpenseManager::loadFromCSV()
{
  ifstream file(FILE_NAME);
  if (!file.is_open())
    return;

  expenses.clear();
  string line;
  getline(file, line);

  while (getline(file, line))
  {
    stringstream ss(line);
    string amt, cat, nt;

    getline(ss, amt, ',');
    getline(ss, cat, ',');
    getline(ss, nt, '\n');

    try
    {
      expenses.emplace_back(stod(amt), cat, nt);
    }
    catch (...)
    {
      cout << "|\033[38;2;0;255;255mSkipping invalid row.\033[0m\n";
    }
  }
}