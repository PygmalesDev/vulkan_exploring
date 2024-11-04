#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdio.h>

#include "run.h"
#include "instances.h"
#include "logger.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

VkInstance instance;
GLFWwindow* window;

int runVulkan(void) {
	initWindow();
    initVulkan();
    mainLoop();
    cleanup();

	return 0;
}

int initVulkan(void) {
	logmsg("Initializing instance creation...");
	instance = createInstance();
	if (!instance) {
		printf("[ERR] Instance creation failed!\n");
		return 1;
	}
	logmsg("Instance creation finished successfully!");
	return 0;
}

int mainLoop(void) {
	logmsg("Initializing the main loop...");
	while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

	return 0;
}

int cleanup(void) {
	logmsg("Starting cleanup...");
	glfwDestroyWindow(window);
    glfwTerminate();

	vkDestroyInstance(instance, NULL);
	logmsg("Cleanup finished!");

	return 0;
}

int initWindow(void) {
	logmsg("Starting the main window...");

	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", NULL, NULL);
	if (!window) {
		return 1;
	}

	logmsg("Main window was initialized!");
	return 0;
}
