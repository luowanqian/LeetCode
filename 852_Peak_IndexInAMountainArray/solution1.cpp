#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binary_search(vector<int>& A, int left, int right) {
        int mid = left + (right - left) / 2;

        if (A[mid] < A[mid-1] && A[mid] > A[mid+1])
            return binary_search(A, left, mid);
        else if (A[mid] > A[mid-1] && A[mid] < A[mid+1])
            return binary_search(A, mid, right);
        else
            return mid;

    }

    int peakIndexInMountainArray(vector<int>& A) {
        if (A.size() < 3)
            return 0;

        return binary_search(A, 0, A.size()-1);
    }
};

int main()
{
    vector<int> A = {0, 2, 1, 0};
    Solution solu;
    int idx = solu.peakIndexInMountainArray(A);
    cout << idx << endl;

    return 0;
}
