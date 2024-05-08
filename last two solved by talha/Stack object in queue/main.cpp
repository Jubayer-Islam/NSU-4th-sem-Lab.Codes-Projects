#include <iostream>
#include "quetype.cpp"


using namespace std;



//print function to print the elements of the queue
void qPrint(QueType<int>ob1){

    cout<<endl<<"The values of queue: ";

    while(ob1.IsEmpty()!=true){
        int temp=0;
        ob1.Dequeue(temp);
        cout<<temp<<" ";

    }

    cout<<endl;
}


int main()
{
    QueType<int> q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);

    if(q.IsEmpty())
        cout<<"The queue is empty\n";
    else
        cout<<"The queue is not empty\n";


    qPrint(q);



    return 0;
}
