#include "graphtype.h"
#include "stacktype.cpp"
#include "quetype.cpp"
using namespace std;
const int NULL_EDGE = 0;

template<class VertexType>
GraphType<VertexType>::GraphType()
{
    numVertices = 0;
    maxVertices = 50;
    vertices = new VertexType[50];
    edges = new int*[50];
    for(int i = 0; i < 50 ;i++)
    {
        edges[i] = new int [50];
    }
    marks = new bool[50];
}

template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
{
    numVertices = 0;
    maxVertices = maxV;
    vertices = new VertexType[maxV];
    edges = new int*[maxV];
    for(int i = 0; i < maxV ;i++)
    {
        edges[i] = new int [maxV];
    }
    marks = new bool[maxV];
}

template<class VertexType>
GraphType<VertexType>::~GraphType()
{
    delete [] vertices;
    delete [] marks;
    for(int i = 0 ; i < maxVertices ; i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
}

template<class VertexType>
void GraphType<VertexType>::MakeEmpty()
{
    numVertices = 0;
}

template<class VertexType>
bool GraphType<VertexType>::IsEmpty()
{
    return (numVertices == 0);
}

template<class VertexType>
bool GraphType<VertexType>::IsFull()
{
    return (numVertices == maxVertices);
}

template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
{
    vertices[numVertices] = vertex;
    edges[numVertices][numVertices] = NULL_EDGE;
    for(int index = 0; index < numVertices ; index++)
    {
        edges[numVertices][index] = NULL_EDGE;
        edges[index][numVertices] = NULL_EDGE;
    }
    numVertices++;
}

template <class VertexType>
int IndexIs (VertexType* vertices,VertexType vertex)
{
    int index = 0;
    while(!(vertex == vertices[index]))
    {
        index++;
    }
    return index;
}

template<class VertexType>
void GraphType<VertexType>::ClearMarks()
{
    for (int i = 0 ; i < maxVertices ; i++)
    {
        marks[i] = false;
    }
}

template<class VertexType>
void GraphType<VertexType>::MarkVertex(VertexType vertex)
{
    int index = IndexIs(vertices,vertex);
    marks[index] = true ;
}

template<class VertexType>
bool GraphType<VertexType>::IsMarked(VertexType vertex)
{
    int index = IndexIs(vertices,vertex);
    return marks[index];
}

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex,VertexType toVertex, int weight)
{
  int row = IndexIs(vertices, fromVertex);
  int col= IndexIs(vertices, toVertex);
  edges[row][col] = weight;
}


template<class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex, VertexType toVertex)
{
  int row = IndexIs(vertices, fromVertex);
  int col= IndexIs(vertices, toVertex);

  return edges[row][col];
}

template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex, QueType<VertexType>& adjVertices)
{
  int fromIndex;
  int toIndex;

  fromIndex = IndexIs(vertices, vertex);
  for (toIndex = 0; toIndex < numVertices; toIndex++)
  {
      if (edges[fromIndex][toIndex] != NULL_EDGE)
      {
          adjVertices.Enqueue(vertices[toIndex]);
      }
  }
}

template<class VertexType>
void GraphType<VertexType>:: DepthFirstSearch(VertexType startVertex, VertexType endVertex)
{
	StackType<VertexType> stack;
	QueType<VertexType> vertexQ;

	bool found = false;
	VertexType vertex;
	VertexType item;

	ClearMarks();
	stack.Push(startVertex);
	do
	{
		vertex = stack.Top();
		stack.Pop();
		if (vertex == endVertex)
		{
			cout << vertex << " ";
			found = true;
		}
		else
		{
			if (!IsMarked(vertex))
			{
				MarkVertex(vertex);
				cout << vertex << " ";
				GetToVertices(vertex, vertexQ);

				while (!vertexQ.IsEmpty())
				{
					vertexQ.Dequeue(item);
					if (!IsMarked(item))
                    {
                        stack.Push(item);
                    }
				}
			}
		}
	} while (!stack.IsEmpty() && !found);
	cout << endl;
	if (!found)
    {
        cout << "Path not found." << endl;
    }
}

template<class VertexType>
void GraphType<VertexType>:: BreadthFirstSearch(VertexType startVertex, VertexType endVertex)
{
	QueType<VertexType> queue;
	QueType<VertexType> vertexQ;

	bool found = false;
	VertexType vertex;
	VertexType item;

	ClearMarks();
	queue.Enqueue(startVertex);
	do
	{
		queue.Dequeue(vertex);
		if (vertex == endVertex)
		{
			cout  << vertex <<" ";
			found = true;
		}
    	else
		{
			if (!IsMarked(vertex))
			{
				MarkVertex(vertex);
				cout  << vertex << " ";
				GetToVertices(vertex, vertexQ);

				while (!vertexQ.IsEmpty())
				{
					vertexQ.Dequeue(item);
					if (!IsMarked(item))
                    {
                        queue.Enqueue(item);
                    }
				}
			}
		}
	} while (!queue.IsEmpty() && !found);

	cout << endl;
	if (!found)
    {
        cout << "Path not found." << endl;
    }
}

template <class VertexType>
int GraphType<VertexType>::OutDegree(VertexType v)
{
    int count = 0;
    int fromIndex;
    int toIndex;
    fromIndex = IndexIs(vertices, v);
    for (toIndex = 0; toIndex < numVertices; toIndex++)
    {
        if (edges[fromIndex][toIndex])
        {
            count++;
        }
    }
    return count;
}

template <class VertexType>
bool GraphType<VertexType>::FoundEdge (VertexType u,VertexType v)
{
    int v1 = IndexIs(vertices,u);
    int v2 = IndexIs(vertices,v);

    if(edges[v1][v2])
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class VertexType>
void GraphType<VertexType>::ModifiedBreadthFirstSearch(VertexType startVertex, VertexType endVertex)
{
    cout<<endl<<"Path: ";

	QueType<VertexType> queue;
	QueType<VertexType> vertexQ;

    int count=0;
	bool found = false;
	VertexType vertex,v1;
	VertexType item;

	ClearMarks();
	queue.Enqueue(startVertex);
	do
	{
		queue.Dequeue(vertex);
		if (vertex == endVertex)
		{
			cout  << vertex<<" ";
			found = true;
		}
        else
		{
			if (!IsMarked(vertex))
			{
				MarkVertex(vertex);

				GetToVertices(vertex, vertexQ);

				while (!vertexQ.IsEmpty())
				{
					vertexQ.Dequeue(item);
					if (!IsMarked(item))
					queue.Enqueue(item);
					if(v1!=vertex){
                        cout  << vertex<<" ";
                        count++;
					}
					v1=vertex;
				}
			}
		}
	} while (!queue.IsEmpty() && !found);
	if (!found)
	cout << "Path not found." << endl;
	cout<<endl<<"Length: "<<count;
}
