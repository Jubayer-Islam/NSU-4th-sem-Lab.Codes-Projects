
#include "stacktype.cpp"
#include "string.h"

stacktype<int>faux;

void print(stacktype<int>st)

{
    for(int i=0; i<MAX_ITEMS; i++)
    {

        if(st.IsEmpty()==true)
        {

            break;
        }
        else
        {
            faux.Push(st.Top());

            st.Pop();
        }
    }

     cout<< "stack values:"<<endl;
    for(int i=0; i<MAX_ITEMS; i++)
    {


        if(faux.IsEmpty()==true)
        {
            break;

        }

        else
        {
            cout<<faux.Top()<<" ";
            st.Push(faux.Top());

            faux.Pop();
        }
    }
    cout<<endl;

}
bool isBalanced(string s)

{
    stacktype<char>st2;
    for (int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            st2.Push('(');
        }

        else if(s[i]==')')
        {
            if(st2.IsEmpty())
            {
                return false;
            }
            else
            {
               st2.Pop();
            }
        }
    }
    if(st2.IsEmpty())
    {
        return true;
    }
    else {return false;}

}

     int calculate (string s)
    {

        int nm1,nm2;
        stacktype<char> cal;

        for (int i=0;i<s.length();i++)
        {


            if(s[i]>=48 && s[i]<=57)
            {
                cal.Push(s[i]-'0');
            }
            else if(s[i]>=42 && s[i]<=47)
            {
                nm2=cal.Top();
                cal.Pop();
                nm1=cal.Top();
                cal.Pop();

            switch (s[i]) {

            case '+': cal.Push(nm1+nm2);
            break;
            case '-': cal.Push(nm1-nm2);
            break;
            case '*': cal.Push(nm1*nm2);
            break;
            case '/': cal.Push(nm1/nm2);
            break;

                }
            }

        }

        return cal.Top();


    }



int main()
{
    int num;
   stacktype<int> obj,aux;

   if(obj.IsEmpty())
   {
       cout<<"empty"<<endl;
   }
   else
    {
        cout<<"not empty"<<endl;
    }

        cout<<"pass 4 integers:"<<endl;

    for(int i=0;i<4;i++)
    {
        cin>>num;
         obj.Push(num);
    }

    //Check whether stack is empty or not
   if(obj.IsEmpty())
   {
       cout<<"stack is empty"<<endl;
   }
   else
    {
        cout<<"stack is not empty"<<endl;
    }

    //Check whether stack is full or not
   if(obj.IsFull())
   {
       cout<<"stack is full"<<endl;
   }
   else
    {
        cout<<"stack is not full"<<endl;
    }

    //print
    print(obj);

    //push another item
    cout<<"insert  another item:"<<endl;
    cin>>num;
    obj.Push(num);
    print(obj);

    //pop two items
    obj.Pop();
    obj.Pop();

    cout<<"after deleting two items, top items is:\n"<<obj.Top()<<endl<<endl;

    //checking string of parentheses are whether balanced or not

    cout<<"1st string () is given by default, enter the other three strings:"<<endl;

    string s1="()",s2,s3,s4;
    cout<<s1<<endl;
    cin>>s2>>s3>>s4;

    if(isBalanced(s1))
    {
        cout<<endl<<"string 1 is balanced"<<endl;
    }
    else
    {
        cout<<endl<<"string 1 is not balanced"<<endl;
    }
    if(isBalanced(s2))
    {
        cout<<"string 2 is balanced"<<endl;
    }
    else
    {
        cout<<"string 2 is not balanced"<<endl;
    }
    if(isBalanced(s3))
    {
        cout<<"string 3 is balanced"<<endl;
    }
    else
    {
        cout<<"string 3 is not balanced"<<endl;
    }
    if(isBalanced(s4))
    {
        cout<<"string 4 is balanced"<<endl;
    }
    else
    {
        cout<<"string 4 is not balanced"<<endl;
    }

        cout<<"Calculating an equation after converting it into a postfix notification:"<<endl;

        cout<<calculate("234*5+-")<<endl; /// 2-(3*4+5)=2-(12+5)=2-17=-15
        cout<<calculate("234*-5+")<<endl; /// 2-3*4+5 =2-12+5=-10+5=-5
        cout<<calculate("48+65-*32-22+*/")<<endl; /// (4+8)*(6-5)/(3-2)*(2+2)=(12*1)/(1*4)=3

    return 0;
}
