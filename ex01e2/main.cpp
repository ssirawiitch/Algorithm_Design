#include <iostream>
using namespace std;

int K[100000];
void sequence(int start,int &ans,int n,int currentsum){
    if(start > n){return ;}
    currentsum += K[start];

    ans = max(ans,currentsum);

    if (currentsum < 0) {
        currentsum = 0;
    }
    sequence(start+1,ans,n,currentsum);
}

int main()
{
    int N,num,s;
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> num;
        K[i] = num;
    }
    int ans = K[0];
    sequence(0,ans,N-1,0);
    cout << ans;
}
