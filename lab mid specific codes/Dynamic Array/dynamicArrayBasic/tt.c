
#include <stdio.h>
int  main(void)
{
    int dd,start =1,end =10;
    for(int i=start;i<=end;i++)
    {
    scanf("%d",&dd);
    switch (dd%2){
    case 1:
        {
            printf("messing with odd\n");
            break;
        }
    case 0: {printf("messing with even\n");}
    }
   }
 return 0;
}
