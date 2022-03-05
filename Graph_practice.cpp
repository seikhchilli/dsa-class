#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<char, list<char> > adj;
    map<char, bool> visited;

public:
  void addEdge(char u, char v){
    adj[u].push_back(v);
  }

  void DFS(char v){
    visited[v] = true;
    cout<<v<<" "<<endl;

    list<char>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++){
      if(!visited[*i]){
        DFS(*i);
      }
    }
  }

  void BFS(char v){
    queue<char> q;

    visited[v] = true;
    q.push(v);

    while(!q.empty()){
      v = q.front();
      cout<<v<<endl;
      q.pop();

      list<char>::iterator i;
      for(i = adj[v].begin(); i != adj[v].end(); i++){
        if(!visited[*i]){
          visited[*i] = true;
          q.push(*i);

        }
      }
    }

  }

};

int main(){
  Graph g;
  g.addEdge('f', 'b');
  g.addEdge('f', 'd');
  g.addEdge('b', 'a');
  g.addEdge('b', 'f');
  g.addEdge('b', 'd');
  g.addEdge('d', 'a');
  g.addEdge('d', 'b');
  g.addEdge('d', 'f');
  g.addEdge('a', 'b');
  g.addEdge('a', 'c');
  g.addEdge('a', 'd');
  g.addEdge('a', 'e');
  g.addEdge('c', 'a');
  g.addEdge('c', 'g');
  g.addEdge('g', 'c');
  g.addEdge('g', 'e');
  g.addEdge('e', 'a');
  g.addEdge('e', 'g');

  g.BFS('a');

}
