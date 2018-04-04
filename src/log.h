#include <stdint.h>
#include <iostream>
#include <string>

namespace Log {

    enum class Level : uint8_t { trace, debug, info, warning, error, critical };

    template<typename... Args>
    void log_message(Level log_level, const char* message, Args... args); //TODO -- Add error types or error locations
    
} // namespace log

#define LOG(log_level, message, ...) \
    Log::log_message(log_level, message, __VA_ARGS__)
