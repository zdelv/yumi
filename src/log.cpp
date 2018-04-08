#include "log.hpp"

namespace Log {

template <typename... Args>
void log_message(Level log_level, const char* message, Args... args)
{

    const char* out = nullptr;
#define LOG_PROCESS(l) \
    case (l):          \
        out = #l;      \
        break;

    switch (log_level)
    {
        LOG_PROCESS(Level::trace);
        LOG_PROCESS(Level::debug);
        LOG_PROCESS(Level::info);
        LOG_PROCESS(Level::warning);
        LOG_PROCESS(Level::error);
        LOG_PROCESS(Level::critical);
    default:
        printf("Invalid log level");
        break;
    }

    ((std::cout << out << ": " << message) << ... << args);

#undef LOG_PROCESS
};

// Creates templates for all of the current ways the log function is used.
// To add more, put the variadic args in the <> and ALL arguments, in order,
// in the ()
#define LOGVARS Level, const char*

template void log_message<int>(LOGVARS, int);
template void log_message<int, int>(LOGVARS, int, int);
template void log_message<const char*>(LOGVARS, const char*);
template void log_message<const char*, const char*>(LOGVARS, const char*,
                                                    const char*);
template void log_message<const char*, int>(LOGVARS, const char*, int);
template void log_message<int, const char*>(LOGVARS, int, const char*);

} // namespace Log
