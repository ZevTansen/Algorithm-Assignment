#include<bits/stdc++.h>
using namespace std;

vector<int> generateData(int n) {
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    return arr;
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}


void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;        

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    cout << "Student Name: Md. Tansen Uddin\n";
    cout << "Student ID: C243012\n\n";

    srand(time(0)); 

    vector<int> sizes = {10, 100, 1000, 10000, 100000};

    for (int n : sizes) {
        cout << "Dataset size: " << n << endl;

        
        vector<int> original = generateData(n);

        
        vector<int> arrInsertion = original;
        auto startIns = chrono::high_resolution_clock::now();
        insertionSort(arrInsertion);
        auto endIns = chrono::high_resolution_clock::now();
        chrono::duration<double> durationIns = endIns - startIns; // seconds
        cout << "Insertion Sort Time: " << durationIns.count() << " seconds" << endl;

        
        vector<int> arrMerge = original;
        auto startMerge = chrono::high_resolution_clock::now();
        mergeSort(arrMerge, 0, arrMerge.size() - 1);
        auto endMerge = chrono::high_resolution_clock::now();
        chrono::duration<double> durationMerge = endMerge - startMerge; // seconds
        cout << "Merge Sort Time: " << durationMerge.count() << " seconds" << endl;

        
        vector<int> arrQuick = original;
        auto startQuick = chrono::high_resolution_clock::now();
        quickSort(arrQuick, 0, arrQuick.size() - 1);
        auto endQuick = chrono::high_resolution_clock::now();
        chrono::duration<double> durationQuick = endQuick - startQuick; // seconds
        cout << "Quick Sort Time: " << durationQuick.count() << " seconds" << endl;

        cout << "------------------------" << endl;
    }

    return 0;
}