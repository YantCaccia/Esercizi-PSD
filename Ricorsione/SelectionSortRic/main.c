#include <stdio.h>
#include "item.h"
#include "vettore.h"
#define nl printf("\n")

int main(int argc, char *argv[]) {
    Item arr[5];

    input_array_str(arr, argv[1]);

    // for(int i = 0; i < 5; i++) arr[i] = in_item();

    selection_sort_ric(arr, 5);

    output_array(arr, 5);

    return 0;
}