#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterate through image
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            double average = round((image[r][c].rgbtBlue + image[r][c].rgbtGreen + image[r][c].rgbtRed) / 3.0);
            image[r][c].rgbtBlue = average;
            image[r][c].rgbtGreen = average;
            image[r][c].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterate through image
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width / 2; c++)
        {
            RGBTRIPLE temp = image[r][c];
            image[r][c] = image[r][width - 1 - c];
            image[r][width -  1 - c] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    //Make a copy of the image
    RGBTRIPLE copy[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            copy[y][x] = image[y][x];
        }
    }

    //Iterate throughout the entire image
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            //Top Left Corner
            if (r == 0 && c == 0)
            {
                //Get averages of copy and set pixels of new image to these averages
                int red = round((copy[r][c].rgbtRed + copy[r + 1][c].rgbtRed + copy[r][c + 1].rgbtRed + copy[r + 1][c + 1].rgbtRed) / 4.0);
                int green = round((copy[r][c].rgbtGreen + copy[r + 1][c].rgbtGreen + copy[r][c + 1].rgbtGreen + copy[r + 1][c + 1].rgbtGreen) /
                                  4.0);
                int blue =  round((copy[r][c].rgbtBlue + copy[r + 1][c].rgbtBlue + copy[r][c + 1].rgbtBlue + copy[r + 1][c + 1].rgbtBlue) / 4.0);

                image[r][c].rgbtRed = red;
                image[r][c].rgbtGreen = green;
                image[r][c].rgbtBlue = blue;
            }

            //Top Right Corner
            else if (r == 0 && c == width - 1)
            {
                //Get averages of copy and set pixels of new image to these averages
                int red = round((copy[r][c].rgbtRed + copy[r + 1][c].rgbtRed + copy[r + 1][c - 1].rgbtRed + copy[r][c - 1].rgbtRed) / 4.0);
                int green = round((copy[r][c].rgbtGreen + copy[r + 1][c].rgbtGreen + copy[r + 1][c - 1].rgbtGreen + copy[r][c - 1].rgbtGreen) /
                                  4.0);
                int blue =  round((copy[r][c].rgbtBlue + copy[r + 1][c].rgbtBlue + copy[r + 1][c - 1].rgbtBlue + copy[r][c - 1].rgbtBlue) / 4.0);

                image[r][c].rgbtRed = red;
                image[r][c].rgbtGreen = green;
                image[r][c].rgbtBlue = blue;
            }

            //Bottom Left Corner
            else if (r == height - 1 && c == 0)
            {
                //Get averages of copy and set pixels of new image to these averages
                int red = round((copy[r][c].rgbtRed + copy[r - 1][c].rgbtRed + copy[r - 1][c + 1].rgbtRed + copy[r][c + 1].rgbtRed) / 4.0);
                int green = round((copy[r][c].rgbtGreen + copy[r - 1][c].rgbtGreen + copy[r - 1][c + 1].rgbtGreen + copy[r][c + 1].rgbtGreen) /
                                  4.0);
                int blue =  round((copy[r][c].rgbtBlue + copy[r - 1][c].rgbtBlue + copy[r - 1][c + 1].rgbtBlue + copy[r][c + 1].rgbtBlue) / 4.0);

                image[r][c].rgbtRed = red;
                image[r][c].rgbtGreen = green;
                image[r][c].rgbtBlue = blue;
            }

            //Bottom Right Corner
            else if (r == height - 1 && c == width - 1)
            {
                //Get averages of copy and set pixels of new image to these averages
                int red = round((copy[r][c].rgbtRed + copy[r][c - 1].rgbtRed + copy[r - 1][c - 1].rgbtRed + copy[r - 1][c].rgbtRed) / 4.0);
                int green = round((copy[r][c].rgbtGreen + copy[r][c - 1].rgbtGreen + copy[r - 1][c - 1].rgbtGreen + copy[r - 1][c].rgbtGreen) /
                                  4.0);
                int blue =  round((copy[r][c].rgbtBlue + copy[r][c - 1].rgbtBlue + copy[r - 1][c - 1].rgbtBlue + copy[r - 1][c].rgbtBlue) / 4.0);

                image[r][c].rgbtRed = red;
                image[r][c].rgbtGreen = green;
                image[r][c].rgbtBlue = blue;
            }

            //Top edge
            else if (r == 0)
            {
                //Get averages of copy and set pixels of new image to these averages
                int red = round((copy[r][c].rgbtRed + copy[r][c - 1].rgbtRed +
                                 copy[r][c + 1].rgbtRed + copy[r + 1][c - 1].rgbtRed +
                                 copy[r + 1][c].rgbtRed + copy[r + 1][c + 1].rgbtRed) / 6.0);

                int green = round((copy[r][c].rgbtGreen + copy[r][c - 1].rgbtGreen +
                                   copy[r][c + 1].rgbtGreen + copy[r + 1][c - 1].rgbtGreen +
                                   copy[r + 1][c].rgbtGreen + copy[r + 1][c + 1].rgbtGreen) / 6.0);

                int blue =  round((copy[r][c].rgbtBlue + copy[r][c - 1].rgbtBlue +
                                   copy[r][c + 1].rgbtBlue + copy[r + 1][c - 1].rgbtBlue +
                                   copy[r + 1][c].rgbtBlue + copy[r + 1][c + 1].rgbtBlue) / 6.0);

                image[r][c].rgbtRed = red;
                image[r][c].rgbtGreen = green;
                image[r][c].rgbtBlue = blue;
            }

            //Bottom edge
            else if (r == height - 1)
            {
                //Get averages of copy and set pixels of new image to these averages
                int red = round((copy[r][c].rgbtRed + copy[r][c - 1].rgbtRed +
                                 copy[r][c + 1].rgbtRed + copy[r - 1][c - 1].rgbtRed +
                                 copy[r - 1][c].rgbtRed + copy[r - 1][c + 1].rgbtRed) / 6.0);

                int green = round((copy[r][c].rgbtGreen + copy[r][c - 1].rgbtGreen +
                                   copy[r][c + 1].rgbtGreen + copy[r - 1][c - 1].rgbtGreen +
                                   copy[r - 1][c].rgbtGreen + copy[r - 1][c + 1].rgbtGreen) / 6.0);

                int blue =  round((copy[r][c].rgbtBlue + copy[r][c - 1].rgbtBlue +
                                   copy[r][c + 1].rgbtBlue + copy[r - 1][c - 1].rgbtBlue +
                                   copy[r - 1][c].rgbtBlue + copy[r - 1][c + 1].rgbtBlue) / 6.0);

                image[r][c].rgbtRed = red;
                image[r][c].rgbtGreen = green;
                image[r][c].rgbtBlue = blue;
            }

            //Left edge
            else if (c == 0)
            {
                //Get averages of copy and set pixels of new image to these averages
                int red = round((copy[r][c].rgbtRed + copy[r - 1][c].rgbtRed +
                                 copy[r + 1][c].rgbtRed + copy[r - 1][c + 1].rgbtRed +
                                 copy[r][c + 1].rgbtRed + copy[r + 1][c + 1].rgbtRed) / 6.0);

                int green = round((copy[r][c].rgbtGreen + copy[r - 1][c].rgbtGreen +
                                   copy[r + 1][c].rgbtGreen + copy[r - 1][c + 1].rgbtGreen +
                                   copy[r][c + 1].rgbtGreen + copy[r + 1][c + 1].rgbtGreen) / 6.0);

                int blue =  round((copy[r][c].rgbtBlue + copy[r - 1][c].rgbtBlue +
                                   copy[r + 1][c].rgbtBlue + copy[r - 1][c + 1].rgbtBlue +
                                   copy[r][c + 1].rgbtBlue + copy[r + 1][c + 1].rgbtBlue) / 6.0);

                image[r][c].rgbtRed = red;
                image[r][c].rgbtGreen = green;
                image[r][c].rgbtBlue = blue;
            }

            //Right edge
            else if (c == width - 1)
            {
                //Get averages of copy and set pixels of new image to these averages
                int red = round((copy[r - 1][c - 1].rgbtRed + copy[r - 1][c].rgbtRed +
                                 copy[r][c - 1].rgbtRed + copy[r][c].rgbtRed +
                                 copy[r + 1][c - 1].rgbtRed + copy[r + 1][c].rgbtRed) / 6.0);

                int green = round((copy[r - 1][c - 1].rgbtGreen + copy[r - 1][c].rgbtGreen +
                                   copy[r][c - 1].rgbtGreen + copy[r][c].rgbtGreen +
                                   copy[r + 1][c - 1].rgbtGreen + copy[r + 1][c].rgbtGreen) / 6.0);

                int blue =  round((copy[r - 1][c - 1].rgbtBlue + copy[r - 1][c].rgbtBlue +
                                   copy[r][c - 1].rgbtBlue + copy[r][c].rgbtBlue +
                                   copy[r + 1][c - 1].rgbtBlue + copy[r + 1][c].rgbtBlue) / 6.0);

                image[r][c].rgbtRed = red;
                image[r][c].rgbtGreen = green;
                image[r][c].rgbtBlue = blue;
            }

            //Middle characters
            else
            {
                //Get averages of copy and set pixels of new image to these averages
                int red = round((copy[r - 1][c - 1].rgbtRed + copy[r - 1][c].rgbtRed + copy[r - 1][c + 1].rgbtRed +
                                 copy[r][c - 1].rgbtRed + copy[r][c].rgbtRed + copy[r][c + 1].rgbtRed +
                                 copy[r + 1][c - 1].rgbtRed + copy[r + 1][c].rgbtRed + copy[r + 1][c + 1].rgbtRed) / 9.0);

                int green = round((copy[r - 1][c - 1].rgbtGreen + copy[r - 1][c].rgbtGreen + copy[r - 1][c + 1].rgbtGreen +
                                   copy[r][c - 1].rgbtGreen + copy[r][c].rgbtGreen + copy[r][c + 1].rgbtGreen +
                                   copy[r + 1][c - 1].rgbtGreen + copy[r + 1][c].rgbtGreen + copy[r + 1][c + 1].rgbtGreen) / 9.0);

                int blue = round((copy[r - 1][c - 1].rgbtBlue + copy[r - 1][c].rgbtBlue + copy[r - 1][c + 1].rgbtBlue +
                                  copy[r][c - 1].rgbtBlue + copy[r][c].rgbtBlue + copy[r][c + 1].rgbtBlue +
                                  copy[r + 1][c - 1].rgbtBlue + copy[r + 1][c].rgbtBlue + copy[r + 1][c + 1].rgbtBlue) / 9.0);

                image[r][c].rgbtRed = red;
                image[r][c].rgbtGreen = green;
                image[r][c].rgbtBlue = blue;
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Make a copy of the image
    RGBTRIPLE copy[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            copy[y][x] = image[y][x];
        }
    }

    //Iterate throughout the entire image
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            //Top Left Corner
            if (r == 0 && c == 0)
            {
                //Get gx and gy sums
                int redgx = (copy[r][c + 1].rgbtRed * 2) + copy[r + 1][c + 1].rgbtRed;
                int greengx = (copy[r][c + 1].rgbtGreen * 2) + copy[r + 1][c + 1].rgbtGreen;
                int bluegx = (copy[r][c + 1].rgbtBlue * 2) + copy[r + 1][c + 1].rgbtBlue;

                int redgy = (copy[r + 1][c].rgbtRed * 2) + copy[r + 1][c + 1].rgbtRed;
                int greengy = (copy[r + 1][c].rgbtGreen * 2) + copy[r + 1][c + 1].rgbtGreen;
                int bluegy = (copy[r + 1][c].rgbtBlue * 2) + copy[r + 1][c + 1].rgbtBlue;

                //Calculate sobel values
                int redfinal = round(sqrt(redgx * redgx + redgy * redgy));
                int greenfinal = round(sqrt(greengx * greengx + greengy * greengy));
                int bluefinal = round(sqrt(bluegx * bluegx + bluegy * bluegy));
                
                //Cap values at 255
                if (redfinal > 255)
                {
                    image[r][c].rgbtRed = 255;
                }
                else
                {
                    image[r][c].rgbtRed = redfinal;
                }
                
                if (greenfinal > 255) 
                {
                    image[r][c].rgbtGreen = 255;  
                } 
                else
                {
                    image[r][c].rgbtGreen = greenfinal;
                }
                
                if (bluefinal > 255)
                {
                    image[r][c].rgbtBlue = 255;
                }
                else
                {
                    image[r][c].rgbtBlue = bluefinal;
                }
            }

            //Top Right Corner
            else if (r == 0 && c == width - 1)
            {
                //Get gx and gy sums
                int redgx = (copy[r][c - 1].rgbtRed * -2) + (copy[r + 1][c - 1].rgbtRed * -1);
                int greengx = (copy[r][c - 1].rgbtGreen * -2) + (copy[r + 1][c - 1].rgbtGreen * -1);
                int bluegx = (copy[r][c - 1].rgbtBlue * -2) + (copy[r + 1][c - 1].rgbtBlue * -1);

                int redgy = (copy[r + 1][c].rgbtRed * 2) + copy[r + 1][c - 1].rgbtRed;
                int greengy = (copy[r + 1][c].rgbtGreen * 2) + copy[r + 1][c - 1].rgbtGreen;
                int bluegy = (copy[r + 1][c].rgbtBlue * 2) + copy[r + 1][c - 1].rgbtBlue;

                //Calculate sobel values
                int redfinal = round(sqrt(redgx * redgx + redgy * redgy));
                int greenfinal = round(sqrt(greengx * greengx + greengy * greengy));
                int bluefinal = round(sqrt(bluegx * bluegx + bluegy * bluegy));
                
                //Cap values at 255
                if (redfinal > 255)
                {
                    image[r][c].rgbtRed = 255;
                }
                else
                {
                    image[r][c].rgbtRed = redfinal;
                }
                
                if (greenfinal > 255)
                {
                    image[r][c].rgbtGreen = 255;  
                } 
                else
                {
                    image[r][c].rgbtGreen = greenfinal;
                }
                
                if (bluefinal > 255)
                {
                    image[r][c].rgbtBlue = 255;
                }
                else
                {
                    image[r][c].rgbtBlue = bluefinal;
                }
            }

            //Bottom Left Corner
            else if (r == height - 1 && c == 0)
            {
                //Get gx and gy sums
                int redgx = (copy[r][c + 1].rgbtRed * 2) + (copy[r - 1][c + 1].rgbtRed * 1);
                int greengx = (copy[r][c + 1].rgbtGreen * 2) + (copy[r - 1][c + 1].rgbtGreen * 1);
                int bluegx = (copy[r][c + 1].rgbtBlue * 2) + (copy[r - 1][c + 1].rgbtBlue * 1);

                int redgy = (copy[r - 1][c].rgbtRed * -2) + (copy[r - 1][c + 1].rgbtRed * -1);
                int greengy = (copy[r - 1][c].rgbtGreen * -2) + (copy[r - 1][c + 1].rgbtGreen * -1);
                int bluegy = (copy[r - 1][c].rgbtBlue * -2) + (copy[r - 1][c + 1].rgbtBlue * -1);
                
                //Calculate sobel values
                int redfinal = round(sqrt(redgx * redgx + redgy * redgy));
                int greenfinal = round(sqrt(greengx * greengx + greengy * greengy));
                int bluefinal = round(sqrt(bluegx * bluegx + bluegy * bluegy));
                
                //Cap values at 255
                if (redfinal > 255)
                {
                    image[r][c].rgbtRed = 255;
                }
                else
                {
                    image[r][c].rgbtRed = redfinal;
                }
                
                if (greenfinal > 255)
                {
                    image[r][c].rgbtGreen = 255;  
                } 
                else
                {
                    image[r][c].rgbtGreen = greenfinal;
                }
                
                if (bluefinal > 255)
                {
                    image[r][c].rgbtBlue = 255;
                }
                else
                {
                    image[r][c].rgbtBlue = bluefinal;
                }
            }

            //Bottom Right Corner
            else if (r == height - 1 && c == width - 1)
            {
                //Get gx and gy sums
                int redgx = (copy[r - 1][c - 1].rgbtRed * -1) + (copy[r][c - 1].rgbtRed * -2);
                int greengx = (copy[r - 1][c - 1].rgbtGreen * -1) + (copy[r][c - 1].rgbtGreen * -2); 
                int bluegx = (copy[r - 1][c - 1].rgbtBlue * -1) + (copy[r][c - 1].rgbtBlue * -2);

                int redgy = (copy[r - 1][c - 1].rgbtRed * -1) + (copy[r - 1][c].rgbtRed * -2);
                int greengy = (copy[r - 1][c - 1].rgbtGreen * -1) + (copy[r - 1][c].rgbtGreen * -2);
                int bluegy = (copy[r - 1][c - 1].rgbtBlue * -1) + (copy[r - 1][c].rgbtBlue * -2);
                
                //Calculate sobel values
                int redfinal = round(sqrt(redgx * redgx + redgy * redgy));
                int greenfinal = round(sqrt(greengx * greengx + greengy * greengy));
                int bluefinal = round(sqrt(bluegx * bluegx + bluegy * bluegy));
                
                //Cap values at 255
                if (redfinal > 255)
                {
                    image[r][c].rgbtRed = 255;
                }
                else
                {
                    image[r][c].rgbtRed = redfinal;
                }
                
                if (greenfinal > 255)
                {
                    image[r][c].rgbtGreen = 255;  
                } 
                else
                {
                    image[r][c].rgbtGreen = greenfinal;
                }
                
                if (bluefinal > 255)
                {
                    image[r][c].rgbtBlue = 255;
                }
                else
                {
                    image[r][c].rgbtBlue = bluefinal;
                }
            }

            //Top edge
            else if (r == 0)
            {
                //Get gx and gy sums
                int redgx = (copy[r][c - 1].rgbtRed * -2) + (copy[r][c + 1].rgbtRed * 2) + (copy[r + 1][c - 1].rgbtRed * -1) +
                            (copy[r + 1][c + 1].rgbtRed * 1);
                int greengx = (copy[r][c - 1].rgbtGreen * -2) + (copy[r][c + 1].rgbtGreen * 2) + (copy[r + 1][c - 1].rgbtGreen * -1) +
                              (copy[r + 1][c + 1].rgbtGreen * 1);
                int bluegx = (copy[r][c - 1].rgbtBlue * -2) + (copy[r][c + 1].rgbtBlue * 2) + (copy[r + 1][c - 1].rgbtBlue * -1) +
                             (copy[r + 1][c + 1].rgbtBlue * 1);

                int redgy = (copy[r][c - 1].rgbtRed * 0) + (copy[r + 1][c].rgbtRed * 2) + (copy[r + 1][c - 1].rgbtRed * 1) +
                            (copy[r + 1][c + 1].rgbtRed * 1);
                int greengy = (copy[r][c - 1].rgbtGreen * 0) + (copy[r + 1][c].rgbtGreen * 2) + (copy[r + 1][c - 1].rgbtGreen * 1) +
                              (copy[r + 1][c + 1].rgbtGreen * 1);
                int bluegy = (copy[r][c - 1].rgbtBlue * 0) + (copy[r + 1][c].rgbtBlue * 2) + (copy[r + 1][c - 1].rgbtBlue * 1) +
                             (copy[r + 1][c + 1].rgbtBlue * 1);
                
                //Calculate sobel values
                int redfinal = round(sqrt(redgx * redgx + redgy * redgy));
                int greenfinal = round(sqrt(greengx * greengx + greengy * greengy));
                int bluefinal = round(sqrt(bluegx * bluegx + bluegy * bluegy));
                
                //Cap values at 255
                if (redfinal > 255)
                {
                    image[r][c].rgbtRed = 255;
                }
                else
                {
                    image[r][c].rgbtRed = redfinal;
                }
                
                if (greenfinal > 255)
                {
                    image[r][c].rgbtGreen = 255;  
                } 
                else
                {
                    image[r][c].rgbtGreen = greenfinal;
                }
                
                if (bluefinal > 255)
                {
                    image[r][c].rgbtBlue = 255;
                }
                else
                {
                    image[r][c].rgbtBlue = bluefinal;
                }
            }

            //Bottom edge
            else if (r == height - 1)
            {
                //Get gx and gy sums
                int redgx = (copy[r - 1][c - 1].rgbtRed * -1) + (copy[r - 1][c + 1].rgbtRed * 1) + (copy[r][c - 1].rgbtRed * -2) +
                            (copy[r][c + 1].rgbtRed * 2);
                int greengx = (copy[r - 1][c - 1].rgbtGreen * -1) + (copy[r - 1][c + 1].rgbtGreen * 1) + (copy[r][c - 1].rgbtGreen * -2) +
                              (copy[r][c + 1].rgbtGreen * 2);
                int bluegx = (copy[r - 1][c - 1].rgbtBlue * -1) + (copy[r - 1][c + 1].rgbtBlue * 1) + (copy[r][c - 1].rgbtBlue * -2) +
                             (copy[r][c + 1].rgbtBlue * 2);

                int redgy = (copy[r - 1][c - 1].rgbtRed * -1) + (copy[r - 1][c].rgbtRed * -2) + (copy[r - 1][c + 1].rgbtRed * -1) +
                            (copy[r][c + 1].rgbtRed * 0);
                int greengy = (copy[r - 1][c - 1].rgbtGreen * -1) + (copy[r - 1][c].rgbtGreen * -2) + (copy[r - 1][c + 1].rgbtGreen * -1) +
                              (copy[r][c + 1].rgbtGreen * 0);
                int bluegy = (copy[r - 1][c - 1].rgbtBlue * -1) + (copy[r - 1][c].rgbtBlue * -2) + (copy[r - 1][c + 1].rgbtBlue * -1) +
                             (copy[r][c + 1].rgbtBlue * 0);
                             
                //Calculate sobel values
                int redfinal = round(sqrt(redgx * redgx + redgy * redgy));
                int greenfinal = round(sqrt(greengx * greengx + greengy * greengy));
                int bluefinal = round(sqrt(bluegx * bluegx + bluegy * bluegy));
                
                //Cap values at 255
                if (redfinal > 255)
                {
                    image[r][c].rgbtRed = 255;
                }
                else
                {
                    image[r][c].rgbtRed = redfinal;
                }
                
                if (greenfinal > 255)
                {
                    image[r][c].rgbtGreen = 255;  
                } 
                else
                {
                    image[r][c].rgbtGreen = greenfinal;
                }
                
                if (bluefinal > 255)
                {
                    image[r][c].rgbtBlue = 255;
                }
                else
                {
                    image[r][c].rgbtBlue = bluefinal;
                }
            }

            //Left edge
            else if (c == 0)
            {
                //Get gx and gy sums
                int redgx = (copy[r][c + 1].rgbtRed * 2) + (copy[r - 1][c + 1].rgbtRed * 1) + (copy[r + 1][c + 1].rgbtRed * 1);
                int greengx = (copy[r][c + 1].rgbtGreen * 2) + (copy[r - 1][c + 1].rgbtGreen * 1) + (copy[r + 1][c + 1].rgbtGreen * 1);
                int bluegx = (copy[r][c + 1].rgbtBlue * 2) + (copy[r - 1][c + 1].rgbtBlue * 1) + (copy[r + 1][c + 1].rgbtBlue * 1);

                int redgy = (copy[r - 1][c].rgbtRed * -2) + (copy[r + 1][c].rgbtRed * 2) + (copy[r - 1][c + 1].rgbtRed * -1) +
                            (copy[r + 1][c + 1].rgbtRed * 1);
                int greengy = (copy[r - 1][c].rgbtGreen * -2) + (copy[r + 1][c].rgbtGreen * 2) + (copy[r - 1][c + 1].rgbtGreen * -1) +
                              (copy[r + 1][c + 1].rgbtGreen * 1);
                int bluegy = (copy[r - 1][c].rgbtBlue * -2) + (copy[r + 1][c].rgbtBlue * 2) + (copy[r - 1][c + 1].rgbtBlue * -1) +
                             (copy[r + 1][c + 1].rgbtBlue * 1);

                //Calculate sobel values
                int redfinal = round(sqrt(redgx * redgx + redgy * redgy));
                int greenfinal = round(sqrt(greengx * greengx + greengy * greengy));
                int bluefinal = round(sqrt(bluegx * bluegx + bluegy * bluegy));
                
                //Cap values at 255
                if (redfinal > 255)
                {
                    image[r][c].rgbtRed = 255;
                }
                else
                {
                    image[r][c].rgbtRed = redfinal;
                }
                
                if (greenfinal > 255)
                {
                    image[r][c].rgbtGreen = 255;  
                } 
                else
                {
                    image[r][c].rgbtGreen = greenfinal;
                }
                
                if (bluefinal > 255)
                {
                    image[r][c].rgbtBlue = 255;
                }
                else
                {
                    image[r][c].rgbtBlue = bluefinal;
                }
            }

            //Right edge
            else if (c == width - 1)
            {
                //Get gx and gy sums
                int redgx = (copy[r][c - 1].rgbtRed * -2) + (copy[r - 1][c - 1].rgbtRed * -1) + (copy[r + 1][c - 1].rgbtRed * -1);
                int greengx = (copy[r][c - 1].rgbtGreen * -2) + (copy[r - 1][c - 1].rgbtGreen * -1) + (copy[r + 1][c - 1].rgbtGreen * -1);
                int bluegx = (copy[r][c - 1].rgbtBlue * -2) + (copy[r - 1][c - 1].rgbtBlue * -1) + (copy[r + 1][c - 1].rgbtBlue * -1);

                int redgy = (copy[r - 1][c - 1].rgbtRed * -1) + (copy[r - 1][c].rgbtRed * -2) + (copy[r + 1][c - 1].rgbtRed * 1) +
                            (copy[r + 1][c].rgbtRed * 2);
                int greengy = (copy[r - 1][c - 1].rgbtGreen * -1) + (copy[r - 1][c].rgbtGreen * -2) + (copy[r + 1][c - 1].rgbtGreen * 1) +
                              (copy[r + 1][c].rgbtGreen * 2);
                int bluegy = (copy[r - 1][c - 1].rgbtBlue * -1) + (copy[r - 1][c].rgbtBlue * -2) + (copy[r + 1][c - 1].rgbtBlue * 1) +
                             (copy[r + 1][c].rgbtBlue * 2);
                
                //Calculate sobel values
                int redfinal = round(sqrt(redgx * redgx + redgy * redgy));
                int greenfinal = round(sqrt(greengx * greengx + greengy * greengy));
                int bluefinal = round(sqrt(bluegx * bluegx + bluegy * bluegy));
                
                //Cap values at 255
                if (redfinal > 255)
                {
                    image[r][c].rgbtRed = 255;
                }
                else
                {
                    image[r][c].rgbtRed = redfinal;
                }
                
                if (greenfinal > 255)
                {
                    image[r][c].rgbtGreen = 255;  
                } 
                else
                {
                    image[r][c].rgbtGreen = greenfinal;
                }
                
                if (bluefinal > 255)
                {
                    image[r][c].rgbtBlue = 255;
                }
                else
                {
                    image[r][c].rgbtBlue = bluefinal;
                }
            }

            //Middle characters
            else
            {
                //Get gx and gy sums
                int redgx = (copy[r - 1][c - 1].rgbtRed * -1) + (copy[r - 1][c].rgbtRed * 0) + (copy[r - 1][c + 1].rgbtRed * 1) +
                            (copy[r][c - 1].rgbtRed * -2) + (copy[r][c].rgbtRed * 0) + (copy[r][c + 1].rgbtRed * 2) +
                            (copy[r + 1][c - 1].rgbtRed * -1) + (copy[r + 1][c].rgbtRed * 0) + (copy[r + 1][c + 1].rgbtRed * 1);

                int greengx = (copy[r - 1][c - 1].rgbtGreen * -1) + (copy[r - 1][c].rgbtGreen * 0) + (copy[r - 1][c + 1].rgbtGreen * 1) +
                              (copy[r][c - 1].rgbtGreen * -2) + (copy[r][c].rgbtGreen * 0) + (copy[r][c + 1].rgbtGreen * 2) +
                              (copy[r + 1][c - 1].rgbtGreen * -1) + (copy[r + 1][c].rgbtGreen * 0) + (copy[r + 1][c + 1].rgbtGreen * 1);

                int bluegx = (copy[r - 1][c - 1].rgbtBlue * -1) + (copy[r - 1][c].rgbtBlue * 0) + (copy[r - 1][c + 1].rgbtBlue * 1) +
                             (copy[r][c - 1].rgbtBlue * -2) + (copy[r][c].rgbtBlue * 0) + (copy[r][c + 1].rgbtBlue * 2) +
                             (copy[r + 1][c - 1].rgbtBlue * -1) + (copy[r + 1][c].rgbtBlue * 0) + (copy[r + 1][c + 1].rgbtBlue * 1);
                                 
                                 
                                 
                int redgy = (copy[r - 1][c - 1].rgbtRed * -1) + (copy[r - 1][c].rgbtRed * -2) + (copy[r - 1][c + 1].rgbtRed * -1) +
                            (copy[r][c - 1].rgbtRed * 0) + (copy[r][c].rgbtRed * 0) + (copy[r][c + 1].rgbtRed * 0) +
                            (copy[r + 1][c - 1].rgbtRed * 1) + (copy[r + 1][c].rgbtRed * 2) + (copy[r + 1][c + 1].rgbtRed * 1);

                int greengy = (copy[r - 1][c - 1].rgbtGreen * -1) + (copy[r - 1][c].rgbtGreen * -2) + (copy[r - 1][c + 1].rgbtGreen * -1) +
                              (copy[r][c - 1].rgbtGreen * 0) + (copy[r][c].rgbtGreen * 0) + (copy[r][c + 1].rgbtGreen * 0) +
                              (copy[r + 1][c - 1].rgbtGreen * 1) + (copy[r + 1][c].rgbtGreen * 2) + (copy[r + 1][c + 1].rgbtGreen * 1);

                int bluegy = (copy[r - 1][c - 1].rgbtBlue * -1) + (copy[r - 1][c].rgbtBlue * -2) + (copy[r - 1][c + 1].rgbtBlue * -1) +
                             (copy[r][c - 1].rgbtBlue * 0) + (copy[r][c].rgbtBlue * 0) + (copy[r][c + 1].rgbtBlue * 0) +
                             (copy[r + 1][c - 1].rgbtBlue * 1) + (copy[r + 1][c].rgbtBlue * 2) + (copy[r + 1][c + 1].rgbtBlue * 1);
                
                //Calculate sobel values
                int redfinal = round(sqrt(redgx * redgx + redgy * redgy));
                int greenfinal = round(sqrt(greengx * greengx + greengy * greengy));
                int bluefinal = round(sqrt(bluegx * bluegx + bluegy * bluegy));
                
                //Cap values at 255
                if (redfinal > 255)
                {
                    image[r][c].rgbtRed = 255;
                }
                else
                {
                    image[r][c].rgbtRed = redfinal;
                }
                
                if (greenfinal > 255)
                {
                    image[r][c].rgbtGreen = 255;  
                } 
                else
                {
                    image[r][c].rgbtGreen = greenfinal;
                }
                
                if (bluefinal > 255)
                {
                    image[r][c].rgbtBlue = 255;
                }
                else
                {
                    image[r][c].rgbtBlue = bluefinal;
                }
            }
        }
    }
    return;
}
