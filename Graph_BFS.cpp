#include<bits/stdc++.h>
using namespace std;

class graph{
public:
  map<int, bool> visited;     //map to keep record og visited nodes
  map<int, list<int>> adj;    //adjacency list

  //function to add an edge to the graph
  void addEdge(int u, int v);

  //BFS transversal of vertices
  void BFS(int u);
};

void graph::addEdge(int u, int v){
  adj[u].push_back(v);
}

void graph::BFS(int u){


  queue<int> que;         //create a queue for BFS

  //mark the current node as visited and enequeue it
  visited[u] = true;
  que.push(u);

  list<int>::iterator i;

  while(!que.empty()){
    u = que.front();
    cout<<u<<" ";
    que.pop();


    for(i = adj[u].begin(); i != adj[u].end(); i++){
      if(!visited[*i]){
        visited[*i] = true;
        que.push(*i);
      }
    }
  }

}

int main(){
  graph g;
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.BFS(2);

  return 0;

}
