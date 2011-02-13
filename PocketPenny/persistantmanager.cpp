#include <QVariant>
#include "iostream"

#include "Category.h"
#include "Expense.h"
#include "ProfileInfo.h"
#include "persistantmanager.h"

using namespace std;

PersistantManager::PersistantManager()
{


}

bool PersistantManager::openDB()
    {
    // Find QSLite driver
    db = QSqlDatabase::addDatabase("QSQLITE");

    // NOTE: File exists in the application private folder, in Symbian Qt implementation
    db.setDatabaseName("pocketpenny.db.sqlite");
    cout<<"database created"<<endl;


    // createProfileInfoTable()
    // createMonthRecordTable())

    // Open databasee
    return db.open();
    }

QSqlError PersistantManager::lastError()
    {
    // If opening database has failed user can ask
    // error description by QSqlError::text()
    return db.lastError();
    }

bool PersistantManager::deleteDB()
    {
    // Close database
    db.close();

    // Remove created database binary file
    return QFile::remove("pocketpenny.db.sqlite");
    }

bool PersistantManager::createCategoryTable()
{
    // Create table "category"
    bool ret = false;

    cout<<" creating category table. DB " <<db.isOpen()<<endl;
    if (db.isOpen())
        {cout<<" creating category table" <<endl;
        QSqlQuery query;
        ret = query.exec("create table category "
                  "(catid integer primary key, "
                  "catname varchar(30)); "
                  );

        }
    return ret;

}

int PersistantManager::insertCategory(Category* passCat)
    {
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
        {
        //http://www.sqlite.org/autoinc.html
        // NULL = is the keyword for the autoincrement to generate next value
        QSqlQuery query;
        ret = query.exec(QString("insert into category values(NULL,'%1')")
        .arg(passCat->getCatName()));

        // Get database given autoincrement value
        if (ret)
            {
            // http://www.sqlite.org/c3ref/last_insert_rowid.html
            newId = query.lastInsertId().toInt();
            }

        }
    return newId;
    }

bool PersistantManager::viewCategory()
{

    bool ret = false;
    cout << "Inside view cat" << endl;
    if (db.isOpen())
    {
        cout<<"DB open trying to view cat-values "<<endl;
        QSqlQuery query(QString("select * from category") );
        cout<< query.size();
        while(query.next())
            {
            cout << "Inside view cat query.next" << endl;
            QString opt =  query.value(1).toString();
            cout <<  qPrintable(opt)<< endl;
            ret = true;
            }
    }


    return ret;

}

bool PersistantManager::createExpenseTable()
    {
    // Create table "expense"

    bool ret1 = false;
    bool ret2 = false;
    bool ret3 = false;

    if (db.isOpen())
        {
        QSqlQuery query;

        ret1 = query.exec("create table expense "
                  "(expid integer primary key, "
                  "exptime TIME, "
                  "expdate DATE, "
                  "catid varchar(30 "
                  "amount float);"
                  " FOREIGN KEY(catid) REFERENCES category(catid)"
                  );

        ret2 = query.exec("CREATE TRIGGER insert_expense_exptime"
                  "AFTER  INSERT ON expense"
                  "BEGIN"
                  "UPDATE expense SET exptime = TIME('NOW')"
                  "WHERE expid = new.expid;"
                  "END;");

        ret3 = query.exec("CREATE TRIGGER insert_expense_expDate"
                  "AFTER  INSERT ON expense "
                  "BEGIN"
                  "UPDATE expense SET  expdate = DATE('NOW')"
                  "WHERE expid = new.expid;"
                  "END; ");
        }
    return (ret1&&ret2&&ret3);
    }


int PersistantManager::insertExpense(Expense* passExp)
    {
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
        {
        //http://www.sqlite.org/autoinc.html
        // NULL = is the keyword for the autoincrement to generate next value

        QSqlQuery query;
        ret = query.exec(QString("insert into Expense values(NULL,'%1','%2',%3,%4)")
        .arg(passExp->getExpDate().toString()).arg(passExp->getExpxpTime().toString())
        .arg(passExp->getCatId()).arg(passExp->getAmount())
        );

        // Get database given autoincrement value
        if (ret)
            {
            // http://www.sqlite.org/c3ref/last_insert_rowid.html
            newId = query.lastInsertId().toInt();
            }

        }
    return newId;
    }


