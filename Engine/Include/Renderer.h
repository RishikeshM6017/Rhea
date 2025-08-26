#pragma once

#include "PCH.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

public:
	VkResult InitializeInstance();
	VkResult GetPhysiclaDevice();
	VkResult GetSurface();
	VkResult InitializeDevice();
	VkResult CreateSwapchain();

	VkResult CreateImage();
	VkResult CreateImageViews();

	VkResult CreateSemaphore();
	VkResult CreateFence();
	VkResult CreateBarrier();

	VkResult GetRequiredExtensions();
	VkResult GetRequiredLayers();

private:
	VkInstance		 instance		= VK_NULL_HANDLE;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice		 device			= VK_NULL_HANDLE;
	VkSurfaceKHR	 surface		= VK_NULL_HANDLE;
	VkSwapchainKHR	 swapchain		= VK_NULL_HANDLE;

	Vector<VkImage>		images;
	Vector<VkImageView> imageViews;


};

