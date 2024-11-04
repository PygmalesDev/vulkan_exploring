#include <stdio.h>
#include <stdlib.h>

#include "run.h"
#include "logger.h"

int main() {
    int result = runVulkan();

	if (result == 0) {
		logmsg("Execution finished gracefully!");
		return 0;
	}
	logerr("Execution failed!");
	return 1;
}
