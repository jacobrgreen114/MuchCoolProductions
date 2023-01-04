
#pragma once

#include <vulkan/vulkan.h>

#include <memory>
#include <vector>
#include <array>

namespace muchcool::rndr {


  class GraphicsContext {
    static const VkInstance instance_;
    static const std::vector<VkPhysicalDevice> physical_devices_;

    const VkPhysicalDevice physical_device_;
    
    const uint32_t graphics_queue_index_;

    const VkDevice device_;
    const VkQueue graphics_queue_;

  public:

    GraphicsContext();
    GraphicsContext(GraphicsContext&&) = delete;
    GraphicsContext(const GraphicsContext&) = delete;
    ~GraphicsContext();

    static auto create_shared() -> std::shared_ptr<GraphicsContext> {
      return std::make_shared<GraphicsContext>();
    }

    auto get_instance() const -> VkInstance { return instance_; }
    auto get_physical_device() const -> VkPhysicalDevice { return physical_device_; }
    auto get_device() const -> VkDevice { return device_; }
    auto get_graphics_queue() const -> VkQueue { return graphics_queue_; }
  };

}
