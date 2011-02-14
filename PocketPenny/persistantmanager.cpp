#include <QVariant>
#include <QDate>
#include <QTime>

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

    return db.open();
    }

bool PersistantManager::initDB()
{
   bool ret1 = createCategoryTable();
   bool ret2 = createExpenseTable();
  // bool ret3 = createProfileInfoTable();
   return (ret1&&ret2);
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

/***********************************************************/

bool PersistantManager::createCategoryTable()
{
    // Create table "category"
    bool ret = false;

    cout<<"Creating category table. DB " <<db.isOpen()<<endl;

    if (db.isOpen())
        {
        QSqlQuery query;

        ret = query.exec("create table category "
                  "(catid integer primary key, "
                  "catname varchar(30)); "
                  );

        }


    cout <<" Catagory table status : " << ret << endl;
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
        .arg(passCat->getCatName())
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

bool PersistantManager::viewCategory()
{

    bool ret = false;
    cout << "Catagories are :" << endl;
    if (db.isOpen())
    {
        QSqlQuery query(QString("select * from category") );

        while(query.next())
            {
            QString opt =  query.value(1).toString();
            cout <<  qPrintable(opt)<< endl;
            ret = true;
            }
    }


    return ret;

}

int PersistantManager::getCatIdFromCatName(QString catName)
{
    int id;
    QSqlQuery query(QString("select catid from category where catname = '%1'")
                    .arg(catName) );

    if(query.next())
    {
        id = query.value(0).toInt();
    }

    return id;
}

/***********************************************************/

bool PersistantManager::createExpenseTable()
    {
    // Create table "expense"

    bool ret = false;

    cout<<"Creating expense table. DB " << db.isOpen() << endl;

    if (db.isOpen())
        {
        QSqlQuery query;

        ret = query.exec("create table expense "
                  "(expid integer primary key, "
                  "exptime TEXT, "
                  "expdate TEXT, "
                  "catid varchar(30), "
                  "amount float,"
                  " FOREIGN KEY(catid) REFERENCES category(catid));"
                  );

/*        ret2 = query.exec("CREATE TRIGGER insert_expense_exptime"
                  "AFTER  INSERT ON expense"
                  "BEGIN"
                  "UPDATE expense SET exptime = TIME('NOW')"
                  "WHERE expid = new.expid;"
                  "END;");

        ret3 = query.exec("CREATE TRIGGER insert_expense_expdate"
                  "AFTER  INSERT ON expense "
                  "BEGIN"
                  "UPDATE expense SET  expdate = DATE('NOW')"
                  "WHERE expid = new.expid;"
                  "END; ");
*/

        }

    cout <<" Expense table status : " << ret << endl;

    return ret;
    }

int PersistantManager::insertExpense(QString expCatName, float expAmount)
    {
    int newId = -1;
    int expCatId;

    bool ret = false;

    expCatId = getCatIdFromCatName(expCatName);

    if (db.isOpen())
        {
        //http://www.sqlite.org/autoinc.html
        // NULL = is the keyword for the autoincrement to generate next value

        cout << qPrintable(QTime::currentTime().toString()) << endl
             << qPrintable(QDate::currentDate().toString()) << endl;

        QSqlQuery query;
        ret = query.exec(QString("insert into expense values(NULL,'%1','%2',%3,%4)")
                         .arg(QTime::currentTime().toString())
                         .arg(QDate::currentDate().toString())
                         .arg(expCatId)
                         .arg(expAmount)
                         );

        cout << "insert expense ret " << ret << endl << endl;

        // Get database given autoincrement value
        if (ret)
            {
            // http://www.sqlite.org/c3ref/last_insert_rowid.html
            newId = query.lastInsertId().toInt();
            }

        }
    return newId;
    }

bool PersistantManager :: viewExpense(){

    bool ret = false;
    cout << "Expenses are :" << endl;

    if (db.isOpen())
    {
        QSqlQuery query(QString("select * from expense") );

        while(query.next())
            {
            cout << "expense : " << endl;
            int expId =  query.value(0).toInt();
            cout << expId << endl;

            QString expTime =  query.value(1).toString();
            cout <<  qPrintable(expTime) << endl;

            QString expDate =  query.value(2).toString();
            cout <<  qPrintable(expDate) << endl;

            int expCatId =  query.value(3).toInt();
            cout <<  expCatId << endl;

            int amount =  query.value(4).toInt();
            cout <<  amount << endl;

            ret = true;
            }
    }


    return ret;

}


/***********************************************************/

//bool PersistantManager::createProfileInfoTable()
//{
//    // Create table "profileinfo"
//    bool ret = false;

//    cout<<"Creating profileinfo table. DB " <<db.isOpen()<<endl;
//    if (db.isOpen())
//        {
//        QSqlQuery query;

//        ret = query.exec("create table profileinfo "
//                  "(proid integer primary key, "
//                  "name varchar(30),"
//                  "currentsalary integer,"
//                  "currentbudget integer)"
//                  );

//        }

//    cout<<" Profileinfo table status : " << ret << endl;

//    return ret;

//}

//int PersistantManager::insertProfileInfo(ProfileInfo* passPI)
//    {
//    int newId = -1;
//    bool ret = false;
//    cout<<" Inside insertprofile()"<<endl;
//    if (db.isOpen())
//        {

//        // NULL = is the keyword for the autoincrement to generate next value
//        cout<<"Inserting profileinfo "<<qPrintable(passPI->getName())<<" "<<passPI->getCurrentSalary()<<" "<<passPI->getCurrentBudget()<<endl;
//        QSqlQuery query;
//        ret = query.exec(QString("insert into profileinfo values(NULL,'%1',%2,%3)")
//        .arg(passPI->getName()).arg(passPI->getCurrentSalary()).arg(passPI->getCurrentBudget()) );
//        cout<<" insert profile insert() status "<<ret<<endl;
//        // Get database given autoincrement value
//        if (ret)
//            {
//            cout<<" Values inserted in profileinfo"<<endl;
//            // http://www.sqlite.org/c3ref/last_insert_rowid.html
//            newId = query.lastInsertId().toInt();
//            }

//        }
//    return newId;
//    }

//bool PersistantManager::viewProfileInfo()
//{

//    bool ret = false;
//    cout << "ProfileInfo :" << endl;
//    if (db.isOpen())
//    {
//        QSqlQuery query(QString("select * from profileinfo") );

//        while(query.next())
//            {
//            QString opt =  query.value(1).toString();
//            cout <<  qPrintable(opt)<< endl;
//            ret = true;
//            }
//    }


//    return ret;

//}
