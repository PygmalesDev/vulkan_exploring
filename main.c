#include <stdio.h>
#include <stdlib.h>

#include "run.h"

int main() {
    int result = runVulkan();

	if (result == 0) {
		printf("[LOG] Execution finished gracefully!\n");
		return 0;
	}
	printf("[ERR] Execution failed!\n");
	return 1;
}
