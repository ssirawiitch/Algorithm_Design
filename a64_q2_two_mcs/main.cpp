#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n+1);

    for(int i = 1;i<=n;i++){
        cin >> v[i];
    }
    vector<int> max_left(n+1,0);  // find max sub array from index 1 to i
    vector<int> max_right(n+2,0); // find max sub array from index i+1 to n

    // Trivial case
    max_left[1] = v[1];
    max_right[n] = v[n];

    // max-left
    int suf = v[1];
    int mss = v[1];
    for(int i = 2;i<=n;i++){
        suf = max(v[i],suf + v[i]);
        mss = max(mss,suf);

        max_left[i] = mss;
    }

    // max-right
    int suf2 = v[n];
    int mss2 = v[n];
    for(int i = n-1;i>=1;i--){
        suf2 = max(v[i],suf2 + v[i]);
        mss2 = max(mss2,suf2);

        max_right[i] = mss2;
    }

    int result = max_left[n];
    for (int i = 1; i < n; i++) {
        result = max(result, max_left[i] + max_right[i + 1]);
    }

    cout << result << "\n";
    return 0;

}
