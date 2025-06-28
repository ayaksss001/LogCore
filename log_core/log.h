#pragma once

enum LogLevel
{
    DEBUG,
    ERROR,
    WARNING
};

enum LogOutput
{
    GLLOG,
    CONSOLELOG,
    TXTLOG
};

void log_msg(LogLevel level, const char* fmt, LogOutput type);
void init_log();
void shutdown_log();
std::string getCurrentTime();
