
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


    return 0;
}
