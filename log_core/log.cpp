#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

#include "log.h"

std::ofstream logFile;

void init_log()
{

    logFile.open("log.txt", std::ios::app);
    logFile << "----Start sesion----\n";
}

void shutdown_log()
{
    if (logFile.is_open())
    {
        logFile << "----End sesion----\n";
        logFile.close();
    }
}

std::string getCurrentTime()
{
    std::time_t now = std::time(nullptr);
    char buf[20];
    if (std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now)))
    {
       return std::string(buf); 
    }
    return "0000-00-00 00:00:00";
}

const char* getColor(LogLevel level)
{
    switch (level)
        {
            case LogLevel::DEBUG : return "\033[32m";
            case LogLevel::ERROR : return "\033[31m";
            case LogLevel::WARNING : return "\033[33m";
            default : return "\033[30m";
        }
}

const char* getLevel(LogLevel level)
{
        switch (level)
        {
            case LogLevel::DEBUG : return "[DEBUG]";
            case LogLevel::ERROR : return "[ERROR]";
            case LogLevel::WARNING : return "[WARNING]";
            default : return "NON"; 
        } 
}

void log_msg(LogLevel level, const char* fmt, LogOutput type)
{
    if(LogOutput::CONSOLELOG == type)
    {
        std::cout<< getColor(level) << getLevel(level) << " : " << fmt << "\033[0m" <<std::endl;
    }else if (LogOutput::TXTLOG == type)
    {
        logFile << "[" << getCurrentTime() << "]" << getLevel(level) << " : " << fmt <<std::endl;
        logFile.flush();
    }       
}