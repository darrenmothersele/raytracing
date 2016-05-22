#include <iostream>
#include <FreeImage.h>
#include <glm/vec3.hpp>

#define WIDTH 200
#define HEIGHT 100

typedef FIBITMAP Image;
typedef RGBQUAD Colour;
typedef glm::vec3 Vec3;

using namespace std;

int main() {

    FreeImage_Initialise();
    cout << FreeImage_GetCopyrightMessage() << endl;

    // 200x100 image with 24 bits per pixel
    Image * image = FreeImage_Allocate(WIDTH, HEIGHT, 24);
    Colour colour;

    if (!image) exit(EXIT_FAILURE);

    for (unsigned int x = 0; x < WIDTH; x++)
        for (unsigned int y = 0; y < HEIGHT; y++)
        {
            Vec3 col(x / float(WIDTH), y / float(HEIGHT), 0.2f);
            colour.rgbRed = (unsigned char)(col.r * 255);
            colour.rgbGreen = (unsigned char)(col.g * 255);
            colour.rgbBlue = (unsigned char)(col.b * 255);
            FreeImage_SetPixelColor(image, x, y, &colour);
        }


    if (FreeImage_Save(FIF_PNG, image, "output.png", 0))
        cout << "Image saved!" << endl;

    FreeImage_DeInitialise();
    exit(EXIT_SUCCESS);
}
