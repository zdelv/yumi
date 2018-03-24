#include <stdint.h>
#include <iostream>
#include <string>

namespace Log {

    enum class Level : uint8_t { trace, debug, info, warning, error, critical };

    void LogMessage(Level log_level, const char* error); //TODO -- Add error types or error locations
} // namespace log

