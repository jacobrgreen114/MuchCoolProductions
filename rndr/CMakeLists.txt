
add_library (rndr   
	"source/graphics_context.cpp"
)

target_include_directories (rndr
PUBLIC
	"include"
	"C:/Dev/Libraries/Vulkan/1.3.216.0/Include"
)

target_link_directories (rndr
PUBLIC
	"C:/Dev/Libraries/Vulkan/1.3.216.0/Bin"
)

target_link_libraries (rndr
PUBLIC
	"vulkan-1.lib"
)