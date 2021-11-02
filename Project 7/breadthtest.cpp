#include<iostream>
#include <list>

using namespace std;

class Graph
{

     int V; // No. of vertices

     list<int> *adj;
     public:
     Graph(int V); 
     void addEdge(int v, int w);
     void BFS(int s);
};

Graph::Graph(int V)
{
     this->V = V;
     adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
     adj[v].push_back(w); 
}

void Graph::BFS(int s)
{

     bool *visited = new bool[V];
     for(int i = 0; i < V; i++)
     {
          visited[i] = false;
     }
     list<int> queue;
     visited[s] = true;
     queue.push_back(s);



     list<int>::iterator i;
     while(!queue.empty())
     {
          s = queue.front();
          cout << s << " ";
          queue.pop_front();
          for (i = adj[s].begin(); i != adj[s].end(); ++i)
          {
               if (!visited[*i])
               {
                    visited[*i] = true;
                    queue.push_back(*i);
               }
          }
     }
}

int main()
{
     int numberOfVertices, v, adjv, i=0;
     cout << "Number Of Vertices: ";
     cin >> numberOfVertices;
     Graph g(numberOfVertices);
     while(i<numberOfVertices)
     {
          cin>>v;
          while(1)
          {
               cin>>adjv;
               if (adjv!=-999)
               {
                    g.addEdge(v,adjv);
                    g.addEdge(adjv,v);
               }

               else 
               {
                    i++;
                    break;
               }
          }
     }
     cout<<"Depth First Traversal: ";
     g.BFS(0);
     return 0;
}