#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }

    int c = 0;
    FILE *image = NULL;
    while (1)
    {
        BYTE *retrieved = malloc(BLOCK_SIZE);
        if (retrieved == NULL)
        {
            printf("Error allocating memory.\n");
            return 1;
        }
        int read = fread(retrieved, sizeof(BYTE), BLOCK_SIZE, file);
        if (read != BLOCK_SIZE)
        {
            break;
        }

        if (retrieved[0] == 0xff && retrieved[1] == 0xd8 && retrieved[2] == 0xff && (retrieved[3] & 0xf0) == 0xe0)
        {
            if (image != NULL)
            {
                fclose(image);
            }

            char *filename = malloc(sizeof(char) * 8);
            if (filename == NULL)
            {
                printf("Error\n");
                return 1;
            }
            sprintf(filename, "%03d.jpg", c++);
            image = fopen(filename, "w");
            if (image == NULL)
            {
                printf("Error opening new file.\n");
                return 1;
            }
            free(filename);

        }
            
        if (image != NULL)
        {
            fwrite(retrieved, sizeof(BYTE), read, image);
        }

        free(retrieved);
    }

    return 0;
}
