#include <iostream>
using namespace std;

int main() {
    int n, arr[100], sum = 0;
    cout << "Enter n: "<< endl;
    cin >> n;
    cout << "Enter " << n - 1 << " elements in range only: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int total = (n * (n + 1) )/2 ;
    cout << " the answer is "<< total - sum<< endl;
    
    //b part 
    
    
    int num, ar[100];
    cout << "Enter num: "<< endl;
    cin >> num ;
    cout << "Enter " << num - 1 << " elements in sorted order in range also: ";
    for (int i = 0; i < num - 1; i++) {
        cin >> ar[i];
    }
    int low = 0, high = num - 2, ans = num;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (ar[mid] == mid + 1) {
            low = mid + 1;
        } else {
            ans = mid + 1;
            high = mid - 1;
        }
    }
    cout << " b part answer is "<< ans;
    return 0;
}
