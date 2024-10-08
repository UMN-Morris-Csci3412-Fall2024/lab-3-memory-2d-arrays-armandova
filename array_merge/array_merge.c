#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>

int* array_merge(int arrays, int* sizes, int** values) {
    int i = 0;
    int total_elem = 0;
    while (i < arrays) {
        total_elem += sizes[i];
        i++;
    }
    if (total_elem == 0) {
        int *zero_arr = (int *)malloc(sizeof(int));
        if (zero_arr == NULL) {
            return NULL; 
        }
        zero_arr[0] = 0;
        return zero_arr;
    }
    int *merged_arr = (int *)malloc(total_elem * sizeof(int));
    if (merged_arr == NULL) {
        return NULL; 
    }
    

    i = 0;
    int pos = 0;
    while (i < arrays) {
        int j = 0;
        while (j < sizes[i]) {
            merged_arr[pos] = values[i][j];
            pos++;
            j++;
        }
        i++;
    }

    mergesort(total_elem, merged_arr);
    int unique_pos = 1; 
    int cur_pos = 1;
    while (cur_pos < total_elem) {
        if (merged_arr[cur_pos] != merged_arr[cur_pos - 1]) {
            merged_arr[unique_pos] = merged_arr[cur_pos];
            unique_pos++;
        }
        cur_pos++;
    }

    int *result_arr = (int *)malloc((unique_pos + 1) * sizeof(int));
    if (result_arr == NULL) {
        free(merged_arr);
        return NULL;
    }

    result_arr[0] = unique_pos;
    i = 0;
    while (i < unique_pos) {
        result_arr[i + 1] = merged_arr[i];
        i++;
    }
    free(merged_arr);
    return result_arr;
}
