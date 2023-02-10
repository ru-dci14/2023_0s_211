#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


const bool debugMode = false; 

void printArray(int size, int arr[])
{
    printf("[ "); 
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); 
    }
    printf("]\n");
}


// A translation from pseudocode to C code
// https://en.wikipedia.org/wiki/Quicksort
// Hoare's partition scheme
// Divides array into two partitions
int partition ( int size, int array[size])
{

    // Pivot value
    int pivot = array[ (size-1)/2 ]; // The value in the middle of the array


    // Left index
    int left = -1;

    // Right index
    int right = size;

    while (true) 
    {

        // Move the left index to the right at least once and while the element at
        // the left index is less than the pivot
        do left++; while (array[left] < pivot);

        // Move the right index to the left at least once and while the element at
        // the right index is greater than the pivot
        do right--; while (pivot < array[right]);

        // If the indices crossed, return
        if ( right<=left )
                return right; 

        // Swap the elements at the left and right indices
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;

    }
}



int quickselect(int size, int arr[], int kval)
{
    int p = partition(size, arr); 

    if(debugMode)
    {
        printf("p = %d\n", p);
        printf("Kth value: %d\n", kval);
        printf("size of array = %d\n", size);
        printArray(size, arr);
    }

    
    if(p == kval)
    {
        p = partition(size, arr); 
        
        if(p == kval)
            return arr[p];

    }

    if(p < kval)
    {
        return quickselect((size-p-1), &arr[p+1], (kval-p-1));
    }
    else
    {
        return quickselect(p+1, arr, kval);  
    }

}



int main(int argc, char* argv[])
{

    FILE* inputFile = fopen(argv[1], "r");
    if (!inputFile)
    {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    char buf[256];

    char* len_string = fgets(buf, 256, inputFile);
    int len = atoi(len_string);
    char* kth_string = fgets(buf, 256, inputFile);
    int kth = atoi(kth_string);
    fgets(buf, 256, inputFile);

    if(debugMode)
    {
        printf("Size of array: %d\n", len); 
        printf("Kth value: %d\n", kth);
    }

    int* array = calloc( len, sizeof(int) );

    for (int i=0; i<len; i++)    
    {
        char* int_string = fgets(buf, 256, inputFile);
        array[i] = atoi(int_string);
    }


    if(debugMode)
    {
        printf("Array before calling quickselect: ");
        printf("[ "); 
        for(int i = 0; i < len; i++)
        {
            printf("%d ", array[i]); 
        }
        printf("]\n\n");
    }
    

    printf("%d\n", quickselect( len, array, kth ));

    free(array);

    return EXIT_SUCCESS;

}
