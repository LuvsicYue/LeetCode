#include "Solution.hpp"
#include <iostream>

template<typename T>
static void printVector(bool isInput, const vector<T>& v);

int main() {

    cout << "------------------Start Computation--------------------\n" << endl;
    Solution sol;
    printVector(false, sol.countBits(5));

    cout << "\n------------------Finish Computation-------------------" << endl;

    return 0;

}
















template<typename T>
void printVector(bool isInput, const vector<T>& v) {
    size_t length = v.size();
    if (isInput)
        cout << "Input: [";
    else
        cout << "Output: [";
    for (int i = 0; i < length; ++i) {
        cout << v[i];
        if (i != length - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}