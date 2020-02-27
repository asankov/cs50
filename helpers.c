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
            RGBTRIPLE *img = &image[i][j];
            float oBlue = (float) img->rgbtBlue;
            float oGreen = (float) img->rgbtGreen;
            float oRed = (float) img->rgbtRed;

            int nBlue = (int) roundf(0.272 * oRed + 0.534 * oGreen + 0.131 * oBlue);
            if (nBlue > 255)
            {
                nBlue = 255;
            }
            img->rgbtBlue = nBlue;
            int nGreen = (int) roundf(0.349 * oRed + 0.686 * oGreen + 0.168 * oBlue);
            if (nGreen > 255)
            {
                nGreen = 255;
            }
            img->rgbtGreen = nGreen;
            int nRed = (int) roundf(0.393 * oRed + .769 * oGreen + 0.189 * oBlue);
            if (nRed > 255)
            {
                nRed = 255;
            }
            img->rgbtRed = nRed;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int iWidth;
    if (width % 2 == 0)
    {
        iWidth = width/2;
    } else {
        iWidth = (width/2)+1;
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE *left = &image[i][j];
            RGBTRIPLE *right = &image[i][width - (j+1)];

            int tmpBlue = left->rgbtBlue;
            int tmpGreen = left->rgbtGreen;
            int tmpRed = left->rgbtRed;

            left->rgbtBlue = right->rgbtBlue;
            left->rgbtGreen = right->rgbtGreen;
            left->rgbtRed = right->rgbtRed;

            right->rgbtBlue = tmpBlue;
            right->rgbtGreen = tmpGreen;
            right->rgbtRed = tmpRed;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
