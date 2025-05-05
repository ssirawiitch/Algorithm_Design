#include <iostream>

using namespace std;

int n;
void recur(int latest,int sum,int &co){

    if(sum > n){return ;}
    if(sum == n){
        co++;
        return;
    }
    for(int i = latest;i<n;i++){
        recur(i,sum+i,co);
    }
}

int main()
{
    cin >> n;
    int co = 0;
    for(int i = 1;i<=n;i++){
        recur(i,i,co);
    }
    cout << co;
    return 0;
}
