#include "Rec.h"
#include "Shape.h"
#include "parser.h"
#include <list>
#include <math.h>

using namespace std;

const string KEY = "box";

list<Rec*> recList_xDirection;
list<Rec*> recList_yDirection;
list<Rec*>::iterator recIter;

list<Shape*> shapeList;
list<Shape*>::iterator shapeIter;

int main(int argc, const char* argv[])
{
    srand((unsigned)time(NULL));
    parser(argv[1], recList_xDirection, recList_yDirection, shapeList, KEY);
    cout << "rec list in x direction #: " << recList_xDirection.size() << endl;
    cout << "rec list in y direction #: " << recList_yDirection.size() << endl;
    cout << "shape list #: " << shapeList.size() << endl;
    /*
    for (recIter = recList_xDirection.begin(); recIter != recList_xDirection.end(); recIter++) 
    {
       cout << (*recIter) -> neighborSize(); 
    }
    cout << endl;
     */
    ofstream ofs;
    ofs.open(argv[2]);
    assert(ofs);
    
    shapeIter = shapeList.begin();
    while ((*shapeIter) -> getRecList().size() != 8) {
        ++shapeIter;
    }
    (*shapeIter) -> plot(ofs);
    
    /*
    for (shapeIter = shapeList.begin(); shapeIter != shapeList.end(); ++shapeIter)
    {
        cout << (*shapeIter) -> getRecList().size() << endl;
        (*shapeIter) -> plot(ofs);
    }
    */
}

