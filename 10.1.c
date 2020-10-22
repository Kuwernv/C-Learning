void MyStrcpy(char *dstStr,const char *srcStr)
{
    while((*dstStr++ = *srcStr++) != '\0')
    {
    }
}

void MyStrcpy(char *dstStr,const char *srcStr)
{
    while(*srcStr != '\0')
    {
        *dstStr = *srcStr;
        dstStr++;
        srcStr++;
    }
}