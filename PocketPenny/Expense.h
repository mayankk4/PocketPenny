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
    QDate expDate;
    QTime expTime;

public:
    Expense();
    Expense(int,float,QDate,QTime);
    void setExpId(int);
    int getExpId();
    void setCatId(int);
    int getCatId();
    void setAmount(float);
    float getAmount();
    void setExpDate(QDate);
    QDate getExpDate();
    void setExpTime(QTime);
    QTime getExpxpTime();
};

#endif // EXPENSE_H
