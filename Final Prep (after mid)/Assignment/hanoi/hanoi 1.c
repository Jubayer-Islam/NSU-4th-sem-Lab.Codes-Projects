#include <stdio.h>
void hanoi(int n, char src, char dst, char aux)
{
    if(n == 1)
        {printf("Move disc %d from peg %c to peg %c\n",n , src, dst);
        return ;}
    else
    {

        hanoi(n-1, src, aux, dst);
           printf("Move disc %d from peg %c to peg %c\n",n , src, dst);
        hanoi(n-1, aux, dst, src);

    }
}

int main()
{

	hanoi(4, 'A', 'C', 'B');
	return 0;
}

