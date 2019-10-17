//
// Created by Golnaz Ghodoosipour on 2019-10-11.
//

#ifndef UNTITLED_SPREADCLASS_H
#define UNTITLED_SPREADCLASS_H

#include <iostream>
#include <vector>

class spreadClass
{
private:

    //std::ifstream file;

public:
    int m;
    int n;
    int count = 0;
    std::vector<std::vector<double> > result;
    std::vector<std::vector<std::string> > spread;
    void readSpread();
    void outputSpread();
    void fillSpread();
    double fillSingleSpread(std::string str);
};


#endif //UNTITLED_SPREADCLASS_H
