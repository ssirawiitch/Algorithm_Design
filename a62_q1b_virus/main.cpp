#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void print_vector(vector<int> &v) {
    for (int x: v) cout << x << " ";
    cout << endl;
}

void reverse_vector(vector<int> &v) {
    vector<int> tmp(v.size());
    for (int i = 0; i < v.size(); i++) {
        tmp[i] = v[v.size()-1-i];
    }
    v = tmp;
}

bool is_DIVOC(vector<int> &v) {
    if (v.size() == 2) {
        return ((v[0] == 0) && (v[1] == 1));
    }
    int m = (v.size()-1)/2;
    int bi = 0;
    int ci = m+1;
    vector<int> a(v.size()/2);
    vector<int> b(v.size()/2);
    for (int i = 0; i <= v.size()/2; i++) {
        a[i] = v[bi++];
        b[i] = v[ci++];
    }
    bool A = is_DIVOC(a) && is_DIVOC(b);
    reverse_vector(a);
    bool B = is_DIVOC(a) && is_DIVOC(b);

    return (A || B);
}


int main(int argc, const char * argv[]) {
    int n,k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < int(pow(2, k)); j++) {
            int x; cin >> x; v.push_back(x);
        }
        if (is_DIVOC(v)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}

