#include<iostream>
#include<cmath>
using namespace std;

void printRev(int n)
{
    cout<<n<<",";
    if(n>1)
        printRev (n-1);

}

void printFwd(int n)
{

    if(n>1)

        printFwd (n-1);
        cout<<n<<",";

}

void printBoth(int n)
{
cout<<n<<",";

    if(n>1){
        printBoth(n-1);
        cout<<n<<",";
    }

}




int fib(int n){
    if (n == 1)
            return (1);

     if(n == 0)
            return (0);
    else {
        return (fib(n-1)+fib(n-2));
    }
}

int factorial(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }
}
int sumOfDigits(int x)
{
    if(x==0)
    {
        return 0;
    }

    else
    {
        return (x%10+sumOfDigits(x/10));
    }
}
int DecToBin(int dec)
{
    if(dec==0)
    {
        return 0;
    }
    else
    {
        return (dec%2+10*DecToBin(dec/2));
    }
}

int findMin(int a[],int n)
{
    if(n==0)
    {
        return a[0];
    }
    else
    {
        if(a[n-1]<findMin(a,(n-1)))
        {
            return a[n-1];
        }
        else
        {
            return findMin(a,(n-1));
        }


    }
}
    float sum(int n){
    if(n==0){
        return (1);
    }
    else
       // return (sum(n-1)+(1/pow(2,n-1)));
         return sum(n-1)+(1/pow(2,n));
}









int main()
{
    cout<<"NOTE: all inputs are already given"<<endl;
    int n=5;
    cout<<"input for fibonacci & factorial: (ex: 7) "<<endl;
     cout << "last (nth) num of fibonacci series is= " << fib( 7)<<endl;
     cout << "factorial is= " << factorial(n)<<endl;

         cout<<"input for sum of digits:(ex: 22) "<<endl;
         int digit=22;

     cout<<"sum of input="<<sumOfDigits(digit)<<endl;

      cout<<"input elements in array from which user want to find minimum: "<<endl;

         int x=3,k;

         int min[10];

           min[0]=10;
           min[1]=14;
           min[2]=5;

     cout<<"minimum="<< findMin(min,x)<<endl;


      cout<<"input for decimal to binary: (ex: 5)  "<<endl;
         int deci=5;

     cout<<"Decimal="<<DecToBin(deci)<<endl;


      cout<<"sum of (1+(1/2)+(1/4)...+(1/2^n)) series,enter n: "<<endl;
       n=3;

     cout<<"series="<<sum(n)<<endl;


    cout<<"elements from n down-to 1:"<<endl;printRev(4);
    cout<<endl<<"elements up-to n:"<<endl;printFwd(4);
    cout<<endl<<"elements both rev and fwd :"<<endl;printBoth(4);




}

