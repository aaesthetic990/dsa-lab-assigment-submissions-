#include <stdio.h>

int main() {
    int arr[100];  
    int n = 0, choice, position, val, i;

    while (1) {
        printf(" MENU \n");
        printf("1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n");
        printf("Enter choice ");
        scanf("%d", &choice);

        if (choice == 1) { 
            printf("Enter number of elements: ");
            scanf("%d", &n);
            printf("Enter %d elements: ", n);
            for (i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
        }
        else if (choice == 2) { 
            printf("Array: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if (choice == 3) { 
            printf("Enter position (0 to %d): ", n);
            scanf("%d", &position);
            if (position < 0 || position > n) {
                printf("Invalid position!\n");
                continue;
            }
            printf("Enter value: ");
            scanf("%d", &val);
            for (i = n; i > position; i--) {
                arr[i] = arr[i - 1];
            }
            arr[position] = val;
            n++;
        }
        else if (choice == 4) { 
            printf("Enter position (0 to %d): ", n - 1);
            scanf("%d", &position);
            if (position < 0 || position >= n) {
                printf("Invalid position!\n");
                continue;
            }
            for (i = position; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
        }
        else if (choice == 5) { 
            printf("Enter value to search: ");
            scanf("%d", &val);
            for (i = 0; i < n; i++) {
                if (arr[i] == val) {
                    printf("Found at index %d\n", i);
                    break;
                }
            }
            if (i == n) {
                printf("Not found\n");
            }
        }
        else if (choice == 6) { 
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
