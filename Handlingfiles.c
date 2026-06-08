#include<stdio.h>
int main()
{
FILE *fp;
char c;

fp = fopen("Female_Basketball_Evolution.docx", "rb");
if(fp != NULL)
{
c = getc(fp);
while (c != EOF)
{printf("%c",c);
c = getc(fp);
}
fclose(fp);
}
else
printf("\nError while openopening file....");

return 0;
}