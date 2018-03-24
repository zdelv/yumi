#include "log.h"


namespace Log {

    void LogMessage(Level log_level, const char* error) {
        
        const char* out = 0;
#define str(x) #x
#define LOG_PROCESS(l) case(l): out = #l; break;

        switch(log_level) {
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

#undef LOG_PROCESS
#undef str
        printf("'%s': %s\n", out, error);
    };   
}
