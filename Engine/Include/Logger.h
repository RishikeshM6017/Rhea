#pragma once

#include "PCH.h"

#define LOG_WARN_ENABLED  1
#define LOG_INFO_ENABLED  1

#ifdef _DEBUG
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1
#else
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif


namespace Logger
{
	typedef enum LogLevel
	{
		LOG_LEVEL_FATAL = 0,
		LOG_LEVEL_ERROR = 1,
		LOG_LEVEL_WARN = 2,
		LOG_LEVEL_INFO = 3,
		LOG_LEVEL_DEBUG = 4,
		LOG_LEVEL_TRACE = 5
	} LogLevel;

	B8 Initialize();
	void Shutdown();

	RAPI void LogOutput(LogLevel level, const char* message, ...);
};

#define RFATAL(message, ...) Logger::LogOutput(Logger::LOG_LEVEL_FATAL, message, ##__VA_ARGS__)
#define RERROR(message, ...) Logger::LogOutput(Logger::LOG_LEVEL_ERROR, message, ##__VA_ARGS__)

#ifdef LOG_WARN_ENABLED
#define RWARN(message, ...)  Logger::LogOutput(Logger::LOG_LEVEL_WARN,  message, ##__VA_ARGS__)
#else
#define RWARN(message, ...)
#endif

#ifdef LOG_INFO_ENABLED
#define RINFO(message, ...)  Logger::LogOutput(Logger::LOG_LEVEL_INFO,  message, ##__VA_ARGS__)
#else
#define RINFO(message, ...)
#endif

#ifdef LOG_WARN_ENABLED
#define RDEBUG(message, ...) Logger::LogOutput(Logger::LOG_LEVEL_DEBUG, message, ##__VA_ARGS__)
#else
#define RDEBUG(message, ...)
#endif

#ifdef LOG_WARN_ENABLED
#define RTRACE(message, ...) Logger::LogOutput(Logger::LOG_LEVEL_TRACE, message, ##__VA_ARGS__)
#else
#define RTRACE(message, ...)
#endif

