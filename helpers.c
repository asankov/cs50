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

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            // itself
            int aBlue = image[i][j].rgbtBlue;
            int aRed = image[i][j].rgbtRed;
            int aGreen = image[i][j].rgbtGreen;
            int c = 1;

            if (i != 0)
            {
                // top
                aBlue += image[i - 1][j].rgbtBlue;
                aRed += image[i - 1][j].rgbtRed;
                aGreen += image[i - 1][j].rgbtGreen;
                c++;


                // top-right
                if (j != width - 1)
                {
                    aBlue += image[i - 1][j + 1].rgbtBlue;
                    aRed += image[i - 1][j + 1].rgbtRed;
                    aGreen += image[i - 1][j + 1].rgbtGreen;
                    c++;
                }

                // top-left
                if (j != 0)
                {
                    aBlue += image[i - 1][j - 1].rgbtBlue;
                    aRed += image[i - 1][j - 1].rgbtRed;
                    aGreen += image[i - 1][j - 1].rgbtGreen;
                    c++;
                }
            }

            // right
            if (j != width - 1)
            {
                aBlue += image[i][j + 1].rgbtBlue;
                aRed += image[i][j + 1].rgbtRed;
                aGreen += image[i][j + 1].rgbtGreen;
                c++;
            }

            // left
            if (j != 0)
            {
                aBlue += image[i][j - 1].rgbtBlue;
                aRed += image[i][j - 1].rgbtRed;
                aGreen += image[i][j - 1].rgbtGreen;
                c++;
            }

            if (i != height - 1)
            {
                // bottom
                aBlue += image[i + 1][j].rgbtBlue;
                aRed += image[i + 1][j].rgbtRed;
                aGreen += image[i + 1][j].rgbtGreen;
                c++;

                // bottom-right
                if (j != width - 1)
                {
                    aBlue += image[i + 1][j + 1].rgbtBlue;
                    aRed += image[i + 1][j + 1].rgbtRed;
                    aGreen += image[i + 1][j + 1].rgbtGreen;
                    c++;
                }
                // botoom-left
                if (j != 0)
                {
                    aBlue += image[i + 1][j - 1].rgbtBlue;
                    aRed += image[i + 1][j - 1].rgbtRed;
                    aGreen += image[i + 1][j - 1].rgbtGreen;
                    c++;
                }
            }

            RGBTRIPLE *img = &image[i][j];

            newImage[i][j].rgbtBlue = (int) roundf((float) aBlue / (float) c);
            newImage[i][j].rgbtRed = (int) roundf((float)aRed / (float) c);
            newImage[i][j].rgbtGreen = (int) roundf((float) aGreen / (float) c);
        }
    }

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            image[i][j] = newImage[i][j];
        }
    }
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE img = image[i][j];

            // itself
            int gxBlue = 0, gyBlue = 0;
            int gxRed = 0, gyRed = 0;
            int gxGreen = 0, gyGreen = 0;

            if (i != 0)
            {
                // top - Gx=0, Gy=-2
                gyBlue += img.rgbtBlue * -2;
                gyRed += img.rgbtRed * -2;
                gyGreen += img.rgbtGreen * -2;

                // top-right - Gx=1, Gy=-1
                if (j != width - 1)
                {
                    gxBlue += img.rgbtBlue;
                    gyBlue += -img.rgbtBlue;
                    gxRed += img.rgbtRed;
                    gyRed += -img.rgbtRed;
                    gxGreen += img.rgbtGreen;
                    gyGreen += -img.rgbtGreen;
                }

                // top-left - Gx=-1, Gy=-1
                if (j != 0)
                {
                    gxBlue += -img.rgbtBlue;
                    gyBlue += -img.rgbtBlue;
                    gxRed += -img.rgbtRed;
                    gyRed += -img.rgbtRed;
                    gxGreen += -img.rgbtGreen;
                    gyGreen += -img.rgbtGreen;
                }
            }

            // right - Gx=2, Gy=0
            if (j != width - 1)
            {
                gxBlue += 2 * img.rgbtBlue;
                gxRed += 2 * img.rgbtRed;
                gxGreen += 2 * img.rgbtGreen;
            }

            // left - Gx=-2, Gy=0
            if (j != 0)
            {
                gxBlue += -2 * img.rgbtBlue;
                gxRed += -2 * img.rgbtRed;
                gxGreen += -2 * img.rgbtGreen;
            }

            if (i != height - 1)
            {
                // bottom - Gx=0, Gy=2
                gyBlue += img.rgbtBlue * 2;
                gyRed += img.rgbtRed * 2;
                gyGreen += img.rgbtGreen * 2;

                // bottom-right - Gx=1, Gy=1
                if (j != width - 1)
                {
                    gxBlue += img.rgbtBlue;
                    gyBlue += img.rgbtBlue;
                    gxRed += img.rgbtRed;
                    gyRed += img.rgbtRed;
                    gxGreen += img.rgbtGreen;
                    gyGreen += img.rgbtGreen;
                }
                // bottom-left - Gx=-1, Gy=1
                if (j != 0)
                {
                    gxBlue += -img.rgbtBlue;
                    gyBlue += img.rgbtBlue;
                    gxRed += -img.rgbtRed;
                    gyRed += img.rgbtRed;
                    gxGreen += -img.rgbtGreen;
                    gyGreen += img.rgbtGreen;
                }
            }

            int newRed = (gxRed*gxRed) + (gyRed*gyRed);
            if (newRed > 255)
            {
                newRed = 255;
            }
            int newBlue = (gxBlue*gxBlue) + (gyBlue*gyBlue);
            if (newBlue > 255)
            {
                newBlue = 255;
            }
            int newGreen = (gxGreen*gxGreen) + (gyGreen*gyGreen);
            if (newGreen > 255)
            {
                newGreen = 255;
            }
            newImage[i][j].rgbtBlue = newBlue;
            newImage[i][j].rgbtRed = newRed;
            newImage[i][j].rgbtGreen = newGreen;
        }
    }

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            image[i][j] = newImage[i][j];
        }
    }
}
