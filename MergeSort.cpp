#include <iostream>
using namespace std;

void printArr(int *arr, int size) {
    cout << endl;
    cout << "Array:\n| "; 
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " | ";
    }
    cout << endl;
    cout << endl;
}

void merge (int *arr, int s, int e) {

    int mid = s + (e-s)/2; // to avoid INT_MAX

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrIndex = s;

    for(int i = 0; i < len1; i++) {
        first[i] = arr[mainArrIndex++];
    }

    mainArrIndex = mid + 1;

    for(int i = 0; i < len2; i++) {
        second[i] = arr[mainArrIndex++];
    }

    //merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;

    mainArrIndex = s;

    while(index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]){
            arr[mainArrIndex++] = first[index1++];
        }else{
            arr[mainArrIndex++] = second[index2++];
        }
    }

    while(index1 < len1) {
        arr[mainArrIndex++] = first[index1++];
    }

    while(index2 < len2) {
        arr[mainArrIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int *arr, int s, int e) {

    //base case
    if (s >= e) {
        return;
    }

    int mid = s + (e-s)/2; // to avoid INT_MAX

    //sort left part
    mergeSort(arr, s, mid);

    //sort right part
    mergeSort(arr, mid+1, e);

    //merge both left and right part.
    merge(arr, s, e);
}

int main()
{
    int arr[12] = {5465,4654,545,87,421,12,58,36,725,751,896,474};
    int size = 12;

    mergeSort(arr, 0, size-1);

    printArr(arr, size);

    return 0;
    
}
