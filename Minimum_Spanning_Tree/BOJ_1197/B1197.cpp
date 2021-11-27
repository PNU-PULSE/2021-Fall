#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int V, E;
int tree[10001];

struct Edge{
  int u,v,c;
  Edge(int u, int v, int c): u(u), v(v), c(c){}
  bool operator <(const Edge &e)const{return c > e.c;}
};

int find(int n){
  if(tree[n] == n) return n;
  return tree[n] = find(tree[n]); // 경로 압축
}

void _union(int x, int y){
  x = find(x);
  y = find(y);
  if(x != y) tree[y] = x;
}

int main(){
  cin >> V >> E;
  for(int i = 1; i <= V; ++i){
    tree[i] = i; 
  }
  priority_queue<Edge, vector<Edge>> pq;
  int u_, v_, c_;
  for(int i = 0; i < E; ++i){
    cin >> u_ >> v_ >> c_;
    pq.push(Edge(u_, v_, c_));
  }

  int sum_ = 0;
  while(!pq.empty()){
    if(find(pq.top().u) != find(pq.top().v)){
      _union(pq.top().u, pq.top().v);
      sum_ += pq.top().c;
    }
    pq.pop();
  }
  cout << sum_;
}