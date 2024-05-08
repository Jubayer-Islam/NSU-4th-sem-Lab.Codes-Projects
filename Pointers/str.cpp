#include<iostream>
using namespace std;

int main()
{
    int a = 7, b = 8;
    int *p = &a;
    cout<<a<<","<<b<<","<<*p<<endl;
    *p = 10;
    cout<<a<<","<<b<<","<<*p<<endl;
    p = &b;
    cout<<a<<","<<b<<","<<*p<<endl;
    b++;
   cout<<a<<","<<b<<","<<*p<<endl;

int A[6]={3,1,8,7};
int *ptr; //*ptr=A;
ptr=A;

*(ptr+2)=7; //{3,1,7,7}
ptr=&A[1];
*(ptr+2)=10; //{3,1,7,10}
ptr[1]=11;  //{3,1,11,10}
for(int i=0;i<4;i++)
{
    cout<<A[i]<<" ";
}
cout<<endl;


int *grades=NULL;
int numberOfGrades;

cout << "Enter the number of grades: ";
cin >> numberOfGrades;
grades = new int[numberOfGrades];

for (int i = 0; i < numberOfGrades; i++)
  {
      cin >> grades[i];
  }

grades[numberOfGrades-1]=10;
for (int j = 0; j < numberOfGrades; j++)
      cout << grades[j] << " ";

delete [] grades;
grades = NULL;

// create a 2D array dynamically
int rows, columns, i, j,c;
int **matrix;
cout<<"enter rows and columns for 2D array:"<<endl;
cin >> rows >> columns;
matrix = new int*[rows];
for(i=0; i<rows; i++)
   matrix[i] = new int[columns];
for(i=0; i<rows; i++)
   for(j=0; j<columns; j++)
      {cin>>matrix[i][j];}
// deallocate the array
for(i=0; i<rows; i++)
   delete [] matrix[i];
delete [] matrix;

}
