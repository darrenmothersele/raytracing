#include <iostream>
#include <FreeImage.h>
#include <chrono>
#include "Vec3.h"
#include "Ray.h"
#include "Sphere.h"
#include "HitableList.h"
#include "Random.h"
#include "Camera.h"
#include "DiffuseMaterial.h"
#include "MetalMaterial.h"
#include "DielectricMaterial.h"

#define WIDTH 200
#define HEIGHT 100
#define BITS_PER_PIXEL 24
#define NUM_RAYS 100

typedef FIBITMAP Image;
typedef RGBQUAD Colour;

using namespace std;

Vec3 backgroundColour(const Ray& r)
{
    Vec3 unitD = unitVector(r.getDirection());
    float t = 0.5f * (unitD.y + 1.0f);
    return (1.0f - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
}

Vec3 getColour(const Ray& r, Hitable *world, int depth)
{
    HitRecord rec;
    if (world->hit(r, 0.001, MAXFLOAT, rec))
    {
        Ray scattered;
        Vec3 attenuation;
        if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered))
        {
            return attenuation * getColour(scattered, world, depth + 1);
        }
        return Vec3{0,0,0};
    }
    return backgroundColour(r);
}


int main() {

    FreeImage_Initialise();
    cout << FreeImage_GetCopyrightMessage() << endl;

    Image * image = FreeImage_Allocate(WIDTH, HEIGHT, BITS_PER_PIXEL);
    if (!image) exit(EXIT_FAILURE);

    Colour colour;

    auto diffuse1 = make_shared<DiffuseMaterial>(Vec3(0.1, 0.2, 0.5));
    auto diffuse2 = make_shared<DiffuseMaterial>(Vec3(0.8, 0.8, 0.0));
    auto metal1 = make_shared<MetalMaterial>(Vec3(0.8, 0.6, 0.2), 0.1);
    auto glass = make_shared<DielectricMaterial>(1.5);

    HitableList *world = new HitableList();
    world->addItem(make_shared<Sphere>(Vec3{0,0,-1}, 0.5f, diffuse1));
    world->addItem(make_shared<Sphere>(Vec3{0,-100.5,-1}, 100.f, diffuse2));
    world->addItem(make_shared<Sphere>(Vec3{1,0,-1}, 0.5f, metal1));
    world->addItem(make_shared<Sphere>(Vec3{-1,0,-1}, 0.5f, glass));

    Vec3 cameraPos{3,3,2};
    Vec3 lookAt{0,0,-1};
    float distToFocus = (cameraPos - lookAt).length();
    cout << "Focus distance = " << distToFocus << endl;
    float aperture = 0.001;
    Camera cam{cameraPos, lookAt, Vec3{0,1,0}, 20, float(WIDTH)/float(HEIGHT), aperture, distToFocus};

    cout << "Rendering..." << endl;
    auto start = chrono::steady_clock::now();
    for (unsigned int x = 0; x < WIDTH; x++)
        for (unsigned int y = 0; y < HEIGHT; y++)
        {

            Vec3 col{0,0,0};
            for (int s = 0; s < NUM_RAYS; s++)
            {
                float u = float(x + dRan()) / float(WIDTH);
                float v = float(y + dRan()) / float(HEIGHT);
                Ray r = cam.getRay(u, v);
                Vec3 p = r.p(2.0);
                col += getColour(r, world, 0);
            }
            col /= float(NUM_RAYS);
            col = Vec3(sqrt(col.r), sqrt(col.g), sqrt(col.b));

            colour.rgbRed = (unsigned char)(col.r * 255);
            colour.rgbGreen = (unsigned char)(col.g * 255);
            colour.rgbBlue = (unsigned char)(col.b * 255);
            FreeImage_SetPixelColor(image, x, y, &colour);
        }
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Render time = " << chrono::duration <double, milli> (diff).count() / 1000.0 << "s" << endl;

    if (FreeImage_Save(FIF_PNG, image, "output.png", 0))
        cout << "Image saved!" << endl;

    FreeImage_DeInitialise();
    exit(EXIT_SUCCESS);
}
