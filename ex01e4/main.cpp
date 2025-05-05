#include <iostream>

using namespace std;

int recur(int x,int n,int k){
    if(n==1){return x%k;}

    if(n%2==0){
        return (recur(x,n/2,k)*recur(x,n/2,k))%k;
    }else{
        return ((recur(x,n/2,k)*recur(x,n/2,k))%k * (x%k))%k;
    }
}

int main()
{
    int x,n,k;
    cin >> x >> n >> k;
    cout << recur(x,n,k)%k;
}
