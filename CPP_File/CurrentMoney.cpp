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
            // Calculate the sum of two values
            currentmoney = getaleen + getaltwee;

            // Check if the result is negative and throw an exception if so
            if (currentmoney < 0)  
            {
                
                throw std::out_of_range("Result is negative");
            }

            
            return currentmoney;
        }
        catch (const std::exception& e)
        {
            // Handle the exception by logging it to a file
            std::ofstream errorFile("error_log_twee.txt", std::ios_base::app);

            // Check if the error log file is open and write the exception details
            if (errorFile.is_open())
            {
                // Check if the error log file is open and write the exception details
                errorFile << "Exception caught while initializing the game: " << e.what() << std::endl;
                
                errorFile.close();
            }
            else
            {
                // Print an error message to the standard error stream if the file cannot be opened
                std::cerr << "Failed to open the error log file!" << std::endl;
            }
            // Re-throw the exception after logging
            throw;
        }
    }
    // Method definition to subtract one value from another
    inline int CurrentMoney::subtract(int getaleen, int getaltwee)
    {
        currentmoney = getaleen - getaltwee;
        return currentmoney;
    }
}
