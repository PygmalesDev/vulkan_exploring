#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "instances.h"
#include "logger.h"

VkInstance createInstance(void) {
	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;

	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	printExtensions();

	// Variable that stores the handle to the object instance
	VkInstance instance;

	// Optional information about the application
	VkApplicationInfo appInfo = {
		.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
		.pApplicationName = "Hello Triangle",
		.applicationVersion = VK_MAKE_VERSION(1, 0, 0),
		.pEngineName = "No Engine",
		.engineVersion = VK_MAKE_VERSION(1, 0, 0),
		.apiVersion = VK_API_VERSION_1_0
	};
	
	// Creation info
	VkInstanceCreateInfo createInfo = {
		.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		.pApplicationInfo = &appInfo,
		.enabledExtensionCount = glfwExtensionCount,
		.ppEnabledExtensionNames = glfwExtensions,
		.enabledLayerCount = 0
	};

	VkResult result = vkCreateInstance(&createInfo, NULL, &instance);
	
	if (result != VK_SUCCESS) return NULL;
	return instance;
}

void printExtensions(void) {
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, NULL);
	VkExtensionProperties* extensions = malloc(sizeof(VkExtensionProperties)*extensionCount);

	vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, extensions);
	
	loginfo("Available extensions: ");

	for (int i = 0; i < extensionCount; i++) {
		char* msg = calloc(strlen("\t- ") + strlen(extensions[i].extensionName)+1, sizeof(char));
		sprintf(msg, "\t- %s", extensions[i].extensionName);
		logsilent(msg);

		free(msg);
	}

	free(extensions);
}
