#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

int r, c , min_d;
int dx[] = {-1, 0, 1, 0}; // left, up, right, down
int dy[] = {0, -1, 0, 1};
int ans = INT_MAX;
map<char, int> v;

struct Dice {
    char T, D, L, R, F, B;
};

Dice rollDice(Dice d, int dir) {
    Dice res = d;
    switch (dir) {
        case 0: // left
            res.T = d.R;
            res.D = d.L;
            res.L = d.T;
            res.R = d.D;
            break;
        case 1: // up
            res.T = d.F;
            res.D = d.B;
            res.F = d.D;
            res.B = d.T;
            break;
        case 2: // right
            res.T = d.L;
            res.D = d.R;
            res.L = d.D;
            res.R = d.T;
            break;
        case 3: // down
            res.T = d.B;
            res.D = d.F;
            res.F = d.T;
            res.B = d.D;
            break;
    }
    return res;
}

void recur(int sx, int sy, int nx, int ny, int temp, Dice d, vector<vector<bool>> &vst) {
    if (sx == nx && sy == ny) {
        ans = min(ans, temp);
        return;
    }

    // branch and bounding
    int num = abs(nx-sx) + abs(ny-sy);
    if(temp + (num*min_d) > ans){
        return;
    }

    for (int i = 0; i < 4; i++) {
        int new_x = sx + dx[i];
        int new_y = sy + dy[i];

        if (new_x >= 0 && new_x < c && new_y >= 0 && new_y < r && !vst[new_y][new_x]) {
            vst[new_y][new_x] = true;
            Dice nextDice = rollDice(d, i);
            recur(new_x, new_y, nx, ny, temp + v[nextDice.T], nextDice, vst);
            vst[new_y][new_x] = false;
        }
    }
}

int main() {
    int p, q, u, d_, l, r_, f, b;
    cin >> r >> c >> p >> q;

    cin >> u >> d_ >> l >> r_ >> f >> b;
    min_d = min({u,d_,l,r_,f,b});
    v['U'] = u;
    v['D'] = d_;
    v['L'] = l;
    v['R'] = r_;
    v['F'] = f;
    v['B'] = b;

    vector<vector<bool>> vst(r, vector<bool>(c, false));
    Dice di = {'U', 'D', 'L', 'R', 'F', 'B'};
    vst[0][0] = true;
    recur(0, 0, q, p, 0, di, vst);

    cout << max(-1,ans);
    return 0;
}
