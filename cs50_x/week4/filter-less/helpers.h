#include "bmp.h"

// The [height][width] indexes in the prototype specify that image is a 2D
// array with height rows and width columns. This helps the function understand
// the dimensions of the array it will be working with.
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);
