#include <iostream>
using namespace std;

int main() {
    int m, n, t;
    cout << "Enter rows cols nonzeros for A: ";
    cin >> m >> n >> t;

    int A[1000][3];
    cout << "Enter triplets for A (row col value):" << endl;
    for (int x = 0; x < t; x++) {
        cin >> A[x][0] >> A[x][1] >> A[x][2];
    }

    // sort A
    for (int x = 0; x < t - 1; x++) {
        for (int y = x + 1; y < t; y++) {
            if (A[x][0] > A[y][0] || (A[x][0] == A[y][0] && A[x][1] > A[y][1])) {
                int r = A[x][0], c = A[x][1], v = A[x][2];
                A[x][0] = A[y][0]; A[x][1] = A[y][1]; A[x][2] = A[y][2];
                A[y][0] = r;        A[y][1] = c;        A[y][2] = v;
            }
        }
    }

    // a part
    int B[1000][3];
    int cnt[1005], pos[1005];
    for (int i = 0; i < 1005; i++) { cnt[i] = 0; }
    for (int i = 0; i < t; i++) { cnt[A[i][1]]++; }
    pos[0] = 0;
    for (int i = 1; i < n; i++) { pos[i] = pos[i - 1] + cnt[i - 1]; }
    for (int i = 0; i < t; i++) {
        int col = A[i][1], p = pos[col]++;
        B[p][0] = col;
        B[p][1] = A[i][0];
        B[p][2] = A[i][2];
    }
    cout << "Transpose of A:" << endl;
    for (int i = 0; i < t; i++) {
        cout << B[i][0] << " " << B[i][1] << " " << B[i][2] << endl;
    }

    // b part
    int t2;
    cout << "Enter nonzeros for D (same size as A): ";
    cin >> t2;
    int D[1000][3];
    cout << "Enter triplets for D (row col value):" << endl;
    for (int x = 0; x < t2; x++) {
        cin >> D[x][0] >> D[x][1] >> D[x][2];
    }

    for (int x = 0; x < t2 - 1; x++) {
        for (int y = x + 1; y < t2; y++) {
            if (D[x][0] > D[y][0] || (D[x][0] == D[y][0] && D[x][1] > D[y][1])) {
                int r = D[x][0], c = D[x][1], v = D[x][2];
                D[x][0] = D[y][0]; D[x][1] = D[y][1]; D[x][2] = D[y][2];
                D[y][0] = r;        D[y][1] = c;        D[y][2] = v;
            }
        }
    }

    int C[2000][3];
    int i = 0, j = 0, p = 0;
    while (i < t && j < t2) {
        if (A[i][0] < D[j][0] || (A[i][0] == D[j][0] && A[i][1] < D[j][1])) {
            C[p][0] = A[i][0]; C[p][1] = A[i][1]; C[p][2] = A[i][2]; p++; i++;
        } else if (D[j][0] < A[i][0] || (D[j][0] == A[i][0] && D[j][1] < A[i][1])) {
            C[p][0] = D[j][0]; C[p][1] = D[j][1]; C[p][2] = D[j][2]; p++; j++;
        } else {
            int sum = A[i][2] + D[j][2];
            if (sum != 0) { C[p][0] = A[i][0]; C[p][1] = A[i][1]; C[p][2] = sum; p++; }
            i++; j++;
        }
    }
    while (i < t) { C[p][0] = A[i][0]; C[p][1] = A[i][1]; C[p][2] = A[i][2]; p++; i++; }
    while (j < t2){ C[p][0] = D[j][0]; C[p][1] = D[j][1]; C[p][2] = D[j][2]; p++; j++; }

    cout << "Addition of A and D:" << endl;
    for (int x = 0; x < p; x++) {
        cout << C[x][0] << " " << C[x][1] << " " << C[x][2] << endl;
    }

    // c part
    int m2, n2, t3;
    cout << "Enter rows cols nonzeros for E: ";
    cin >> m2 >> n2 >> t3;
    int E[1000][3];
    cout << "Enter triplets for E (row col value):" << endl;
    for (int x = 0; x < t3; x++) {
        cin >> E[x][0] >> E[x][1] >> E[x][2];
    }

    int res[105][105];
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n2; c++) {
            res[r][c] = 0;
        }
    }

    for (int x = 0; x < t; x++) {
        for (int y = 0; y < t3; y++) {
            if (A[x][1] == E[y][0]) {
                res[A[x][0]][E[y][1]] += A[x][2] * E[y][2];
            }
        }
    }

    cout << "Multiplication A*E:" << endl;
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n2; c++) {
            if (res[r][c] != 0) {
                cout << r << " " << c << " " << res[r][c] << endl;
            }
        }
    }

    return 0;
}
