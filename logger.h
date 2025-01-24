#ifndef LOGGER_H_
#define LOGGER_H_

void initLogger();
void dLog(char* str, int level, ...);

#define LOG_ERROR(str, ...)   dLog(str, 0 __VA_OPT__(,) __VA_ARGS__)
#define LOG_WARNING(str, ...) dLog(str, 1 __VA_OPT__(,) __VA_ARGS__)
#define LOG_INFO(str, ...)    dLog(str, 2 __VA_OPT__(,) __VA_ARGS__)
#define LOG_DEBUG(str, ...)   dLog(str, 3 __VA_OPT__(,) __VA_ARGS__)

#endif
