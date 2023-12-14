#include "SearchAnalysis.h"

/**
 * @brief Construct a new Search Analysis:: Search Analysis object
 * 
 * @param n 
 * @param exclusive_range 
 */
SearchAnalysis::SearchAnalysis():ArrayVec(){

}


/**
 * @brief Construct a new Search Analysis:: Search Analysis object
 *  and sorts v
 * 
 * @param n 
 * @param exclusive_range 
 */
SearchAnalysis::SearchAnalysis(int n, int exclusive_range):ArrayVec(){
    randGenVec(v,n,exclusive_range);
    sort(v.begin(),v.end());
}

/**
 * @brief returns the first index of elem if it exists, otherwise returns -1
 * iterativeSearch starts at the first index and iterates sequentially to the next until it either
 * finds the element or until it reaches the the end (i.e. element does not exist)
 * 
 * @param elem 
 * @return int 
 */
int SearchAnalysis::iterativeSearch(int elem){
    for(int i = 0; i < v.size(); i++){
        if (v[i] == elem){
            return i;
        }
    } 
    return -1;
}

/**
 * @brief returns the first index of an element if it exists and returns -1 
 * if it does not. binarySearch is recursive (i.e. function calls itself).
 * It utilizes the fact that v is in non-decreasing order (e.g. values go up,
 * but duplicates are allowed).
 * 
 * It calculates the mid from the start and end index. It compares v[mid] (i.e. value
 * at mid) with elem and decides whether to search the left half (lower values)
 * or right half (upper values).
 * 
 * 
 * @param start 
 * @param end 
 * @param elem 
 * @return int 
 */
int SearchAnalysis::binarySearch(int start, int end, int elem){
    if (start >= end){
     return -1;   
    }
    int mid = (start + end) / 2;

    if (v[mid] > elem){         // search left half
        end = mid - 1;   
    } else if (v[mid] < elem){  // search right half
        start = mid + 1;
    } else {                    // found elem
        while (mid == elem) {   // account for duplicates
            mid--;
        }
        return mid+1;
    }
    return binarySearch(start, end, elem);
}

/**
 * @brief returns the time (seconds) it takes to run iterativeSearch(if bool is True) and
 * binarySearch (if bool is False)
 * 
 * @param isIterative 
 * @param elem 
 * @return double 
 */
double SearchAnalysis::runTime(bool isIterative, int elem){ 
    if (isIterative == true) {
        clock_t start = clock();            // start time before running search
        int index = iterativeSearch(elem);
        clock_t end = clock();              // end time
        double elapsed_time_in_sec = (double(end) - double(start))/CLOCKS_PER_SEC;

        return elapsed_time_in_sec;
    } else {
        // binarySearch only works when the input is sorted or in order

        clock_t start = clock();        // start time before running search
        int index = binarySearch(0, v.size()-1, elem);
        clock_t end = clock();          // end time
        double elapsed_time_in_sec = (double(end) - double(start))/CLOCKS_PER_SEC;

        return elapsed_time_in_sec; 
    }
}

/**
 * @brief returns v
 * 
 * @return vector<int> 
 */
vector<int> SearchAnalysis::getV(){
    return v;
}


/**
 * @brief writes runtimes and array sizes to file
 * 
 * @param filename 
 * @param times 
 */
void SearchAnalysis::writeToFile(string filename, vector<double> times, int n[]) const{
    ofstream myFile(filename);

    myFile << "Number of Elements (n)\t Time (sec) " << endl;
    for(int i = 0; i < times.size(); i++){

        myFile << n[i] << "\t" << times[i] << "\n";
    }
    myFile.close();
}