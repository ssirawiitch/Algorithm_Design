#include <iostream>
#include <vector>
#include <string>

using namespace std;

int con[3][3];

void recur(string s,int n,int i,int j,int k,vector<string> &ans,int len){

    if(len == n){ans.push_back(s);return;}

    if(len < 1){
        if(i>0){recur(s+"A",n,i-1,j,k,ans,len+1);}
        if(j>0){recur(s+"B",n,i,j-1,k,ans,len+1);}
        if(k>0){recur(s+"C",n,i,j,k-1,ans,len+1);}
    }
    else{
        if(i>0 && !con[s[s.size()-1] - 'A'][0]){recur(s+"A",n,i-1,j,k,ans,len+1);}
        if(j>0 && !con[s[s.size()-1] - 'A'][1]){recur(s+"B",n,i,j-1,k,ans,len+1);}
        if(k>0 && !con[s[s.size()-1] - 'A'][2]){recur(s+"C",n,i,j,k-1,ans,len+1);}
    }


}

int main()
{
    int n,i,j,k,m;
    string s;
    cin >> n >> i >> j >> k >> m;
    vector<string> ans;
    for(int o = 0;o<m;o++){
        cin >> s;
        if(s=="AA"){con[0][0]=1;}
        if(s=="BA"){con[1][0]=1;}
        if(s=="CA"){con[2][0]=1;}
        if(s=="AB"){con[0][1]=1;}
        if(s=="BB"){con[1][1]=1;}
        if(s=="CB"){con[2][1]=1;}
        if(s=="AC"){con[0][2]=1;}
        if(s=="BC"){con[1][2]=1;}
        if(s=="CC"){con[2][2]=1;}
    }

    recur("",n,i,j,k,ans,0);
    cout << ans.size() << endl;
    for(auto &x:ans){
        cout << x << endl;
    }
}
