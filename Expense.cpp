#include "Expense.h"

Expense::Expense(double amt, const string &cat, const string &nt) : amount(amt), category(cat), note(nt) {}

double Expense::getAmount() const
{
  return amount;
}

string Expense::getCategory() const
{
  return category;
}

string Expense::getNote() const
{
  return note;
}

void Expense::setAmount(double amt)
{
  amount = amt;
}

void Expense::setCategory(const string &cat)
{
  category = cat;
}

void Expense::setNote(const string &nt)
{
  note = nt;
}