#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *img = &image[i][j];
            if (img->rgbtBlue == img->rgbtGreen && img->rgbtGreen == img->rgbtRed)
            {
                continue;
            }
            int sum = img->rgbtBlue + img->rgbtGreen + img->rgbtRed;
            float res = (float) sum / 3.0;
            int ress = (int) roundf(res);
            img->rgbtBlue = ress;
            img->rgbtGreen = ress;
            img->rgbtRed = ress;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
//               sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
//   sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
//   sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
            RGBTRIPLE *img = &image[i][j];
            float oBlue = (float) img->rgbtBlue;
            float oGreen = (float) img->rgbtGreen;
            float oRed = (float) img->rgbtRed;
            img->rgbtBlue = (int) roundf(0.272 * oRed + 0.534 * oGreen + 0.131 * oBlue);
            img->rgbtGreen = (int) roundf(0.349 * oRed + 0.686 * oGreen + 0.168 * oBlue);
            img->rgbtRed = (int) roundf(0.393 * oRed + .769 * oGreen + 0.189 * oBlue);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
