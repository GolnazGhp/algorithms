#include <iostream>

#include <queue>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include "spreadClass.h"

    int main()
    {
        spreadClass sp;
        sp.n = 2;
        sp.m = 3;
        std::vector<std::string> x = {"A2", "4 5 *", "A1"};
        std::vector<std::string> y = {"A1 B2 / 2 +", "3", "39 B1 B2 * /"};
        (sp.spread).push_back(x);
        (sp.spread).push_back(y);

        std::vector<double> x2;
        x2.push_back(std::numeric_limits<double>::min());
        x2.push_back(std::numeric_limits<double>::min());
        x2.push_back(std::numeric_limits<double>::min());

        std::vector<double> y2;
        y2.push_back(std::numeric_limits<double>::min());
        y2.push_back(std::numeric_limits<double>::min());
        y2.push_back(std::numeric_limits<double>::min());

        (sp.result).push_back(y2);

        sp.fillSpread();

        std::cout<<"print the result"<<std::endl;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cout<<sp.result[i][j]<<std::endl;
            }
        }

        return 0;
    }
