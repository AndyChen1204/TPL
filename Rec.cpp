#include "Rec.h"

Rec::Rec(double _x1, double _x2, double _x3, double _x4,
                double _y1, double _y2, double _y3, double _y4)
{
    x1 = _x1;
    x2 = _x2;
    x3 = _x3;
    x4 = _x4;
    y1 = _y1;
    y2 = _y2;
    y3 = _y3;
    y4 = _y4;

    visit = false;
}

void Rec::plot(ofstream& ofs)
{
    ofs << "rectangle('Position', [";
    ofs << x1 << " ";
    ofs << y1 << " ";
    ofs << x3 - x1 << " ";
    ofs << y3 - y1 << " ";
    switch (rand() % 4) {
        case 0:
            ofs << "], 'FaceColor', [0 0 0])" << endl;
            break;
        case 1:
            ofs << "], 'FaceColor', [1 0 0])" << endl;
            break;
        case 2:
            ofs << "], 'FaceColor', [0 1 0])" << endl;
            break;
        case 3:
            ofs << "], 'FaceColor', [0 0 1])" << endl;
            break;
        default:
            break;
    }
}


