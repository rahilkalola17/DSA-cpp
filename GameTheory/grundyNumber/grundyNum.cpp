#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<math.h>
using namespace std;

int mex(int a, int b, int c) {
    unordered_set<int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);

    for (int i{}; i<max(a, max(b,c)) + 2; i++) {
        if (s.count(i) == 0) return i;
    }
}

int grundy(int n) {
    if (n <= 0) return 0;
    return mex(grundy(n/6), grundy(n/2), grundy(n/3));
}

int main() {
    int n;
    cin >> n;
    cout << grundy(n) << endl;
}