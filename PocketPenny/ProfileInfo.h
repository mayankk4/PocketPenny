#ifndef PROFILEINFO_H
#define PROFILEINFO_H

#include <QString>

class ProfileInfo
{
private:
    int proId;
    QString name;
    int currentSalary;
    int currentBudget;

public:
    ProfileInfo();
    ProfileInfo(QString ,int ,int);
    void setProId(int);
    int getProId();
    void setName(QString);
    QString getName();
    void setCurrentSalary(int);
    int getCurrentSalary();
    void setCurrentBudget(int);
    int getCurrentBudget();

};

#endif // PROFILEINFO_H
