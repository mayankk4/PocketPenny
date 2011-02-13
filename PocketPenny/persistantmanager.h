#ifndef PERSISTANTMANAGER_H
#define PERSISTANTMANAGER_H

#include <QSqlDatabase>
#include <QObject>
#include <QSqlError>
#include <QSqlQuery>
#include <QDate>
#include <QFile>

#include "Category.h"
#include "Expense.h"
#include "ProfileInfo.h"


class PersistantManager
{
public:
    PersistantManager();
    //PersistantManager(QObject *parent = 0);
    ~PersistantManager();

    bool openDB();
    bool initDB();
    bool deleteDB();

    int nextId();

    // for Expense Table
    int insertExpense(QString expCatName, float expAmount);
    bool viewExpense();

    // for Category Table
    int insertCategory(Category*);
    bool viewCategory();
    int getCatIdFromCatName(QString catName);

    // for UserProfile Table
    int insertProfileInfo(ProfileInfo*);
    bool viewProfileInfo();

    // for Months Table

    QSqlError lastError();

    bool createExpenseTable();
    bool createCategoryTable();
    bool createProfileInfoTable();
//    bool createMonthRecordTable();

private:
    QSqlDatabase db;
};

#endif // PERSISTANTMANAGER_H
