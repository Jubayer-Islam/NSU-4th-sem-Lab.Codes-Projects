#include <iostream>
#include "stacktype.cpp"

using namespace std;

// function to check if parenthesis are balanced (for all types of brackets)
bool areParanthesisBalanced(string expr)
{
    stacktype<char> s(10);
    char x;

    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
        {

            s.Push(expr[i]);
            continue;
        }

        if (s.IsEmpty())
           return false;

        switch (expr[i])
        {
        case ')':


            x = s.Top();
            s.Pop();
            if (x=='{' || x=='[')
                return false;
            break;

        case '}':


            x = s.Top();
            s.Pop();
            if (x=='(' || x=='[')
                return false;
            break;

        case ']':


            x = s.Top();
            s.Pop();
            if (x =='(' || x == '{')
                return false;
            break;
        }
    }

    // Check Empty Stack
    return (s.IsEmpty());
}

// function to check if parenthesis are balanced
bool isBalanced(string s)
{
    stacktype<char> a(10);

    for (int i=0; i<s.length(); i++)
    {
        if (s[i]=='(')
        {
            a.Push(s[i]);
        }

        if (a.IsEmpty())
           return false;

        if (s[i]==')')
        {
            a.Pop();
        }
    }

    return (a.IsEmpty());
}

int main()
{


    cout<<"Check if the string of parentheses is balance or not :"<<endl;
    string S = "()";
    cout<<" for '"<<S<<"': ";
    if (isBalanced(S))
        cout << "Balanced"<<endl;
    else
        cout << "Not Balanced"<<endl;

    string S1 = "(())()(()())()";
    cout<<" for '"<<S<<"': ";
    if (isBalanced(S1))
        cout << "Balanced"<<endl;
    else
        cout << "Not Balanced"<<endl;

    string S2 = "(())()(()";
    cout<<" for '"<<S2<<"': ";
    if (isBalanced(S2))
        cout << "Balanced"<<endl;
    else
        cout << "Not Balanced"<<endl;

    string S3 = "(())))(()";
    cout<<" for '"<<S3<<"': ";
    if (isBalanced(S3))
        cout << "Balanced"<<endl;
    else
        cout << "Not Balanced"<<endl;

    return 0;
}
