#include <stdint.h>
#include <iostream>
#include <string>

namespace Log {

    enum class Level : uint8_t { trace, debug, info, warning, error, critical };

    void log_message(Level log_level, const char* error); //TODO -- Add error types or error locations
    
} // namespace log

#define LOG(log_level, log_error) \
    Log::log_message(log_level, log_error)
