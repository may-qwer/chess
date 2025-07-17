#include "func.h"

bool is_in_arr(const char sim, const char* arr) {
    int i = 0;
    while(arr[i] != 0) {
        if (sim == arr[i]) {
            return true;
        }
        i++;
    }
    return false;
}

bool is_in_arr(const int num, const int* arr, const int len_of_arr) {
    for (int i = 0; i < len_of_arr; i++)  {
        if (num == arr[i]) {
            return true;
        }
    }
    return false;
}

int get_len_of_arr(const char* str) {
    int len = 0;
    while (str[len] != 0) {
        len++;
    }
    return len;
}
