
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int value;
    int frequency;
} Element;

int compare(const void* a, const void* b) {
    Element* elem1 = (Element*)a;
    Element* elem2 = (Element*)b;

    if (elem1->frequency != elem2->frequency) {
        return elem2->frequency - elem1->frequency;
    } else {
        return elem1->value - elem2->value;
    }
}

int main() {
    int arr[] = {4, 5, 6, 5, 3, 6, 7, 8, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Element elements[n];

    for (int i = 0; i < n; i++) {
        elements[i].value = arr[i];
        elements[i].frequency = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] == elements[j].value) {
                elements[j].frequency++;
                break;
            }
        }
    }

    qsort(elements, n, sizeof(Element), compare);

    int sorted_arr[n];
    for (int i = 0; i < n; i++) {
        sorted_arr[i] = elements[i].value;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");

    return 0;
}
