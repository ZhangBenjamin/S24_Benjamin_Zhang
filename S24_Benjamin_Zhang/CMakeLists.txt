add_executable(Game Source.cpp)

include_directories("../AmusingDolphins/include")

target_link_libraries(Game AmusingDolphins)