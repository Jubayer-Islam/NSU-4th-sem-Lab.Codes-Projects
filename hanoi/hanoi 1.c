#include <stdio.h>
void hanoi(int n, char src, char dst, char aux)
{
    if(n == 1)
        {printf("Move disc %d from peg %c to peg %c\n",n , src, dst);}
    else
    {

        hanoi(n-1, src, aux, dst);
           printf("Move disc %d from peg %c to peg %c\n",n , src, dst);
        hanoi(n-1, aux, dst, src);

    }

    /*
     if(n == 1)
        {printf("Move disc %d from peg %c to peg %c\n",n , src, dst);}
//writting, if(n != 1){printf("Move disc %d from peg %c to peg %c\n",n , src, dst);} shows the one real move
    */
    /** shows only the moves not which disk, but these are the real algorithm */
    /*
    else
    {
        hanoi(n-1, src, aux, dst);
        hanoi(1, src, dst, aux);
        hanoi(n-1, aux, dst, src);
    }
    */

}

int main()
{

	hanoi(2, 'A', 'C', 'B');
	return 0;
}


/*
// C++ recursive function to
// solve tower of hanoi puzzle #more_complex

#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from_rod,
                    char to_rod, char aux_rod)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from_rod <<
                            " to rod " << to_rod<<endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod <<
                                " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}
*/
