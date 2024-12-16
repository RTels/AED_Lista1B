#include <iostream>

using namespace std;


int part(int arr[], int left, int right);
void quicksort(int arr[], int left, int right);
int differencek(int nums[], int n, int k);

int main() {

    int n, k;
    cin >> n >> k;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }


    cout << differencek(nums, n, k) << endl;
    return 0;
}


int part(int arr[], int left, int right) {
    int i = left - 1;
    int pivot = arr[right];

    for (int j = left; j < right; ++j) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pivot_index = part(arr, left, right);
        quicksort(arr, left, pivot_index - 1);
        quicksort(arr, pivot_index + 1, right);
    }
}

int differencek(int nums[], int n, int k) {

    quicksort(nums, 0, n - 1); //ordena

    int count = 0;
    int i = 0, j = 1;


    while (j < n) {
        int diff = nums[j] - nums[i];

        if (diff == k) {
            count++;
            i++;
            j++;
        } else if (diff < k) {
            j++;
        } else {
            i++;
        }
    }

    return count;
}
