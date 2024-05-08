#include <iostream>
#include "graphtype.cpp"
using namespace std;

int main()
{
    GraphType<char> gg;

    gg.AddVertex('A');
    gg.AddVertex('B');
    gg.AddVertex('C');
    gg.AddVertex('D');
    gg.AddVertex('E');

    gg.AddEdge('A','E',1);
    gg.AddEdge('A','B',1);
    gg.AddEdge('A','C',1);
    gg.AddEdge('B','E',1);
    gg.AddEdge('B','D',1);
    gg.AddEdge('C','E',1);
    gg.AddEdge('D','C',1);

    int path=0;
    QueType<char>q,toq;
    //adding all possible vertex from which there can be a path to E
    q.Enqueue('A'); //direct path
    q.Enqueue('B'); //A to B and B to E
    q.Enqueue('C'); //A to C and C to E
    q.Enqueue('D'); //A to B, B to D, D to C and C to E


    char vrtx,midvertex;

   while(!q.IsEmpty())
   {

        q.Dequeue(vrtx);

    if(gg.FoundEdge(vrtx,'E'))
    {
        //if direct path exists
        path++;
    }
    else
    {
        //finding the mid vertex
        gg.GetToVertices(vrtx,toq);

        {
            toq.Dequeue(midvertex);
            if(gg.FoundEdge(midvertex,'E'))
            {
                //if a path from mid vertex to target vertex exists, indirect path exists
                path++;
            }
        }
    }
   }

    cout<<"total path between A and E: "<<path;



}
