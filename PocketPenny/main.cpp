#include <QtCore/QCoreApplication>
#include <QTextStream>
#include <QFile>

#include <iostream>
#include "ProfileInfo.h"
#include "Category.h"
#include "Expense.h"
#include "persistantmanager.h"

using namespace std;


basic_ostream<char>& operator<<(std::basic_ostream<char>& os, const QString& str)
{
   return os << qPrintable(str);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "App starting ... "<<endl;

    cout << "Creating Database connection ... " << endl;

    PersistantManager* pm = new PersistantManager();

    cout<<"Opening Db :" << (pm->openDB() ? "Successful" : "Failed") << endl;
    cout<<"Initializing Db " << endl;

    cout << "Connection created Successfully ... " << endl;

    while(1){
    cout << "Enter 1 to add expense"  << endl
         << "Enter 2 to view all expenses" << endl
         << "Enter 3 to edit an expense" << endl

         << "Enter 4 to add category" << endl
         << "Enter 5 to view all catagories" << endl
         << "Enter 6 to edit category" << endl

         << "Enter 7 to view user profile" << endl
         << "Enter 8 to edit user profile" << endl

         << "Enter 9 to view records of past months" << endl
         << "Enter 0 to exit" << endl;

    int option;
    cin >> option; // edit includes edit and delete

    QString catName;
    QFile file;
    Category* passCat;
    QTextStream qtin(&file);
    int lastCatId;

    switch(option){

        case 1 :
            /*
            cout << "Enter expense date :";
            file.open(stdin, QIODevice::ReadOnly);
            qtin >> expDate;

            cout << "Enter expense time :";
            file.open(stdin, QIODevice::ReadOnly);
            qtin >> expTime;

            cout << "Enter expense category name :";
            file.open(stdin, QIODevice::ReadOnly);
            qtin >> expCatName;

            cout << "Enter expense amount :";
            file.open(stdin, QIODevice::ReadOnly);
            qtin >> expAmount;

            passCat = new Category(catName);
            lastCatId = pm->insertCategory(passCat);
            */


            break;




        case 2 :

        case 3 :

            break;

        case 4 :
            cout << "Enter category name :";

            file.open(stdin, QIODevice::ReadOnly);
            qtin >> catName;

            passCat = new Category(catName);
            lastCatId = pm->insertCategory(passCat);

            cout<<" last inserted category id "<<lastCatId<<endl;
            break;

        case 5 :
            pm->viewCategory();
            break;

        case 6 :

        case 7 :

        case 8 :

        case 9 :

        case 0 :

        default :

              break;

    }

  }
  return a.exec();

}
