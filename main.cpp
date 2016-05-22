#include <iostream>
#include <FreeImage.h>
#include "Vec3.h"
#include "Ray.h"

#define WIDTH 200
#define HEIGHT 100

typedef FIBITMAP Image;
typedef RGBQUAD Colour;

using namespace std;

Vec3 backgroundColour(const Ray& r)
{
    Vec3 unitD = unitVector(r.getDirection());
    float t = 0.5f * (unitD.y + 1.0f);
    return (1.0f - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
}

Vec3 getColour(const Ray& r)
{
    float t = r.hitSphere(Vec3(0, 0, -1), 0.5);
    if (t > 0.0)
    {
        Vec3 N = unitVector(r.p(t) - Vec3(0, 0, -1));
        return 0.5f * Vec3(N.x + 1, N.y + 1, N.z + 1);
    }
    return backgroundColour(r);
}

int main() {

    FreeImage_Initialise();
    cout << FreeImage_GetCopyrightMessage() << endl;

    // 200x100 image with 24 bits per pixel
    Image * image = FreeImage_Allocate(WIDTH, HEIGHT, 24);
    Colour colour;

    Vec3 lowerLeftCorner(-2.0, -1.0, -1.0);
    Vec3 horizontal(4.0, 0.0, 0.0);
    Vec3 vertical(0.0, 2.0, 0.0);
    Vec3 origin(0.0, 0.0, 0.0);

    if (!image) exit(EXIT_FAILURE);

    for (unsigned int x = 0; x < WIDTH; x++)
        for (unsigned int y = 0; y < HEIGHT; y++)
        {
            float u = x / float(WIDTH);
            float v = y / float(HEIGHT);

            Ray r(origin, lowerLeftCorner + (u * horizontal) + (v * vertical));
            Vec3 col = getColour(r);

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
