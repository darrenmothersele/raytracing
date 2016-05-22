#include <iostream>
#include "FreeImage.h"

#define WIDTH 200
#define HEIGHT 100

typedef FIBITMAP Image;
typedef RGBQUAD Colour;

using namespace std;

int main() {

    FreeImage_Initialise();
    cout << FreeImage_GetCopyrightMessage() << endl;

    // 200x100 image with 24 bits per pixel
    Image * image = FreeImage_Allocate(WIDTH, HEIGHT, 24);
    Colour colour;

    if (!image) exit(EXIT_FAILURE);

    for (int x = 0; x < WIDTH; x++)
        for (int y = 0; y < HEIGHT; y++)
        {
            colour.rgbRed = float(x) / float(WIDTH) * 255.0;
            colour.rgbGreen = float(y) / float(HEIGHT) * 255.0;
            colour.rgbBlue = 0.2 * 255.0;
            FreeImage_SetPixelColor(image, x, y, &colour);
        }


    if (FreeImage_Save(FIF_PNG, image, "output.png", 0))
        cout << "Image saved!" << endl;

    FreeImage_DeInitialise();
    exit(EXIT_SUCCESS);
}
