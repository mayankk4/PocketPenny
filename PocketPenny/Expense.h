#ifndef EXPENSE_H
#define EXPENSE_H

#include <QString>
#include <QDate>
#include <QTime>
class Expense
{
private:
    int expId;
    int catId;
    float amount;
    int expDay;
    int expMonth;
    int expYear;
    QTime expTime;

public:
    Expense();
    Expense(int,float,int,int,int,QTime);
    void setExpId(int);
    int getExpId();
    void setCatId(int);
    int getCatId();
    void setAmount(float);
    float getAmount();
    void setExpDay(int);
    int getExpDay();
    void setExpMonth(int);
    int getExpMonth();
    void setExpYear(int);
    int getExpYear();
    void setExpTime(QTime);
    QTime getExpxpTime();
};

#endif // EXPENSE_H
