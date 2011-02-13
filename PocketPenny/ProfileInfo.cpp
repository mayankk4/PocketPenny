#include "ProfileInfo.h"

/*
ProfileInfo::ProfileInfo()
{
    this->name = "";
    this->currentSalary = 0;
    this->currentBudget = 0;
}
*/

ProfileInfo::ProfileInfo(QString name,int currentSalary,int currentBudget)
{
    this->name = name;
    this->currentSalary = currentSalary;
    this->currentBudget = currentBudget;
}

void ProfileInfo::setName(QString name)
{
    this->name = name;
}

QString ProfileInfo::getName()
{
    return this->name;
}

void ProfileInfo::setCurrentSalary(int currentSalary)
{
    this->currentSalary = currentSalary;
}

int ProfileInfo::getCurrentSalary()
{
    return this->currentSalary;
}

void ProfileInfo::setCurrentBudget(int currentBudget)
{
    this->currentBudget = currentBudget;
}

int ProfileInfo::getCurrentBudget()
{
    return this->currentBudget;
}
