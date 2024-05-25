set(HEADER_FILES
	include/AmusingDolphins.h
	src/ADA.h
	src/Utility.h
	src/ADWindow.h
	src/WindowImpl.h
	src/codeGLFW/WindowGLFW.h
	src/Renderer.h
	src/RendererImplement.h
	src/codeOpenGL/RendererOpenGL.h
	src/Shader.h
	src/ShaderImplement.h
	src/codeOpenGL/ShaderOpenGL.h
	src/Image.h
	src/ImageImplement.h
	src/codeOpenGL/ImageOpenGL.h
	src/AmusingDolphinsEvents.h
	src/AmusingDolphinsKeys.h
	src/Unit.h
	


)

set(SOURCE_FILES
	src/ADA.cpp
	src/ADWindow.cpp
	src/codeGLFW/WindowGLFW.cpp
	src/Renderer.cpp
	src/codeOpenGL/RendererOpenGL.cpp
	src/Shader.cpp
	src/codeOpenGL/ShaderOpenGL.cpp
	src/Image.cpp
	src/codeOpenGL/ImageOpenGL.cpp
	src/AmusingDolphinsEvents.cpp
	src/Unit.cpp

	
)



add_library(AmusingDolphins SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_compile_definitions(AmusingDolphins
	PUBLIC
		$<$<CONFIG:Debug>:AMUSING_DOLPHINS_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:AMUSING_DOLPHINS_DEBUG=1>
	PRIVATE
		AMUSING_DOLPHINS_LIB
		AD_GLFW_WINDOW
		AMUSING_DOLPHINS_OPENGL
)

if (MSVC)
	target_compile_definitions(AmusingDolphins PUBLIC AMUSING_DOLPHINS_MS_COMPILER)
endif()

target_include_directories(AmusingDolphins PRIVATE ../glfw/include)
target_include_directories(AmusingDolphins PRIVATE ../AmusingDolphins/src)
target_include_directories(AmusingDolphins PRIVATE ../glad/include)
target_include_directories(AmusingDolphins PRIVATE ../stbi)

target_precompile_headers(AmusingDolphins PRIVATE src/pch.h)

target_link_libraries(AmusingDolphins glfw)
target_link_libraries(AmusingDolphins glad)
target_link_libraries(AmusingDolphins stbi)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/AmusingDolphins)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug/AmusingDolphins)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release/AmusingDolphins)
