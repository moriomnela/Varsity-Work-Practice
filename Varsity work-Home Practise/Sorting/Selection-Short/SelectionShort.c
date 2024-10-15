#include <stdio.h>

int main() {
    // Write C code here
    int arr[] = {5,3,45,6,4,70,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int min_idx;
    for (int i= 0;i<size-1;i++){
        min_idx= i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }

         }
         int temp= arr[i];
         arr[i]=arr[min_idx];
         arr[min_idx]=temp;
    }

    for (int i = 0 ; i<size; i++){
        printf("%d ", arr[i]);
    }
}

