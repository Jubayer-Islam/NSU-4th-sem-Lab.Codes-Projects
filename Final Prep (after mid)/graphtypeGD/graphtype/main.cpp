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
    gg.AddVertex('F');
    gg.AddVertex('G');
    gg.AddVertex('H');

    gg.AddEdge('A','B',1);
    gg.AddEdge('A','C',1);
    gg.AddEdge('A','D',1);
    gg.AddEdge('B','A',1);
    gg.AddEdge('D','A',1);
    gg.AddEdge('D','E',1);
    gg.AddEdge('D','G',1);
    gg.AddEdge('F','H',1);
    gg.AddEdge('G','F',1);
    gg.AddEdge('H','E',1);

    cout << gg.OutDegree('D') << endl;

    if(gg.FoundEdge('A','D'))
    {
        cout << "There is an edge" << endl;
    }
    else
    {
        cout << "There is no edge" << endl;
    }

    if(gg.FoundEdge('B','D'))
    {
        cout << "There is an edge" << endl;
    }
    else
    {
        cout << "There is no edge" << endl;
    }

    gg.DepthFirstSearch('B','E');
    gg.DepthFirstSearch('E','B');

    gg.BreadthFirstSearch('B','E');
    gg.BreadthFirstSearch('E','B');
    gg.ModifiedBreadthFirstSearch('B','E');

}
