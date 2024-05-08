#include "queue.cpp"
#include "list.cpp"
#include "stack.cpp"
#include <iostream>
#include<string>

using namespace std;

bool IsPalindrome(string);
bool IsReverse(string,string);

bool IsPalindrome(string str){
   StackLL<char> S1;
   QueueLL<char> Q1;
   int x=str.length();
   bool p;



   for(int i=0;i<x;i++){
    S1.push(str[i]);
    Q1.enqueue(str[i]);

   }
   for(int i=0;i<x;i++){
        if(S1.pop()==Q1.Dequeue()){
        p=true;
        }
        else{
            p=false;
            return false;
        }

   }


   return p;


}
bool IsReverse(string  str1,string  str2){

int x=str1.length(),y=str2.length();
bool p;

   if(x==y){
     StackLL<char> S1;
     QueueLL<char> Q1;


     for(int i=0;i<x;i++){
        S1.push(str1[i]);
        Q1.enqueue(str2[i]);
     }
     for(int i=0;i<x;i++){
        if(S1.pop()==Q1.Dequeue()){
        p=true;
        }
        else{
            p=false;
            return p;
        }
     }
   }
   else{


    return false;

   }

   return p;






}


int main()
{



   string str,str1,str2;

   cout<<"Enter a string :"<<endl;
   cin>>str;

   if(IsPalindrome(str)) cout<<"Palindrome."<<endl;
   else cout<<"Not palindrome"<<endl;

   cout<<"Enter two string :"<<endl;
   cin>>str1>>str2;

    if(IsReverse(str1,str2)) cout<<"Reverse."<<endl;
    else cout<<"Not Reverse"<<endl;






    return 0;
}
