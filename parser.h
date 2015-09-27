#ifndef PARSER_H
#define PARSER_H
#include <cassert>
#include <iostream>
#include <fstream>
#include "Rec.h"
#include "Shape.h"
#include <list>
#include <math.h>
#include <queue>

using namespace std;

extern list<Rec*>::iterator recIter1;
extern list<Rec*>::iterator recIter2;

bool compx(const Rec* num1, const Rec* num2);
bool compy(const Rec* num1, const Rec* num2);

void parser(const char* fileName, 
            list<Rec*>& recListx, 
            list<Rec*>& recListy, 
            list<Shape*>& shapeList, 
            string key);

#endif
