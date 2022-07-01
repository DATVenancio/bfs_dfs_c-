#include <iostream>
#include <queue>
#include <cstring>


#define SIZE 10

using namespace std;

bool visited[SIZE];
int graph[SIZE][SIZE];


dfs(int vertice){
  visited[vertice]=true;
  cout<<vertice<<"-";

  for(int i=0; i<SIZE;i++){
    //cout<<graph[vertice,i];
    if(graph[vertice][i]){

      if(!visited[i]) dfs(i);

    }
  }
}




bfs(int start){
  queue<int> list;
  int next_vertice;
  list.push(start);
  visited[start]=true;
  cout<<start<<"-";

  while(!list.empty()){
    int vertice = list.front();
    list.pop();

    for(int i =0; i<SIZE;i++){
      if(graph[vertice][i]){
        next_vertice = i;
      }


      if(!visited[next_vertice]){
        list.push(next_vertice);
        visited[next_vertice]=true;
        cout<<next_vertice<<"-";
      }
    }
  }
}


explore(int choice){
  for(int i=0; i<SIZE;i++)
    visited[i]= false;

  if(choice==1){
    for(int i=0;i<SIZE;i++){
      if(!visited[i]) dfs(i);
    }
  }

  if(choice==2){
    for(int i=0;i<SIZE;i++){
      if(!visited[i]) bfs(i);
    }
  }
}

int main(){
  int edges;
  int edge_start, edge_end;

  memset(graph, 0, sizeof graph);

  cout<< "AMOUNT OF EDGDES: ";
  cin>>edges;

  cout<< "EDGES( from to): \n";

  for(int i=0; i<edges; i++){
    cin>> edge_start>>edge_end;
    graph[edge_start][edge_end]=1;
    graph[edge_end][edge_start]=1;
  }


  cout<<"GRAPH:"<<endl;
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      cout<<graph[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<endl;

  cout<<"DFS: ";
  explore(1);
  cout<<endl;

  cout<<"BFS: ";
  explore(2);
  cout<<endl;

  return 0;

}
