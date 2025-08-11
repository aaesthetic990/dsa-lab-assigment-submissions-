
#include <stdio.h>

int main() {
    int number ;
    printf("Enter number of elements: ");
    scanf("%d", &number );

    int arr[number];
    printf("Enter %d elements: ", number );
    for (int i = 0; i < number; i++) {
        scanf("%d", &arr[i]);
    }

    
    for (int i = 0; i < number ; i++) {
        for (int j = i + 1; j < number; ) {
            if (arr[i] == arr[j]) {
                
                for (int k = j; k < number - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                number--; 
            } else {
                j++;
            }
        }
    }

    printf("Array after removing duplicates: ");
    for (i = 0; i < number; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
