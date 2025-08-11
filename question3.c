#include <stdio.h>

int main() {
    int i;
    int arr[5] = {1}; 
    for (i = 0; i < 5; i++) {
        printf("%d", arr[i]);
    }
    
    // i am expecting output to be 10000 as we are only initialising first index number and the rest are automatically set to 0.
  //so output according to  me is 10000
    return 0;
}
