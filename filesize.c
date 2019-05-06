#include <stdio.h>

long getFileSize(const char* filePath)
{
    long result = -1;
    FILE *fp = NULL;

    if((fp = fopen(filePath, "r")) == NULL)
    {
        return result;
    }

    fseek(fp, 0, SEEK_END);

    result = ftell(fp);

    return result;
}

int main()
{
    const char* filePath = "/mnt/c/study/c/put_out.png";
    long size = getFileSize(filePath);

    printf(" %s size is %ld\n", filePath, size);

    return 0;
}
