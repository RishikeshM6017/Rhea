#include "PCH.h"
#include "Logger.h"

B8 Logger::Initialize()
{
	//TODO: Create log file
	return true;
}

void Logger::Shutdown()
{
	//TODO: Cleanup logging and write queue entries
}

RAPI void Logger::LogOutput(LogLevel level, const char* message, ...)
{
	const char* levelString[6] = { "[FATAL]:", "[ERROR]:", "[WARN]: ", "[INFO]: ", "[DEBUG]:", "[TRACE]:" };

	B8 isError = level < 2;

	char outMessage[512];
	memset(outMessage, 0, sizeof(outMessage));

	va_list argPtr;
	va_start(argPtr, message);
	vsnprintf(outMessage, 512, message, argPtr);
	va_end(argPtr);

	char formattedMessage[512];
	sprintf_s(formattedMessage, sizeof(formattedMessage), "%s %s\n", levelString[level], outMessage);

	printf("%s", formattedMessage);
}
