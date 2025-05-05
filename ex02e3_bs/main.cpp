#include<cstdio>

int a[100000];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(m--)
    {
        int x;
        scanf("%d",&x);
        if(a[0] > x){ printf("-1\n"); continue; }
        int low = 0, high = n-1, mid, ans;
        while(low <= high)
        {
            mid = (low+high)>>1;
            if(a[mid] <= x)
                ans = mid, low = mid+1;
            else
                high = mid-1;
        }
        printf("%d\n",ans);
    }
}

