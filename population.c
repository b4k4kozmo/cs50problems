#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize;
    do
    {
        startSize = get_int("Enter starting llama population: ");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("Enter the desired llama population to end with: ");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    int born;
    int died;
    int llamaCount = startSize;
    while (llamaCount < endSize)
    {
        born = llamaCount / 3;
        died = llamaCount / 4;
        llamaCount += (born - died);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %d", years);
}