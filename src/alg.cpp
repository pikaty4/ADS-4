// Copyright 2021 NNTU-CS
int binarySearch(int arr[], int number, int a, int b) {
    if (a <= b) {
        int ser = (a + b) / 2;
        if (arr[ser] == number) {
            int i = 1;
            int c = 1;
            while (arr[ser - i] == number && ser - i >= 0) { i++; c++; }
            i = 1;
            while (arr[ser + i] == number) { i++; c++; }
            return c;
        }
        if (arr[ser] < number)
            return binarySearch(arr, ser + 1, b, number);
        if (arr[ser] > number)
            return binarySearch(arr, a, ser - 1, number);
        
    }
    return 0;
}

int countPairs1(int* arr, int value, int len) {
    int c = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int k = i + 1; k < len; k++) {
            if (*(arr + i) + *(arr + k) == value) {
                c++;
            }
        }
    }
    return c;
}

int countPairs2(int* arr, int value, int len) {
    int c = 0;
    int i = 0;
    int d = 0;
    int f = 0;
    while (i < len) {
        d = 1;
        while (d < len - 1) {
            f = *(arr + i) + *(arr + i + d);
            if (f > value) break;
            if (f == value) c++;
            d++;
        }
        i++;
    }
    return c;
}

int countPairs3(int* arr, int value, int len) {
    int i = 0;
    int c = 0;
    int s, s2;
    while (i < len) {
        if (*(arr + i) + *(arr + i + 1) > value) return c;
        s = binarySearch(arr + i + 1, 0, len - i - 2, value - *(arr+i));
        c += s;
        i++;
    }
    return c;
}
