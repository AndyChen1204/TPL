#ifndef SHAPE_H
#define SHAPE_H 
#include <iostream>
#include <fstream>
#include <list>
#include "Rec.h"

using namespace std;

class Shape
{
    public:
        //Shape();
        ~Shape();
        void addNewRec(Rec*);
    
        double get_xmin() const {return xmin;}
        double get_xmax() const {return xmax;}
        double get_ymin() const {return ymin;}
        double get_ymax() const {return ymax;}
    
        void set_xmin(double temp){xmin = temp;}
        void set_xmax(double temp){xmax = temp;}
        void set_ymin(double temp){ymin = temp;}
        void set_ymax(double temp){ymax = temp;}
    
        list<Rec*>& getRecList(){return recList;}
        void plot(ofstream&);

    private:
        /* data */
        list<Rec*> recList;
        double xmin, xmax;
        double ymin, ymax;
};

#endif
