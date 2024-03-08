set(HEADER_FILES
	include/AmusingDolphins.h
	src/ADA.h
	src/Utility.h
	src/ADWindow.h
	src/WindowImpl.h
	src/codeGLFW/WindowGLFW.h
	


)

set(SOURCE_FILES
	src/ADA.cpp
	src/ADWindow.cpp
	src/codeGLFW/WindowGLFW.cpp
)



add_library(AmusingDolphins SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_compile_definitions(AmusingDolphins
	PUBLIC
		$<$<CONFIG:Debug>:AMUSING_DOLPHINS_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:AMUSING_DOLPHINS_DEBUG=1>
	PRIVATE
		AMUSING_DOLPHINS_LIB
		AD_GLFW_WINDOW
)

if (MSVC)
	target_compile_definitions(AmusingDolphins PUBLIC AMUSING_DOLPHINS_MS_COMPILER)
endif()

target_include_directories(AmusingDolphins PRIVATE ../glfw/include)

target_include_directories(AmusingDolphins PRIVATE ../AmusingDolphins)

target_precompile_headers(AmusingDolphins PRIVATE src/pch.h)

target_link_libraries(AmusingDolphins glfw)