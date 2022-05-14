#define STB_IMAGE_IMPLEMENTATION
#include <stdio.h>
#include <string.h>
#include "stb_image.h"

typedef struct IntStr
{
    char buf[12];
    int len;
} IntStr;

IntStr
intToString(int n){
    IntStr result;

    sprintf(result.buf, "%d", n);
    result.len = strlen(result.buf);
    return result;
}

int 
main(int argc, char const *argv[])
{
    if(argc != 2){
        puts("imgToRaw\nError expects one argument, a path to an image file");
        return 1;    
    }

    // load image
    const char* imageFileName = argv[1];
    int width, height, channelCount;
    
    unsigned char* data = stbi_load(imageFileName, &width, &height, &channelCount, 0);
    if(data == NULL){
        printf("unable to parse image file %s\n", imageFileName);
        return 1;
    }
    size_t dataSize = width * height * channelCount;

    printf("image info:\nwidth: %dpx, height: %dpx, channel count: %d.\n", width, height, channelCount);

    // prepare output filename
    // "./imagefilename_w_h_c.raw"
    IntStr widthStr = intToString(width);
    IntStr heightStr = intToString(height);
    IntStr channelCountStr = intToString(channelCount);
    int outputFilenameBufLen = strlen(imageFileName) + widthStr.len + heightStr.len + channelCountStr.len + 7 + 1;
    char* outputFilenameBuf = (char*) malloc(outputFilenameBufLen);

    if(outputFilenameBuf == NULL){
        puts("unable to allocate memory for output filename");
        free(data);
        return 1;
    }

    sprintf(outputFilenameBuf, "%s.%s_%s_%s.raw", imageFileName, widthStr.buf, heightStr.buf, channelCountStr.buf);
    printf("output filename: %s\n", outputFilenameBuf);

    {
        // writing file
        FILE *file = NULL;
        file = fopen(outputFilenameBuf, "wb");
        if(file == NULL){
            printf("unable to open file %s\n", outputFilenameBuf);
            free(data);
            return 1;
        }
        fwrite(data, dataSize, 1, file);
        fclose(file);
    }


    free(outputFilenameBuf);
    free(data);

    return 0;
}
