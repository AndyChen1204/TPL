#ifndef REC_H
#define REC_H
#include <iostream>
#include <fstream>
#include <list>


using namespace std;

class Rec
{
    public:
        Rec( double x1, double x2, double x3, double x4,
                double y1, double y2, double y3, double y4 );
        ~Rec();
    
        double get_x1() const {return x1;}
        double get_y1() const {return y1;}
        double get_x2() const {return x2;}
        double get_y2() const {return y2;}
        double get_x3() const {return x3;}
        double get_y3() const {return y3;}
        double get_x4() const {return x4;}
        double get_y4() const {return y4;}
    
        void set_visit(bool temp){visit = temp;}
        bool get_visit(){return visit;}
    
        void addNeighbor(Rec* rec){neighbor.push_back(rec);}
        int neighborSize(){return neighbor.size();}
        list<Rec*>& getNeighborList(){return neighbor;}
    
        void plot(ofstream& ofs);
    
    private:
        /* data */
        double x1, x2, x3, x4;
        double y1, y2, y3, y4;
        list<Rec*> neighbor;
        bool visit;
};

#endif
