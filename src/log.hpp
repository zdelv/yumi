#ifndef LOG_H
#define LOG_H
#include "types.hpp"
#include <iostream>
#include <string>

namespace Log {

enum class Level : u8
{
    trace,
    debug,
    info,
    warning,
    error,
    critical
};

template <typename... Args>
void log_message(Level log_level, const char* message,
                 Args... args); // TODO -- Add error types or error locations

} // namespace Log

#define LOG(log_level, message, ...) \
    Log::log_message(log_level, message, __VA_ARGS__)
#endif