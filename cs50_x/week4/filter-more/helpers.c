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
    WORD blue_total;
    WORD green_total;
    WORD red_total;

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

            // Checks N pixel.-
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct
    {
        LONG Blue;
        LONG Green;
        LONG Red;
    } BGR;

    BGR Gx;
    BGR Gy;
    BGR sobel;

    // Creates a copy of image.
    RGBTRIPLE copy_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy_image[i][j] = image[i][j];
        }
    }

    // Calculates Gx
    for (int i = 0, max_h_index = height - 1; i < height; i++)
    {
        for (int j = 0, max_w_index = width - 1; j < width; j++)
        {
            // Adds checked pixel to total.
            Gx.Blue = 0;
            Gx.Green = 0;
            Gx.Red = 0;

            // Checks N pixel.-
            if (i != 0)
            {
                // Adds N to total.
                Gx.Blue = Gx.Blue + (copy_image[i - 1][j].rgbtBlue * 0);
                Gx.Green = Gx.Green + (copy_image[i - 1][j].rgbtGreen * 0);
                Gx.Red = Gx.Red + (copy_image[i - 1][j].rgbtRed * 0);

                // Checks NW pixel.
                if (j != 0)
                {
                    // Adds NW to total.
                    Gx.Blue = Gx.Blue + (copy_image[i - 1][j - 1].rgbtBlue * -1);
                    Gx.Green = Gx.Green + (copy_image[i - 1][j - 1].rgbtGreen * -1);
                    Gx.Red = Gx.Red + (copy_image[i - 1][j - 1].rgbtRed * -1);
                }
                // Checks NE pixel.
                if (j != max_w_index)
                {
                    // Adds NE to total.
                    Gx.Blue = Gx.Blue + (copy_image[i - 1][j + 1].rgbtBlue * 1);
                    Gx.Green = Gx.Green + (copy_image[i - 1][j + 1].rgbtGreen * 1);
                    Gx.Red = Gx.Red + (copy_image[i - 1][j + 1].rgbtRed * 1);
                }
            }

            // Checks S pixel.
            if (i != max_h_index)
            {
                // Adds S to total.
                Gx.Blue = Gx.Blue + (copy_image[i + 1][j].rgbtBlue * 0);
                Gx.Green = Gx.Green + (copy_image[i + 1][j].rgbtGreen * 0);
                Gx.Red = Gx.Red + (copy_image[i + 1][j].rgbtRed * 0);

                // Checks SW pixel.
                if (j != 0)
                {
                    // Adds SW to total.
                    Gx.Blue = Gx.Blue + (copy_image[i + 1][j - 1].rgbtBlue * -1);
                    Gx.Green = Gx.Green + (copy_image[i + 1][j - 1].rgbtGreen * -1);
                    Gx.Red = Gx.Red + (copy_image[i + 1][j - 1].rgbtRed * -1);
                }
                // checks SE pixel.
                if (j != max_w_index)
                {
                    // Adds SE to total.
                    Gx.Blue = Gx.Blue + (copy_image[i + 1][j + 1].rgbtBlue * 1);
                    Gx.Green = Gx.Green + (copy_image[i + 1][j + 1].rgbtGreen * 1);
                    Gx.Red = Gx.Red + (copy_image[i + 1][j + 1].rgbtRed * 1);
                }
            }

            // Checks E pixel.
            if (j != max_w_index)
            {
                // Adds E to total.
                Gx.Blue = Gx.Blue + (copy_image[i][j + 1].rgbtBlue * 2);
                Gx.Green = Gx.Green + (copy_image[i][j + 1].rgbtGreen * 2);
                Gx.Red = Gx.Red + (copy_image[i][j + 1].rgbtRed * 2);
            }

            // Checks W pixel.
            if (j != 0)
            {
                // Adds W to total.
                Gx.Blue = Gx.Blue + (copy_image[i][j - 1].rgbtBlue * -2);
                Gx.Green = Gx.Green + (copy_image[i][j - 1].rgbtGreen * -2);
                Gx.Red = Gx.Red + (copy_image[i][j - 1].rgbtRed * -2);
            }

            // Adds checked pixel to total.
            Gy.Blue = 0;
            Gy.Green = 0;
            Gy.Red = 0;

            // Checks N pixel.-
            if (i != 0)
            {
                // Adds N to total.
                Gy.Blue = Gy.Blue + (copy_image[i - 1][j].rgbtBlue * -2);
                Gy.Green = Gy.Green + (copy_image[i - 1][j].rgbtGreen * -2);
                Gy.Red = Gy.Red + (copy_image[i - 1][j].rgbtRed * -2);

                // Checks NW pixel.
                if (j != 0)
                {
                    // Adds NW to total.
                    Gy.Blue = Gy.Blue + (copy_image[i - 1][j - 1].rgbtBlue * -1);
                    Gy.Green = Gy.Green + (copy_image[i - 1][j - 1].rgbtGreen * -1);
                    Gy.Red = Gy.Red + (copy_image[i - 1][j - 1].rgbtRed * -1);
                }
                // Checks NE pixel.
                if (j != max_w_index)
                {
                    // Adds NE to total.
                    Gy.Blue = Gy.Blue + (copy_image[i - 1][j + 1].rgbtBlue * -1);
                    Gy.Green = Gy.Green + (copy_image[i - 1][j + 1].rgbtGreen * -1);
                    Gy.Red = Gy.Red + (copy_image[i - 1][j + 1].rgbtRed * -1);
                }
            }

            // Checks S pixel.
            if (i != max_h_index)
            {
                // Adds S to total.
                Gy.Blue = Gy.Blue + (copy_image[i + 1][j].rgbtBlue * 2);
                Gy.Green = Gy.Green + (copy_image[i + 1][j].rgbtGreen * 2);
                Gy.Red = Gy.Red + (copy_image[i + 1][j].rgbtRed * 2);

                // Checks SW pixel.
                if (j != 0)
                {
                    // Adds SW to total.
                    Gy.Blue = Gy.Blue + (copy_image[i + 1][j - 1].rgbtBlue * 1);
                    Gy.Green = Gy.Green + (copy_image[i + 1][j - 1].rgbtGreen * 1);
                    Gy.Red = Gy.Red + (copy_image[i + 1][j - 1].rgbtRed * 1);
                }
                // checks SE pixel.
                if (j != max_w_index)
                {
                    // Adds SE to total.
                    Gy.Blue = Gy.Blue + (copy_image[i + 1][j + 1].rgbtBlue * 1);
                    Gy.Green = Gy.Green + (copy_image[i + 1][j + 1].rgbtGreen * 1);
                    Gy.Red = Gy.Red + (copy_image[i + 1][j + 1].rgbtRed * 1);
                }
            }

            // Checks E pixel.
            if (j != max_w_index)
            {
                // Adds E to total.
                Gy.Blue = Gy.Blue + (copy_image[i][j + 1].rgbtBlue * 0);
                Gy.Green = Gy.Green + (copy_image[i][j + 1].rgbtGreen * 0);
                Gy.Red = Gy.Red + (copy_image[i][j + 1].rgbtRed * 0);
            }

            // Checks W pixel.
            if (j != 0)
            {
                // Adds W to total.
                Gy.Blue = Gy.Blue + (copy_image[i][j - 1].rgbtBlue * 0);
                Gy.Green = Gy.Green + (copy_image[i][j - 1].rgbtGreen * 0);
                Gy.Red = Gy.Red + (copy_image[i][j - 1].rgbtRed * 0);
            }

            // Sobel filter algorithm.
            sobel.Blue = round(sqrt(pow(Gx.Blue, 2.0) + pow(Gy.Blue, 2.0)));
            sobel.Green = round(sqrt(pow(Gx.Green, 2.0) + pow(Gy.Green, 2.0)));
            sobel.Red = round(sqrt(pow(Gx.Red, 2.0) + pow(Gy.Red, 2.0)));

            // Caps sobel values to 255.
            if (sobel.Blue > 255)
                sobel.Blue = 255;
            if (sobel.Green > 255)
                sobel.Green = 255;
            if (sobel.Red > 255)
                sobel.Red = 255;

            // Assigns image pixel data.
            image[i][j].rgbtBlue = sobel.Blue;
            image[i][j].rgbtGreen = sobel.Green;
            image[i][j].rgbtRed = sobel.Red;
        }
    }
    return;
}
