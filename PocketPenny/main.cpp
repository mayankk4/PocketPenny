#include <QtCore/QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QStringList>
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

bool editProfile()
{
    bool ret = false;
    QFile file("userprofile.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);

    QString line;
    //while((line = f.readLine()) != EOF)
    line = in.readLine();
    QStringList namepair = line.split("=");

    line = in.readLine();
    QStringList salarypair = line.split("=");

    line = in.readLine();
    QStringList budgetpair = line.split("=");

    file.close();

    cout<<"What do u want to edit ?? "<<endl;
    cout<<"1. Your name "<<namepair.at(1)<<endl;
    cout<<"2. Your currentsalary "<<salarypair.at(1)<<endl;
    cout<<"3. Your currentbudget "<<budgetpair.at(1)<<endl;
    cout<<"Enter your choice e.g 1 "<<endl;

    int option;
    cin>>option;
    while(option < 1 || option > 3)
    {
        cout<<" Invalid Option !!! Choose again"<<endl;
        cout<<"What do u want to edit ?? "<<endl;
        cout<<"1. Your name "<<namepair.at(1)<<endl;
        cout<<"2. Your currentsalary "<<salarypair.at(1)<<endl;
        cout<<"3. Your currentbudget "<<budgetpair.at(1)<<endl;
        cout<<"Enter your choice e.g 1 "<<endl;
        cin>>option;
    }
    QTextStream qtin(&file);
    file.open(stdin, QIODevice::ReadOnly);
    QString changedvar;
    if(option == 1)
    {
        cout<<"Enter your name"<<endl;
        qtin>>changedvar;
        if(changedvar != "")
            namepair.replace(1,changedvar);
    }
    else if(option == 2)
    {
        cout<<"Enter your current salary"<<endl;
        qtin>>changedvar;
        if(changedvar != "")
            salarypair.replace(1,changedvar);
    }

    else
    {
        cout<<"Enter your current budget"<<endl;
        qtin>>changedvar;
        if(changedvar != "")
            budgetpair.replace(1,changedvar);
    }
    file.close();

    //cout<<" name "<<namepair.at(1)<<endl;
    QFile fileop("userprofile.txt");
    fileop.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&fileop);
    out <<namepair.at(0) + " = " + namepair.at(1)<<endl;
    out <<salarypair.at(0) + " = " + salarypair.at(1)<<endl;
    out <<budgetpair.at(0) + " = " + budgetpair.at(1)<<endl;
    //out <<salarypair<<endl;
    //out <<budgetpair<<endl;
    file.close();
    return ret;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "App starting ... "<<endl;

    cout << "Creating Database connection ... " << endl;

    PersistantManager* pm = new PersistantManager();

    cout<<"Opening Db :" << (pm->openDB() ? " Successful" : " Failed") << endl;

    cout<<"Initializing Db " << endl;
    pm->initDB();

    cout << "DB Initialised" << endl;

    cout << "Connections created Successfully ... " << endl << endl;

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
         << "Enter 0 to exit" << endl << endl;

    int option;
    cin >> option; // edit includes edit and delete

    QString catName, expCatName;
    int lastCatId, lastExpId;
    float expAmount;
    QFile file;

    Category* passCat;

    QTextStream qtin(&file);
    file.open(stdin, QIODevice::ReadOnly);
	

    switch(option){

        case 1 :
            pm->viewCategory();

            cout << "Enter expense category name : " << endl;
            qtin >> expCatName;
            cout << "the name u entered is : " << qPrintable(expCatName) <<endl;

            cout << "Enter expense amount : " << endl;
            qtin >> expAmount;            
            cout << "the amount u entered is : " << expAmount <<endl;

            lastExpId = pm->insertExpense(expCatName, expAmount);
            break;

        case 2 :
            cout << "Showing all expenses :" << endl;
            pm->viewExpense();
            break;

        case 3 :

            break;

        case 4 :
            cout << "Enter category name :";

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
            pm->viewProfileInfo();
            break;

        case 8 :
            editProfile();
            break;

        case 9 :

        case 0 :

        default :

              break;

    }

  }
  return a.exec();

}
