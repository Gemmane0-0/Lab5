#ifndef ARRAYVEC
#define ARRAYVEC

#include <vector>
#include <cstdlib>
using namespace std;

class ArrayVec {
    public:
        ArrayVec();
        void randGenArr(int arr[], int n, int exclusive_range);
        void randGenVec(vector<int> & v, int n, int exlcusive_range);
        int getSize(const int arr[], int cap);
    private:
};
#endif
