#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;

    while (start <= end) {
        if (arr[mid] == key){
            return mid;
        }

        if(key > arr[mid]) { // go to right part
            start = mid + 1;
        } else { // go to left part
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int main() {
    
    int even[6] = {2,4,6,8,12,18};
    int odd[5] = {3,8,11,14,16};

    cout << binarySearch(even, 6, 12);
    return 0;
};