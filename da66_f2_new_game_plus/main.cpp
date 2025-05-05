#include <iostream>
#include <vector>

const int MOD = 100'000'007;

using namespace std;

int main() {
  vector<vector<int>> maze;
  vector<vector<vector<int>>> result;
  int R,C;
  cin >> R >> C;
  maze = vector<vector<int>>(R+2,vector<int>(C+2,0));
  result = vector<vector<vector<int>>>(R+2,vector<vector<int>>(C+2,vector<int>(3,0)));
  for (int i = 1;i <= R;i++) {
    for (int j = 1;j <= C;j++) {
      cin >> maze[i][j];
    }
  }

  //initial
  for (int i = 0; i <= R+1;i++) { maze[i][0] = 1; maze[i][C+1] = 1;}
  for (int i = 0; i <= C+1;i++) { maze[0][i] = 1; maze[R+1][i] = 1;}

  //col 2
  for (int r = 1;r <= R;r++) {
    if (maze[r][2] == 0) {
      result[r][2][0] = (maze[r+1][1] == 0 ? 1 : 0);
      result[r][2][1] = (maze[r  ][1] == 0 ? 1 : 0);
      result[r][2][2] = (maze[r-1][1] == 0 ? 1 : 0);
    } else {
      result[r][2] = {0,0,0};
    }
  }

  //dynamic programming
  for (int c = 3;c <= C;c++) {
    for (int r = 1;r <= R;r++) {
      if (maze[r][c] == 0) {
        result[r][c][0] = (result[r+1][c-1][1] + result[r+1][c-1][2]) % MOD;
        result[r][c][1] = (result[r  ][c-1][0] + result[r  ][c-1][2]) % MOD;
        result[r][c][2] = (result[r-1][c-1][1] + result[r-1][c-1][0]) % MOD;
      } else {
        result[r][c][0] = 0;
        result[r][c][1] = 0;
        result[r][c][2] = 0;
      }
    }
  }

  int ans = 0;
  for (int i = 1;i <= R;i++) {
    ans += result[i][C][0];
    ans %= MOD;
    ans += result[i][C][1];
    ans %= MOD;
    ans += result[i][C][2];
    ans %= MOD;
  }
  cout << ans << endl;
}




