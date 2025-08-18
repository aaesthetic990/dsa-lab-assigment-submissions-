#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter order of matrix: ";
    cin >> n;

    // a part
    int diag[100];
    cout << "Enter diagonal elements: ";
    for (int i = 0; i < n; i++) cin >> diag[i];
    cout << "Diagonal Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << diag[i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }

    // b part
    int tri[300];
    cout << "Enter tri-diagonal elements: ";
    for (int i = 0; i < 3 * n - 2; i++) cin >> tri[i];
    cout << "Tri-diagonal Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << tri[n - 1 + i] << " ";
            else if (i == j + 1) cout << tri[i - 1] << " ";
            else if (j == i + 1) cout << tri[2 * n - 1 + i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }

    // c part
    int lower[10000];
    cout << "Enter lower triangular elements: ";
    for (int i = 0; i < n * (n + 1) / 2; i++) cin >> lower[i];
    cout << "Lower Triangular Matrix:" << endl;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << lower[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }

    // d part
    int upper[10000];
    cout << "Enter upper triangular elements: ";
    for (int i = 0; i < n * (n + 1) / 2; i++) cin >> upper[i];
    cout << "Upper Triangular Matrix:" << endl;
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) cout << upper[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }

    // e part
    int sym[10000];
    cout << "Enter symmetric matrix elements (row-wise lower triangle including diagonal): ";
    for (int i = 0; i < n * (n + 1) / 2; i++) cin >> sym[i];
    cout << "Symmetric Matrix:" << endl;
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << sym[i * (i + 1) / 2 + j] << " ";
            else cout << sym[j * (j + 1) / 2 + i] << " ";
        }
        cout << endl;
    }

    return 0;
}
