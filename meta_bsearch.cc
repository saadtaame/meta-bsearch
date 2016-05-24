
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int bsearch(vector<int> A, int k) {
    int n = (int)A.size();

    int lg = 0;
    while((1 << lg) < n)
        lg += 1;

    int pos = 0;
    for(int i = lg - 1; i >= 0; i--) {
        if(A[pos] == k)
            return pos;
        int new_pos = pos | (1 << i);
        if((new_pos < n) && (A[new_pos] <= k))
            pos = new_pos;
    }

    return ((A[pos] == k) ? pos : -1);
}

int main( void ) {

    vector<int> A = {-2, 10, 100, 250, 32315};
    cout << bsearch(A, -2) << endl;

    return 0;
}
