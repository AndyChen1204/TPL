#include "Shape.h"

void  Shape::addNewRec(Rec* rec)
{
    recList.push_back(rec);    
}

void Shape::plot(ofstream& ofs)
{
    list<Rec*>::iterator recIter;
    for (recIter = recList.begin(); recIter != recList.end(); ++recIter)
    {
        (*recIter) -> plot(ofs);
    }
}
