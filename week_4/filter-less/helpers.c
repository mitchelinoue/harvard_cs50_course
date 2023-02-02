#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
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
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
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

            image[i][j] = image[i][(width - 1) - j];

            image[i][(width - 1) - j] = temp;

        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    };

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int index = 1;
            int averageBlue = copy[i][j].rgbtBlue;
            int averageGreen = copy[i][j].rgbtGreen;
            int averageRed = copy[i][j].rgbtRed;

            if (i + 1 < height)
            {
                averageBlue += copy[i + 1][j].rgbtBlue;
                averageGreen += copy[i + 1][j].rgbtGreen;
                averageRed += copy[i + 1][j].rgbtRed;
                index++;
            }
            if (i - 1 > 0)
            {
                averageBlue += copy[i - 1][j].rgbtBlue;
                averageGreen += copy[i - 1][j].rgbtGreen;
                averageRed += copy[i - 1][j].rgbtRed;
                index++;
            }
            if (j + 1 < width)
            {
                averageBlue += copy[i][j + 1].rgbtBlue;
                averageGreen += copy[i][j + 1].rgbtGreen;
                averageRed += copy[i][j + 1].rgbtRed;
                index++;
            }
            if (j - i > 0)
            {
                averageBlue += copy[i][j - 1].rgbtBlue;
                averageGreen += copy[i][j - 1].rgbtGreen;
                averageRed += copy[i][j - 1].rgbtRed;
                index++;
            }
            if (i + 1 < height && j - 1 > 0)
            {
                averageBlue += copy[i + 1][j - 1].rgbtBlue;
                averageGreen += copy[i + 1][j - 1].rgbtGreen;
                averageRed += copy[i + 1][j - 1].rgbtRed;
                index++;
            }
            if (i + 1 < height && j + 1 < width)
            {
                averageBlue += copy[i + 1][j + 1].rgbtBlue;
                averageGreen += copy[i + 1][j + 1].rgbtGreen;
                averageRed += copy[i + 1][j + 1].rgbtRed;
                index++;
            }
            if (i - 1 > 0 && j + 1 < width)
            {
                averageBlue += copy[i - 1][j + 1].rgbtBlue;
                averageGreen += copy[i - 1][j + 1].rgbtGreen;
                averageRed += copy[i - 1][j + 1].rgbtRed;
                index++;
            }
            if (i - 1 > 0 && j - 1 > 0)
            {
                averageBlue += copy[i - 1][j - 1].rgbtBlue;
                averageGreen += copy[i - 1][j - 1].rgbtGreen;
                averageRed += copy[i - 1][j - 1].rgbtRed;
                index++;
            }

            image[i][j].rgbtBlue = round(averageBlue / index);
            image[i][j].rgbtGreen = round(averageGreen / index);
            image[i][j].rgbtRed = round(averageRed / index);
        }
    }
}
