#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class DSU{
private:
    vector<int> parent;
    vector<int> S;
public:
    DSU(int n) {
		// initially each node points to itself (its own root)
		parent.resize(n);
		S.resize(n,1);
		for (int i = 0; i < n; i++)
			{parent[i] = i;}
	}
	int findset(int n) {
        if (parent[n] == n) return n;
        return parent[n] = findset(parent[n]); // Path compression
    }
	int uni(int x,int y,int &clus){
        int s1 = findset(x);
        int s2 = findset(y);
        if(S[s1] > S[s2]){
            parent[s2] = s1;
            S[s1] = S[s1] + S[s2];
        }else{
            parent[s1] = s2;
            S[s2] = S[s1] + S[s2];
        }
        clus--;
        return clus;
	}
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,q,a,b,c,d;
    cin >> n >> m >> q;
    vector<int> cluster (n+1,0);
    vector<tuple<int,int,int>> w;

    for(int i = 0;i<m;i++){
        cin >> a >> b >> c;
        w.push_back({c,a,b});
    }
    sort(w.begin(),w.end());
    DSU dsu(n);

    int clus = n;
    int temp = 0;
    for(auto [t,u,v] : w){
        if(dsu.findset(u) != dsu.findset(v)){
            temp+=t;
            cluster[dsu.uni(u,v,clus)] = t;
        }
    }

    for(int i = 0;i<q;i++){
        cin >> d;
        cout << cluster[d] << "\n";
    }
    return 0;
}
