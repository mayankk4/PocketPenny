#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>
class Category
{
private:
    int catId;
    QString catName;
public:
    Category();
    Category(QString);
    void setCatId(int);
    int getCatId();
    void setCatName(QString);
    QString getCatName();
};

#endif // CATEGORY_H
