#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdio.h>

#include "run.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

int runVulkan(void) {
	GLFWwindow* window = initWindow();
    initVulkan();
    mainLoop(window);
    cleanup(window);

	return 0;
}

int initVulkan(void) {

	return 0;
}

int mainLoop(GLFWwindow* window) {
	printf("[LOG] Initializing the main loop...\n");
	while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

	return 0;
}

int cleanup(GLFWwindow* window) {
	printf("[LOG] Starting cleanup...\n");
	glfwDestroyWindow(window);

    glfwTerminate();
	printf("[LOG] Cleanup finished!\n");

	return 0;
}

GLFWwindow* initWindow(void) {
	printf("[LOG] Starting the main window...\n");

	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", NULL, NULL);

	printf("[LOG] Main window was initialized!\n");

	return window;
}
