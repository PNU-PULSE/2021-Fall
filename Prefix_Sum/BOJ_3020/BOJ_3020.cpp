#include <iostream>
#include<string.h>
using namespace std;

int main() {
  int caveLen,caveHeight;
  int ceiling[500001];
  int floor[500001];
  int count =0, minResult=200001;
  int length;

  cin>>caveLen>>caveHeight;
  memset(ceiling, 0 , sizeof(ceiling));
  memset(floor, 0 , sizeof(floor));

  
  for(int index=0; index<caveLen ; ++index){
    cin>>length;
    if(index % 2 ==0)
      ++floor[length];
    else
      ++ceiling[caveHeight -length +1];
  }

  for(int h=caveHeight-1; h>0; --h)
    floor[h] += floor[h+1];

  for(int h=2; h<=caveHeight ; ++h)
    ceiling[h] += ceiling[h-1];

  for(int h=1; h<=caveHeight ; ++h){
    if(ceiling[h] + floor[h] == minResult){
      ++count;
    }else if(ceiling[h] + floor[h] < minResult){
      count =1;
      minResult = ceiling[h] + floor[h];
    }
  }

  cout<<minResult<<" "<<count<<"\n";
  return 0;
}