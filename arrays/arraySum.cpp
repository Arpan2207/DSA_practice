#include <iostream>
using namespace std;

int arraySum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        //sum = sum + arr[i];
        sum += arr[i];
    }
    return sum;
}

int main() {
    
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
     int num[100];

    for(int i = 0; i < size; i++) {
        cin >> num[i];
    }

    cout << "The sum of the array is: " << arraySum(num, size) << endl;
}
