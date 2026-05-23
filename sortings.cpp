#include <iostream>
#include <vector>

using namespace std;

void bubblesort(vector<int>& array) {
    int n = array.size();
    bool swapped;

    for (int i = 0; i<n-1; i++) {
        swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j+1]);
                swapped = true;
            }
        }

        if(!swapped) {
            break;
        }
    }
}
