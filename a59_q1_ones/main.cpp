#include"bits/stdc++.h"
#define I int
I N,K,Q[11];
I S(I X,I K){
    if(X<12)return std::min(X,13-X);
    I C=X/Q[K],D=X%Q[K];
    return C*K+std::min(S(D,K-1),K+S((Q[K]-D)%Q[K],K-1));
}
main(){
    scanf("%d",&N);
    for(;Q[K]<=N;Q[K+1]=Q[K]*10+1,K++);
    printf("%d",S(N,K));
}
