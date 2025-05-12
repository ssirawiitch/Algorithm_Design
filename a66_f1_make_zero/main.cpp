#include<bits/stdc++.h>
using namespace std;

int main (){
  int n,ans=25;
  cin >> n;
  for (int i=0;n+i<=1<<24;i++){
    int nv=i,nn=n+i;
    while (nn&((1<<24)-1)){
      nn<<=1;
      nv++;
    }
    ans=min(ans,nv);
  }
  cout << ans;
}
