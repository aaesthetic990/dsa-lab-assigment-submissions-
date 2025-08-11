#include <stdio.h>

int main() {
    int n, left, right, temp;
    printf("Enter number of elements ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements ", n);
    for (left = 0; left < n; left++) {
        scanf("%d", &arr[left]);
    }


    left = 0;
    right = n - 1;


    while (left < right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }

    printf("Reversed array: is \n");
    for (left = 0; left < n; left++) {
        printf("%d ", arr[left]);
    }

    return 0;
}
