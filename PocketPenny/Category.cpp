#include "Category.h"

Category::Category()
{
    this->catId = 0;
    this->catName = "";
}

Category::Category(int catId, QString catName)
{
    this->catId = catId;
    this->catName = catName;
}

void Category::setCatId(int catId)
{
    this->catId = catId;
}

int Category::getCatId()
{
    return catId;
}

void Category::setCatName(QString catName)
{
    this->catName = catName;
}

QString Category::getCatName()
{
    return catName;
}
