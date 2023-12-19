#include "CurrentMoney.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace Towerdefense
{
    CurrentMoney::CurrentMoney(int currentmoney) : currentmoney(currentmoney){} //member initialization in constructors(the stuff behind a colon)

    inline int CurrentMoney::sum(int getaleen, int getaltwee)
    {
        try
        {
            currentmoney = getaleen + getaltwee;

            
            if (currentmoney < 0)  
            {
                
                throw std::out_of_range("Result is negative");
            }

            
            return currentmoney;
        }
        catch (const std::exception& e)
        {
            
            std::ofstream errorFile("error_log_twee.txt", std::ios_base::app);

           
            if (errorFile.is_open())
            {
                
                errorFile << "Exception caught while initializing the game: " << e.what() << std::endl;
                
                errorFile.close();
            }
            else
            {
                
                std::cerr << "Failed to open the error log file!" << std::endl;
            }

            throw;
        }
    }
    inline int CurrentMoney::subtract(int getaleen, int getaltwee)
    {
        currentmoney = getaleen - getaltwee;
        return currentmoney;
    }
}
