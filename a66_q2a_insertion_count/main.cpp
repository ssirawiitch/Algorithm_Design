#include<bits/stdc++.h>

using namespace std;
const int N = 2e5+10;
int a[N];
int n;
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i != n ; i++)scanf("%d",&a[i]);
    while(m--)
    {
        int key;
        scanf("%d",&key);
        int num = 0;
        int i = 0;
        while(a[i]!=key)
        {
            if(a[i++]>key)num++;
        }
        printf("%d\n",num);
    }
}
