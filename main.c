#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isCarpet(int x, int y)
{
    while (1)
    {
        if (x == 0 || y == 0)
            return 0;
        else if (x % 3 == 1 && y % 3 == 1)
            return 1;
        x = x / 3;
        y = y / 3;
    }
}

void sierpinski(FILE *output, int max_iter)
{
    int size = (int)pow(3, max_iter);
    fprintf(output, "P3\n%d %d\n1\n", size, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (isCarpet(i, j) == 0)
            {
                fprintf(output, "0 0 0\t");
            }
            else
            {
                fprintf(output, "1 1 1\t");
            }
        }

        fprintf(output, "\n");
    }
}

int main(int argc, char const *argv[])
{
    int max_iter;
    FILE *output = fopen("output.ppm", "w");

    if (argc == 2)
    {
        max_iter = atoi(argv[1]);
    }
    else if (argc > 2)
    {
        printf("Too many arguments supplied.\n");
    }
    else
    {
        printf("One argument expected.\n");
    }

    sierpinski(output, max_iter);
    return 0;
}
