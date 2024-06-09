#include "StartScreen.h"

Start::Start()
{
    startScreenImage = nullptr;
    try {
        startScreenImage = new AmusingDolphins::Image("..\\Assets\\Textures\\Menu\\TitleScreen.png");
        std::cout << "Start screen image loaded successfully." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Failed to load start screen image: " << e.what() << std::endl;
    }
}

Start::~Start()
{
    delete startScreenImage;
}



void Start::DisplayStartScreen()
{
    if (startScreenImage) {
        AmusingDolphins::Renderer::Draw(*startScreenImage, 200, 100);
    }
    else {
        std::cerr << "Start screen image is not loaded." << std::endl;
    }
}
