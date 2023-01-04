#include "muchcool/rndr/graphics_context.hpp"

#include <vector>
#include <array>

namespace muchcool::rndr {

  auto create_instance() -> VkInstance {
    auto create_info = VkInstanceCreateInfo{
      .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
    };

    auto instance = VkInstance{};
    auto result = vkCreateInstance(&create_info, nullptr, &instance);
    if (result) throw std::exception("Failed to create instance.");
    return instance;
  }
 

  auto get_physical_devices(const VkInstance instance) -> std::vector<VkPhysicalDevice> {
    uint32_t count = {};
    auto result = vkEnumeratePhysicalDevices(instance, &count, nullptr);
    if (result) throw std::exception("Failed to get physical device count.");

    auto physical_devices = std::vector<VkPhysicalDevice>{ count };
    auto result = vkEnumeratePhysicalDevices(instance, &count, physical_devices.data());
    if (result) throw std::exception("Failed to get physical devices.");

    return physical_devices;
  }

  static const VkInstance instance_ = create_instance();
  static const std::vector<VkPhysicalDevice> physical_devices_ = get_physical_devices(instance_);


  auto select_physical_device() -> VkPhysicalDevice {
    // todo : implement physical device selection logic
    return physical_devices_.at(0);
  }


  auto select_best_graphics_queue(const VkPhysicalDevice physical_device) -> uint32_t {
    // todo : implement graphics queue select logic
    return 0;
  }





  auto create_device(const VkPhysicalDevice physical_device) -> VkDevice {
    float queue_priority = 1.0f;

    auto queue_create_infos = std::array<VkDeviceQueueCreateInfo, 1>{
      VkDeviceQueueCreateInfo{
        .sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
        .queueFamilyIndex = select_best_graphics_queue(physical_device),
        .queueCount = 1,
        .pQueuePriorities = &queue_priority
      }
    };

    auto create_info = VkDeviceCreateInfo{
      .sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
      .queueCreateInfoCount = queue_create_infos.size(),
      .pQueueCreateInfos = queue_create_infos.data(),
    };

    auto device = VkDevice{};
    auto result = vkCreateDevice(physical_device, &create_info, nullptr, &device);
    if (result) throw std::exception("Failed to create device.");
    return device;
  }



  GraphicsContext::GraphicsContext() : 
    physical_device_{ select_physical_device() },
    device_{ create_device(physical_device_)} {
  }

  GraphicsContext::~GraphicsContext() {
  
  }

}