
#include "spreadClass.h"
#include <ctype.h>
#include <iostream>
#include <string>
#include <sstream> 

spreadClass();
~spreadClass();

void spreadClass::fillSpread()
{
   double ans = INT_MIN;
   for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < m; j++)
       {
           std::string strHere = spread[i][j];
           std::cout<<"curren String is "<<strHere<<std::endl;
            ans = fillSingleSpread(spread[i][j]);
           result[i][j] = ans;
       }
   }
}

static std::vector<std::string> splitBySpace(std::string s)
{
    std::vector<std::string> result;
    std::istringstream iss(s);
    for(std::string s; iss >> s; )
        result.push_back(s);

    return result;
}

double spreadClass::fillSingleSpread(std::string str)
{
    std::cout<<"fillSingleSpread is called"<<std::endl;
    std::cout<<"input string is "<<str<<std::endl;
    std::vector<std::string> splitStr = splitBySpace(str);
    double res = 0;
    std::vector<double> charsInstr;
    int i = 0;
    
    while(i < splitStr.size())
    {
        if (splitStr[i] == "+" || splitStr[i] == "-" || splitStr[i] == "/" || splitStr[i] == "*")
        {
            std::cout<<"the string is"<<splitStr[i]<<std::endl;
            std::cout<<"the size of the vector is "<<charsInstr.size()<<std::endl;
            std::cout<<"I'm popping out "<<charsInstr.back()<<std::endl;
            double num1 = charsInstr.back();
            charsInstr.pop_back();
            std::cout<<"I'm popping out "<<charsInstr.back()<<std::endl;
            double num2 = charsInstr.back();
             charsInstr.pop_back();
            if (splitStr[i] == "+")
                res = (num1 + num2);
            else if (splitStr[i] == "-")
                res = (num2 - num1);
            else if (splitStr[i] == "*")
                res = (num1 * num2);
            else if (splitStr[i] == "/")
                res = (num2 / num1);

            std::cout<<"I'm pushing"<<res<<std::endl;
            charsInstr.push_back(res);
        }
        else if ((splitStr[i])[0] >= 'A' && splitStr[i][0] <= 'Z')
        {
            std::cout<<"the string is"<<splitStr[i]<<std::endl;
            
            int row = (splitStr[i])[0] - 'A';
            int col = (splitStr[i])[1] - '0';
            std::cout<<"row and column are "<<row<<"and"<<col<<std::endl;
            if (result[row][col] != std::numeric_limits<double>::min()) {
                charsInstr.push_back(result[row][col]);

            } else
            {
                count++;
                if (count > 500)
                {
                    printf("this is error");
                    exit(5);
                }
                double tmp = fillSingleSpread(spread[row][col]);                   
                charsInstr.push_back(tmp);
            }
        }
        else
        {
            std::cout<<"the string is"<<splitStr[i]<<std::endl;
            int num = std::stoi (splitStr[i]);
            std::cout<<"it's a number and the number is "<<num<<std::endl;
            charsInstr.push_back(std::stoi (splitStr[i]));
        }

        i++;
    }

    count = 0;
    std::cout<<"output char is : "<<std::endl;
    for (int k = 0; k < charsInstr.size(); k++)
    {
        std::cout<< charsInstr[k] << std::endl;
    }
    
    return charsInstr[0];
}




