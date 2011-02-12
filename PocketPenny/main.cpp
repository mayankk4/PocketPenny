#include <QtCore/QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    cout << "App starting ... "<<endl;

    // create database tables
    // connect to database
    // create user profile

    int option;

    while(1){
    cout << "Enter 1 to add expense"  << endl
         << "Enter 2 to view all expenses" << endl
         << "Enter 3 to edit an expense" << endl

         << "Enter 4 to add catagory" << endl
         << "Enter 5 to view all catagories" << endl
         << "Enter 6 to edit catagory" << endl

         << "Enter 7 to view user profile" << endl
         << "Enter 8 to edit user profile" << endl

         << "Enter 9 to view records of past months" << endl
         << "Enter 0 to exit" << endl;

    cin >> option; // edit includes edit and delete

    switch(option){

        case 1 :

            break;

        case 2 :

            break;

        case 3 :

            break;

        case 4 :

            break;

        case 5 :

            break;

        case 6 :

            break;

        case 7 :

            break;

        case 8 :

            break;

        case 9 :

            break;

        case 0 :

            break;

        default :

            break;

    }

  }
  return a.exec();
}
