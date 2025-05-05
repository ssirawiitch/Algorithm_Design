#include <iostream>
#include <vector>

using namespace std;

int n;
int ans = 0;

bool check(vector<int> &col){
    // diagonal if |row1 - row2| == |col1 - col2|
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            // Check if same column or same diagonal
            if (abs(i - j) == abs(col[i] - col[j])) {
                return false;
            }
        }
    }
    return true;

}

void queen(int step,vector<int> &col,vector<bool> &used){

    if(step <= n){
        for(int i = 1;i<=n;i++){
            if(!used[i]){
                used[i] = true;
                col[step] = i;
                queen(step+1,col,used);
                used[i] = false;
            }
        }
    }else{
        if(check(col)){
            ans++;
        }
        return ;
    }
}

int main()
{
    cin >> n;
    vector<int> col(n+1);
    vector<bool> used(n+1,false);
    queen(1,col,used);
    cout << ans;
}
