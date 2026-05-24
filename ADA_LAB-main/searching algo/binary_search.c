#include <stdio.h>

int main() {
    int arr[] = {1,3,5,7,9};
    int n = 5, key = 7;
    int l = 0, r = n-1, mid, pos = -1;

    while(l <= r){
        mid = (l + r) / 2;

        if(arr[mid] == key){
            pos = mid;
            break;
        }
        else if(arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }

    if(pos != -1)
        printf("Found at index %d", pos);
    else
        printf("Not Found");

    return 0;
}
