#include <stdio.h>
void ReadVby(void);
char vocabulary[3207][15];
int main()
{
    ReadVby;
    
}
void ReadVby(void)
{
    char vocabulary[3207][15];
    FILE *fp = fopen("vocabulary.txt", "r");
    if (fp)
    {
        int i;
        for (i = 0; i < 3208; i++)
        {
            fscanf(fp, "%s", &vocabulary[i]);
            printf("%s\n", &vocabulary[i]);
        }
    }
}