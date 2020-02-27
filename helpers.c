#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE img = image[i][j];
            float sum = img.rgbtBlue + img.rgbtGreen + img.rgbtRed;
            float res = sum / 3;
            image[i][j].rgbtBlue = (int) res;
            image[i][j].rgbtGreen = (int) res;
            image[i][j].rgbtRed = (int) res;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
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
