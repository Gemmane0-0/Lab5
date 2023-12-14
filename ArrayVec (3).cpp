#include "ArrayVec.h"

/**
 * @brief Default Constuctor
 *
 */
ArrayVec::ArrayVec()
{

}

/**
 * @brief modifies arr to contain up to n integers ranging
 * from 0 to exclusive_range (aka [0,exclusive_range))
 *
 * @param arr
 * @param n
 * @param exclusive_range
 */
void ArrayVec::randGenArr(int arr[], int n, int exclusive_range){
    for(int i = 0; i < n; i++){
        arr[i] = rand() % exclusive_range; 
    }
}

/**
 * @brief modifies v to contain up to n integers ranging
 * from 0 to exclusive_range (aka [0,exclusive_range))
 *
 * @param v
 * @param n
 * @param exclusive_range
 */
void ArrayVec::randGenVec(vector<int> & v, int n, int exclusive_range){
    for(int i = 0; i < n; i++){
        //v[i] = rand() % exclusive_range;
        v.push_back(rand() % exclusive_range);
    }
}
/**
 * @brief returns the size of the array, which is at most cap
 *
 * @param arr
 * @param cap (capacity)
 * @return int
 */
int ArrayVec::getSize(const int arr[], int cap){
    int size = 0;
    for(int i = 0; i < cap; i++){
        if (arr[i] == -1){
            break;
        }
        size++;
    }
    return size;
}
