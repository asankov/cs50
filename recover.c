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
    while(1)
    {
        BYTE *image = malloc(BLOCK_SIZE);
        int retrieved = fread(image, sizeof(BYTE), BLOCK_SIZE, file);
        if (retrieved != BLOCK_SIZE)
        {
            printf("Read error.\n");
            return 1;
        }

        if (retrieved[0] == 0xff && retrieved[1] == 0xd8 && retrieved[2] == 0xff && (retrieved[3] & 0xf0) == 0xe0)
        {
            if (image != NULL)
            {
                fclose(image);
            }

            char *filename;
            sprintf(filename, "%3d", ++c);
            image = fopen(filename, "w");
            if (image == NULL)
            {
                printf("Error opening new file.\n");
                return 1;
            }

            fprintf(image, retrieved);

            printf("Image %i found.\n", ++c);
        } 
        else 
        {
            if (image != NULL)
            {
                fprintf(image, retrieved);
            }
        }
    }
}
