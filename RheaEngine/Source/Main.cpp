#include "PCH.h"

#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>


const int window_width  = 540;
const int window_height = 540;


int main()
{
	//Initialization
	
	//GLFW

	assert(glfwInit() == GLFW_TRUE);
	assert(glfwVulkanSupported() == GLFW_TRUE);

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	GLFWwindow* window = NULL; 
	
	window = glfwCreateWindow(window_width, window_height, "Sandbox", NULL, NULL);
	assert(window != NULL);

	//Vulkan::AppInfo

	U32 apiVersion = 0;
	vkEnumerateInstanceVersion(&apiVersion);
	apiVersion &= ~0xFFFU;

	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pNext = nullptr;
    appInfo.pApplicationName	= "Sandbox";
    appInfo.applicationVersion	= VK_MAKE_API_VERSION(0, 1, 0, 0);
    appInfo.pEngineName			= "Rhea";
    appInfo.engineVersion		= VK_MAKE_API_VERSION(0, 1, 0, 0);
    appInfo.apiVersion			= apiVersion;

	//Vulkan::Instance

	Vector<const char*> layers = {};
	Vector<const char*> extensions = {};

	VkInstanceCreateInfo instanceInfo = {};
	instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceInfo.pNext = nullptr;
    instanceInfo.flags = 0;
    instanceInfo.pApplicationInfo			= &appInfo;
    instanceInfo.enabledLayerCount			= U32(layers.size());
    instanceInfo.ppEnabledLayerNames		= layers.data();
    instanceInfo.enabledExtensionCount		= U32(extensions.size());
    instanceInfo.ppEnabledExtensionNames	= extensions.data();

	VkInstance instance = VK_NULL_HANDLE;
	vkCreateInstance(&instanceInfo, nullptr, &instance);



	//Main Loop

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}


	//Shutdown

	//Vulkan::Cleanup
	vkDestroyInstance(instance);

	glfwDestroyWindow(window);

	glfwTerminate();
}