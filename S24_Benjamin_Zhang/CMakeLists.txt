add_executable(Game Source.cpp MyGame.h MyGame.cpp Timer.h Timer.cpp StartScreen.h StartScreen.cpp)

include_directories("../AmusingDolphins/include")

target_link_libraries(Game AmusingDolphins)