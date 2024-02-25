#include<iostream>
#include<list>
using namespace std;

class graph{
   int numvertices;
   list<int> *adjLists;
   bool *visited;
   public:
   graph(int v);
   void addedge(int src,int dest);
   void DFS(int vertex);
};
graph::graph(int vertices)
{
    numvertices =vertices;
    adjLists =new list<int>[vertices];
    visited =new bool[vertices];

}
void graph::addedge(int src,int dest)
{
    adjLists[src].push_front(dest);
}
void graph::DFS(int vertex)
{
    visited[vertex]=true;
    list<int>adjList =adjLists[vertex];
    cout<<vertex<<" ";
    list<int>::iterator i;
    for(i=adjList.begin();i!=adjList.end();i++)
     if(!visited[*i])
        DFS(*i);
}
int main()
{
    graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
     g.addedge(2,3);
     g.DFS(2);
     return 0;
   


}