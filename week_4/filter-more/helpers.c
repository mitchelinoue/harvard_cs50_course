#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;

            image[i][j].rgbtBlue = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtRed = round(average);
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

            float averageBlue = copy[i][j].rgbtBlue;
            float averageGreen = copy[i][j].rgbtGreen;
            float averageRed = copy[i][j].rgbtRed;
            int index = 1;

            if (i + 1 < height)
            {
                averageBlue += copy[i + 1][j].rgbtBlue;
                averageGreen += copy[i + 1][j].rgbtGreen;
                averageRed += copy[i + 1][j].rgbtRed;
                index++;
            }

            if (i - 1 >= 0)
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

            if (j - 1 >= 0)
            {
                averageBlue += copy[i][j - 1].rgbtBlue;
                averageGreen += copy[i][j - 1].rgbtGreen;
                averageRed += copy[i][j - 1].rgbtRed;
                index++;
            }

            if (i + 1 < height && j - 1 >= 0)
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

            if (i - 1 >= 0 && j + 1 < width)
            {
                averageBlue += copy[i - 1][j + 1].rgbtBlue;
                averageGreen += copy[i - 1][j + 1].rgbtGreen;
                averageRed += copy[i - 1][j + 1].rgbtRed;
                index++;
            }

            if (i - 1 >= 0 && j - 1 >= 0)
            {
                averageBlue += copy[i - 1][j - 1].rgbtBlue;
                averageGreen += copy[i - 1][j - 1].rgbtGreen;
                averageRed += copy[i - 1][j - 1].rgbtRed;
                index++;
            }

            float finalBlue = averageBlue / (float) index;
            float finalGreen = averageGreen / (float) index;
            float finalRed = averageRed / (float) index;

            image[i][j].rgbtBlue = round(finalBlue);
            image[i][j].rgbtGreen = round(finalGreen);
            image[i][j].rgbtRed = round(finalRed);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gxBlue = 0;
            float gxGreen = 0;
            float gxRed = 0;

            float gyBlue = 0;
            float gyGreen = 0;
            float gyRed = 0;

            if (i + 1 < height)
            {
                // gxBlue += 0 * copy[i + 1][j].rgbtBlue;
                // gxGreen += 0 * copy[i + 1][j].rgbtGreen;
                // gxRed += 0 * copy[i + 1][j].rgbtRed;

                gyBlue += 2 * copy[i + 1][j].rgbtBlue;
                gyGreen += 2 * copy[i + 1][j].rgbtGreen;
                gyRed += 2 *copy[i + 1][j].rgbtRed;
            }
            if (i - 1 >= 0)
            {
                // gxBlue += 0 * copy[i - 1][j].rgbtBlue;
                // gxGreen += 0 * copy[i - 1][j].rgbtGreen;
                // gxRed += 0 * copy[i - 1][j].rgbtRed;

                gyBlue += -2 * copy[i - 1][j].rgbtBlue;
                gyGreen += -2 * copy[i - 1][j].rgbtGreen;
                gyRed += -2 * copy[i - 1][j].rgbtRed;
            }
            if (j + 1 < width)
            {
                gxBlue += 2 * copy[i][j + 1].rgbtBlue;
                gxGreen += 2 * copy[i][j + 1].rgbtGreen;
                gxRed += 2 * copy[i][j + 1].rgbtRed;

                // gyBlue += 0 * copy[i][j + 1].rgbtBlue;
                // gyGreen += 0 * copy[i][j + 1].rgbtGreen;
                // gyRed += 0 * copy[i][j + 1].rgbtRed;
            }
            if (j - 1 >= 0)
            {
                gxBlue += -2 * copy[i][j - 1].rgbtBlue;
                gxGreen += -2 * copy[i][j - 1].rgbtGreen;
                gxRed += -2 * copy[i][j - 1].rgbtRed;

                // gyBlue += 0 * copy[i][j - 1].rgbtBlue;
                // gyGreen += 0 * copy[i][j - 1].rgbtGreen;
                // gyRed += 0 * copy[i][j - 1].rgbtRed;
            }
            if (i + 1 < height && j - 1 >= 0)
            {
                gxBlue += -1 * copy[i + 1][j - 1].rgbtBlue;
                gxGreen += -1 * copy[i + 1][j - 1].rgbtGreen;
                gxRed += -1 * copy[i + 1][j - 1].rgbtRed;

                gyBlue += 1 * copy[i + 1][j - 1].rgbtBlue;
                gyGreen += 1 * copy[i + 1][j - 1].rgbtGreen;
                gyRed += 1 * copy[i + 1][j - 1].rgbtRed;
            }
            if (i + 1 < height && j + 1 < width)
            {
                gxBlue += 1 * copy[i + 1][j + 1].rgbtBlue;
                gxGreen += 1 * copy[i + 1][j + 1].rgbtGreen;
                gxRed += 1 * copy[i + 1][j + 1].rgbtRed;

                gyBlue += 1 * copy[i + 1][j + 1].rgbtBlue;
                gyGreen += 1 * copy[i + 1][j + 1].rgbtGreen;
                gyRed += 1 * copy[i + 1][j + 1].rgbtRed;
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                gxBlue += 1 * copy[i - 1][j + 1].rgbtBlue;
                gxGreen += 1 * copy[i - 1][j + 1].rgbtGreen;
                gxRed += 1 * copy[i - 1][j + 1].rgbtRed;

                gyBlue += -1 * copy[i - 1][j + 1].rgbtBlue;
                gyGreen += -1 * copy[i - 1][j + 1].rgbtGreen;
                gyRed += -1 * copy[i - 1][j + 1].rgbtRed;
            }
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                gxBlue += -1 * copy[i - 1][j - 1].rgbtBlue;
                gxGreen += -1 * copy[i - 1][j - 1].rgbtGreen;
                gxRed += -1 * copy[i - 1][j - 1].rgbtRed;

                gyBlue += -1 * copy[i - 1][j - 1].rgbtBlue;
                gyGreen += -1 * copy[i - 1][j - 1].rgbtGreen;
                gyRed += -1 * copy[i - 1][j - 1].rgbtRed;
            }

            int finalBlue = round(sqrt(pow(gxBlue, 2) + pow(gyBlue, 2)));
            int finalGreen = round(sqrt(pow(gxGreen, 2) + pow(gyGreen, 2)));
            int finalRed = round(sqrt(pow(gxRed, 2) + pow(gyRed, 2)));

            // printf("finalBlue: %i\n",finalBlue);
            // printf("finalGreen: %i\n",finalGreen);
            // printf(" finalRed: %i\n",finalRed);

            if (finalBlue > 255)
            {
                finalBlue = 255;
            }
            if (finalGreen > 255)
            {
                finalGreen = 255;
            }
            if (finalRed > 255)
            {
                finalRed = 255;
            }

            image[i][j].rgbtBlue = finalBlue;
            image[i][j].rgbtGreen = finalGreen;
            image[i][j].rgbtRed = finalRed;
        }
    }
}
