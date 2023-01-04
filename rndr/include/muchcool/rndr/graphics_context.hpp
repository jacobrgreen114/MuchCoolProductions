
#pragma once

#include <vulkan/vulkan.h>

#include <memory>

namespace muchcool::rndr {


  class GraphicsContext {

    const VkPhysicalDevice physical_device_;
    const VkDevice device_;


  public:
    GraphicsContext();
    GraphicsContext(GraphicsContext&&) = delete;
    GraphicsContext(const GraphicsContext&) = delete;
    ~GraphicsContext();

    static auto create_shared() -> std::shared_ptr<GraphicsContext> {
      return std::make_shared<GraphicsContext>();
    }
  };


}
