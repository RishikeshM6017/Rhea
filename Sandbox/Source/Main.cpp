#include <Logger.h>

int main()
{
	RFATAL("test message: %f", 3.14f);
	RERROR("test message: %f", 3.14f);
	RWARN("test message: %f", 3.14f);
	RINFO("test message: %f", 3.14f);
	RDEBUG("test message: %f", 3.14f);
	RTRACE("test message: %f", 3.14f);

	return 0;
}