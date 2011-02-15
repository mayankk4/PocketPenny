#include "Expense.h"

Expense::Expense()
{
    expId = 0;
    catId = 0;
    amount = 0.0;
    expDay = 0;
    expMonth = 0;
    expYear = 0;
    expTime = *(new QTime());
}

Expense::Expense(int catId, float amount, int expDay, int expMonth, int expYear, QTime expTime)
{
    this->expId = 0;
    this->catId = catId;
    this->amount = amount;
    this->expDay = expDay;
    this->expMonth = expMonth;
    this->expYear = expYear;
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

void Expense::setExpDay(int expDay)
{
    this->expDay = expDay;
}

int Expense::getExpDay()
{
    return expDay;
}

void Expense::setExpMonth(int expMonth)
{
    this->expMonth = expMonth;
}

int Expense::getExpMonth()
{
    return expMonth;
}

void Expense::setExpYear(int expYear)
{
    this->expYear = expYear;
}

int Expense::getExpYear()
{
    return expYear;
}

void Expense::setExpTime(QTime expTime)
{
    this->expTime = expTime;
}

QTime Expense::getExpxpTime()
{
    return expTime;
}

