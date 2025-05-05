#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;

const int MAXN(55);

#define VII vector< vector<int> >

priority_queue< pair<int,VII> >q;

map<VII,int>path;

int d[4][2] = {1,0,-1,0,0,1,0,-1};

int heuristic(VII &node){

    int h = 0;

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            if(node[i][j] == 0) continue;
            int x = node[i][j];
            h += abs(i-(x-1)/4) + abs(j-(x-1)%4);
        }

    return h;
}

int main(){

    vector< vector<int> > start(4), finish(4);

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            int x;
            scanf("%d",&x);
            start[i].push_back(x);
        }

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            finish[i].push_back(i*4 + j + 1);

    finish[3][3] = 0;

    if(start == finish)
    {
        printf("0");
        return 0;
    }

    q.push(make_pair(-heuristic(start),start));
    path[start] = 0;

    while(!q.empty())
    {
        VII node = q.top().second;

        q.pop();

        int nmove = path[node];

        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                if(node[i][j] == 0)
                {
                    for(int k=0;k<4;k++)
                    {
                        int x = i + d[k][0];
                        int y = j + d[k][1];

                        if(x < 0 || x >=4 || y < 0 || y >= 4) continue;

                        swap(node[i][j], node[x][y]);

                        if(!path.count(node))
                        {
                            if(node == finish)
                            {
                                printf("%d",nmove+1);
                                return 0;
                            }

                            q.push(make_pair(-(nmove+1+heuristic(node)),node));
                            path[node] = nmove + 1;
                        }

                        swap(node[i][j], node[x][y]);
                    }
                }
            }
    }
}

