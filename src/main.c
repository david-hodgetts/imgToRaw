#define STB_IMAGE_IMPLEMENTATION
#include <stdio.h>
#include <string.h>
#include "stb_image.h"

typedef struct IntStr
{
    char buf[11];
    int len;
} IntStr;

IntStr
intToString(int n){
    IntStr result;

    sprintf(result.buf, "%d", n);
    return result;
}

int 
main(int argc, char const *argv[])
{
    if(argc != 2){
        puts("imgToRaw expects one argument, namely a path to an image file");
        return 1;    
    }

    const char* imageFileName = argv[1];

    printf("arg count %d filename %s\n", argc, imageFileName);
    int width, height, channelCount;
    unsigned char* data = stbi_load(imageFileName, &width, &height, &channelCount, 0);
    if(data == NULL){
        printf("unable to parse image file %s", imageFileName);
        return 1;
    }

    size_t imageFileNameLen = strlen(imageFileName);

    IntStr widthStr = intToString(width);
    IntStr heightStr = intToString(height);
    IntStr channelCountStr = intToString(channelCount);


    printf("width %d height %d  channel count %d\n", width, height, channelCount);
    printf("strlen %ld\n", imageFileNameLen);
    printf("widthstr %s\n", widthStr.buf);

    return 0;
}
