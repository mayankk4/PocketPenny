#include "Expense.h"

Expense::Expense()
{
    expId = 0;
    catId = 0;
    amount = 0.0;
    expDate = *(new QDate());
    expTime = *(new QTime());
}

Expense::Expense(int expId, int catId, float amount, QDate expDate, QTime expTime)
{
    this->expId = expId;
    this->catId = catId;
    this->amount = amount;
    this->expDate = expDate;
    this->expTime = expTime;
}

void Expense::setExpId(int expId)
{
    this->expId = expId;
}

int Expense::getExpId()
{
    return expId;
}

void Expense::setCatId(int catId)
{
    this->catId = catId;
}

int Expense::getCatId()
{
    return catId;
}

void Expense::setAmount(float amount)
{
    this->amount = amount;
}

float Expense::getAmount()
{
    return amount;
}

void Expense::setExpDate(QDate expDate)
{
    this->expDate = expDate;
}

QDate Expense::getExpDate()
{
    return expDate;
}

void Expense::setExpTime(QTime expTime)
{
    this->expTime = expTime;
}

QTime Expense::getExpxpTime()
{
    return expTime;
}

