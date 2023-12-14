#ifndef SEARCHANALYSIS
#define SEARCHANALYSIS

#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
#include "ArrayVec.h"

using namespace std;

class SearchAnalysis: ArrayVec {
    public:
        SearchAnalysis();
        SearchAnalysis(int n, int exclusive_range);
        int iterativeSearch(int elem);
        int binarySearch(int start, int end, int elem);
        double runTime(bool isIterative, int elem);
        vector<int> getV();
        void writeToFile(string filename, vector<double> times, int n[])const;
    private:
        vector<int>v;
};
#endif
