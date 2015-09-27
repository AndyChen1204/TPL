#include "parser.h"

list<Rec*>::iterator recIter1;
list<Rec*>::iterator recIter2;

bool compx(const Rec* num1, const Rec* num2)
{
    return num1 -> get_x1() < num2 -> get_x1();
}

bool compy(const Rec* num1, const Rec* num2)
{
    return num1 -> get_y1() < num2 -> get_y1();
}

void parser(const char* fileName, 
            list<Rec*>& recListx, 
            list<Rec*>& recListy, 
            list<Shape*>& shapeList, 
            string key)
{
    ifstream ifs;
    ifs.open(fileName);
    assert(ifs);

    string sTemp;
    getline(ifs, sTemp);  
    getline(ifs, sTemp);  
    getline(ifs, sTemp);  
    getline(ifs, sTemp);  
    getline(ifs, sTemp);  
    getline(ifs, sTemp);  

    ifs >> sTemp;
    assert(sTemp == key);

    while(sTemp == key)
    {
        getline(ifs, sTemp);
        getline(ifs, sTemp);
        getline(ifs, sTemp);

        ifs >> sTemp >> sTemp;
        assert(sTemp == "5");
        double x1,x2,x3,x4;
        double y1,y2,y3,y4;

        ifs >> x1 >> y1;
        ifs >> x2 >> y2;
        ifs >> x3 >> y3;
        ifs >> x4 >> y4;

        Rec* recTemp = new Rec(x1,x2,x3,x4,y1,y2,y3,y4);
        recListx.push_back(recTemp);
        recListy.push_back(recTemp);

        ifs >> sTemp >> sTemp;
        ifs >> sTemp >> sTemp;
    }

    recListx.sort(compx);
    recListy.sort(compy);

    recIter1 = recListx.begin(); 
    recIter2 = recListx.begin();
    
    //add neighbor in x direction
    while (recIter1 != recListx.end()) 
    {
        ++recIter2;
        while (recIter2 != recListx.end() && 
               (*recIter2) -> get_x1() <= (*recIter1) -> get_x3())
        {
            if(fabs((*recIter1) -> get_y1() - (*recIter2) -> get_y3()) == 0 || 
               fabs((*recIter1) -> get_y3() - (*recIter2) -> get_y1()) == 0)
            {
                (*recIter2) -> addNeighbor(*recIter1);
                (*recIter1) -> addNeighbor(*recIter2);
            }
            ++recIter2;
        }
        ++recIter1;
        recIter2 = recIter1;
    }
    
    recIter1 = recListy.begin();
    recIter2 = recListy.begin();
    
    //add neighbor in y direction
    while (recIter1 != recListy.end())
    {
        ++recIter2;
        while (recIter2 != recListy.end() && 
               (*recIter2) -> get_y1() <= (*recIter1) -> get_y3())
        {
            if(fabs((*recIter1) -> get_x1() - (*recIter2) -> get_x3()) == 0 ||
               fabs((*recIter1) -> get_x3() - (*recIter2) -> get_x1()) == 0)
            {
                (*recIter2) -> addNeighbor(*recIter1);
                (*recIter1) -> addNeighbor(*recIter2);
            }
            ++recIter2;
        }
        ++recIter1;
        recIter2 = recIter1;
    }
    
    //create shape
    queue<Rec*> bfs;
    
    for (recIter1 = recListx.begin(); recIter1 != recListx.end(); recIter1++)
    {
        if ((*recIter1) -> get_visit() == false)
        {
            Shape* stemp;
            stemp = new Shape;
            
            (*recIter1) -> set_visit(true);
            
            stemp -> set_ymin((*recIter1) -> get_y1());
            stemp -> set_ymax((*recIter1) -> get_y3());
            stemp -> set_xmin((*recIter1) -> get_x1());
            stemp -> set_xmax((*recIter1) -> get_x3());
            
            stemp -> addNewRec(*recIter1);
            
            bfs.push((*recIter1));
            long index1=0,index2=1;
            while (bfs.empty() != 1)
            {
                for (int i = 0; i < index2; i++)
                {
                    for (recIter2 = bfs.front() -> getNeighborList().begin(); 
                         recIter2 != bfs.front() -> getNeighborList().end(); 
                         recIter2++)
                    {
                        if ((*recIter2) -> get_visit() == false) {
                            (*recIter2) -> set_visit(true);
                            if ((*recIter2) -> get_y1() < stemp -> get_ymin())
                                stemp -> set_ymin((*recIter2) -> get_y1());
                            if ((*recIter2) -> get_y3() > stemp -> get_ymax())
                                stemp -> set_ymax((*recIter2) -> get_y3());
                            if ((*recIter2) -> get_x1() < stemp -> get_xmin())
                                stemp -> set_xmin((*recIter2) -> get_x1());
                            if ((*recIter2) -> get_x3() > stemp -> get_xmax())
                                stemp -> set_xmax((*recIter2) -> get_x3());
                            
                            bfs.push((*recIter2));
                            stemp -> addNewRec(*recIter2);
                            index1++;
                        }
                    }
                    bfs.pop();
                }
                if(bfs.empty() == 1)break;
                index2 = 0;
                for (int i = 0; i < index1; i++)
                {
                    for (recIter2 = bfs.front() -> getNeighborList().begin(); 
                         recIter2 != bfs.front() -> getNeighborList().end(); 
                         recIter2++)
                    {
                        if ((*recIter2) -> get_visit() == false) {
                            (*recIter2) -> set_visit(true);
                            if ((*recIter2) -> get_y1() < stemp -> get_ymin())
                                stemp -> set_ymin((*recIter2) -> get_y1());
                            if ((*recIter2) -> get_y3() > stemp -> get_ymax())
                                stemp -> set_ymax((*recIter2) -> get_y3());
                            if ((*recIter2) -> get_x1() < stemp -> get_xmin())
                                stemp -> set_xmin((*recIter2) -> get_x1());
                            if ((*recIter2) -> get_x3() > stemp -> get_xmax())
                                stemp -> set_xmax((*recIter2) -> get_x3());
                            
                            bfs.push((*recIter2));
                            stemp -> addNewRec(*recIter2);
                            index2++;
                        }
                    }
                    bfs.pop();
                }
                index1 = 0;
            }
            shapeList.push_back(stemp);
        }
    }
}
