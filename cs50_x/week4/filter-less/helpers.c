#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Place holder for the highest value amongst B, G and R.
    BYTE avg;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round(
                ((float) (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)) /
                3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    DWORD sepiaRed;
    DWORD sepiaGreen;
    DWORD sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculating sepia B, G and R.
            sepiaRed = round((float) (.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                      .189 * image[i][j].rgbtBlue));
            sepiaGreen = round((float) (.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                        .168 * image[i][j].rgbtBlue));
            sepiaBlue = round((float) (.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                       .131 * image[i][j].rgbtBlue));

            // Prevents a colour from exceeding 255(FF).
            if (sepiaBlue > 255)
                sepiaBlue = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaRed > 255)
                sepiaRed = 255;

            // Updating pixel data.
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Place-holder value for B, G and R.
    BYTE B;
    BYTE G;
    BYTE R;

    int left_counter = width / 2;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < left_counter; j++)
        {
            // Right-most index counter.
            int Right_counter = width - j - 1;

            // Storing left-most pixel data.
            B = image[i][j].rgbtBlue;
            G = image[i][j].rgbtGreen;
            R = image[i][j].rgbtRed;

            // Transfering right-most pixel data to the left-most pixel data.
            image[i][j].rgbtBlue = image[i][Right_counter].rgbtBlue;
            image[i][j].rgbtGreen = image[i][Right_counter].rgbtGreen;
            image[i][j].rgbtRed = image[i][Right_counter].rgbtRed;

            // Transfering left-most pixel data to the right-most pixel data.
            image[i][Right_counter].rgbtBlue = B;
            image[i][Right_counter].rgbtGreen = G;
            image[i][Right_counter].rgbtRed = R;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int pixel_checked;
    DWORD blue_total;
    DWORD green_total;
    DWORD red_total;

    // Creates a copy of image.
    RGBTRIPLE copy_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy_image[i][j] = image[i][j];
        }
    }

    // Checks each pixel.
    for (int i = 0, max_h_index = height - 1; i < height; i++)
    {
        for (int j = 0, max_w_index = width - 1; j < width; j++)
        {
            // Adds checked pixel to total.
            blue_total = copy_image[i][j].rgbtBlue;
            green_total = copy_image[i][j].rgbtGreen;
            red_total = copy_image[i][j].rgbtRed;
            pixel_checked = 1;

            // Checks N pixel.
            if (i != 0)
            {
                // Adds N to total.
                blue_total = blue_total + copy_image[i - 1][j].rgbtBlue;
                green_total = green_total + copy_image[i - 1][j].rgbtGreen;
                red_total = red_total + copy_image[i - 1][j].rgbtRed;
                pixel_checked++;

                // Checks NW pixel.
                if (j != 0)
                {
                    // Adds NW to total.
                    blue_total = blue_total + copy_image[i - 1][j - 1].rgbtBlue;
                    green_total = green_total + copy_image[i - 1][j - 1].rgbtGreen;
                    red_total = red_total + copy_image[i - 1][j - 1].rgbtRed;
                    pixel_checked++;
                }
                // Checks NE pixel.
                if (j != max_w_index)
                {
                    // Adds NE to total.
                    blue_total = blue_total + copy_image[i - 1][j + 1].rgbtBlue;
                    green_total = green_total + copy_image[i - 1][j + 1].rgbtGreen;
                    red_total = red_total + copy_image[i - 1][j + 1].rgbtRed;
                    pixel_checked++;
                }
            }

            // Checks S pixel.
            if (i != max_h_index)
            {
                // Adds S to total.
                blue_total = blue_total + copy_image[i + 1][j].rgbtBlue;
                green_total = green_total + copy_image[i + 1][j].rgbtGreen;
                red_total = red_total + copy_image[i + 1][j].rgbtRed;
                pixel_checked++;

                // Checks SW pixel.
                if (j != 0)
                {
                    // Adds SW to total.
                    blue_total = blue_total + copy_image[i + 1][j - 1].rgbtBlue;
                    green_total = green_total + copy_image[i + 1][j - 1].rgbtGreen;
                    red_total = red_total + copy_image[i + 1][j - 1].rgbtRed;
                    pixel_checked++;
                }
                // checks SE pixel.
                if (j != max_w_index)
                {
                    // Adds SE to total.
                    blue_total = blue_total + copy_image[i + 1][j + 1].rgbtBlue;
                    green_total = green_total + copy_image[i + 1][j + 1].rgbtGreen;
                    red_total = red_total + copy_image[i + 1][j + 1].rgbtRed;
                    pixel_checked++;
                }
            }

            // Checks E pixel.
            if (j != max_w_index)
            {
                // Adds E to total.
                blue_total = blue_total + copy_image[i][j + 1].rgbtBlue;
                green_total = green_total + copy_image[i][j + 1].rgbtGreen;
                red_total = red_total + copy_image[i][j + 1].rgbtRed;
                pixel_checked++;
            }

            // Checks W pixel.
            if (j != 0)
            {
                // Adds W to total.
                blue_total = blue_total + copy_image[i][j - 1].rgbtBlue;
                green_total = green_total + copy_image[i][j - 1].rgbtGreen;
                red_total = red_total + copy_image[i][j - 1].rgbtRed;
                pixel_checked++;
            }

            // Assigns average to image pixel data.
            image[i][j].rgbtBlue = round(((float) blue_total) / pixel_checked);
            image[i][j].rgbtGreen = round(((float) green_total) / pixel_checked);
            image[i][j].rgbtRed = round(((float) red_total) / pixel_checked);
        }
    }
    return;
}
