// Internally vertex are stored from 0 based index
// Outputed from index 1


#include <iostream>
#include <vector>
#include <utility>

using Graph  =  std::vector<std::vector<int>>;
using Order = std::vector<std::pair<int,int>>;

std::vector<std::vector<int>> G;
void print_graph(Graph&);
void initialise_graph(Graph&,int);
void explore(int,Graph&,std::vector<bool> &,Order &);
void DFS(Graph&,std::vector<bool> &,Order &);
void print_order(Graph&,Order&);


int pre_post_order(){
    static int order = 0;
    ++order;
    return order;
}

int main(){


  size_t n, m;
  std::cin >> n >> m;
  Graph G(n,std::vector<int>());

  std::vector<bool> visited(n);
  Order postpre(n);


  initialise_graph(G,m);
  print_graph(G);
  DFS(G,visited,postpre);
  print_order(G,postpre);
  return 0;
}

 
void explore(int vertex, Graph &G, std::vector<bool> &visited, Order &postpre){
    std::cout<<"Visiting:"<<vertex+1<<std::endl;
       
    postpre[vertex].first = pre_post_order();
    visited[vertex] = true;
    for( const int &w:G[vertex]){
        if(!visited[w]){
            explore(w,G,visited,postpre);
        }
    }
    postpre[vertex].second = pre_post_order();
}

void DFS(Graph &G, std::vector<bool> &visited, Order &postpre){
    for(int i=0;i<G.size();i++){
        if(!visited[i]){
            explore(i,G,visited,postpre);
        }   
    }
}

void initialise_graph(Graph &G, int edges){

  for (size_t i = 0; i < edges; i++)
  {
    int x, y;
    std::cin >> x >> y;
    G[x - 1].push_back(y - 1);
  }

}
    
void print_graph(Graph &G){

for(int i=0;i<G.size();i++){
    std::cout<<i+1<<":";
    for(int j=0;j<G[i].size();j++){
        std::cout<<G[i][j]+1<<",";
    }
    std::cout<<std::endl;
}
 
}
    
void print_order(Graph &G,Order &O){

for(int i=0;i<G.size();i++){
    std::cout<<i+1<<":"<<O[i].first<<"/"<<O[i].second;
    std::cout<<std::endl;
}
 
}
