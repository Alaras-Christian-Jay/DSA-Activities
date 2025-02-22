#include <iostream>
#include <algorithm>

using namespace std;

int myArray[30];
int numElem = 0;
int maxElem = 20;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void traverseArray() {
    cout << "Showing elements in my array\n";
    for (int i = 0; i < numElem; i++) {
        cout << myArray[i] << " | ";
    }
    cout << "\n";
}

string insertAtTheEnd(int num) {
    if (numElem == maxElem) return "Array is full!";
    myArray[numElem++] = num;
    return "Element successfully inserted at the end!";
}

string insertAtTheBeginning(int num) {
    if (numElem == maxElem) return "Array is full!";
    for (int i = numElem; i > 0; i--) {
        myArray[i] = myArray[i - 1];
    }
    myArray[0] = num;
    numElem++;
    return "Element successfully inserted at the beginning!";
}

string insertAtGivenPosition(int num, int elementAfter) {
    if (numElem == maxElem) return "Array is full!";

    int position = binary_search(elementAfter, 0, numElem);
    /* for (int i = 0; i < numElem; i++) {
        if (myArray[i] == elementAfter) {
            position = i + 1;
            break;
        }
    } */
    if (position == -1) return "Element to insert after not found!";

    for (int i = numElem; i > position; i--) {
        myArray[i] = myArray[i - 1];
    }
    myArray[position] = num;
    numElem++;
    return "Element successfully inserted!";
}

void bubbleSort() {
    bool swapped;
    for (int i = 0; i < numElem - 1; i++) {
        swapped = false;
        for (int j = 0; j < numElem - i - 1; j++) {
            if (myArray[j] > myArray[j + 1]) {
                swap(myArray[j], myArray[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Optimization: Exit if no swaps occurred
    }
}

string insertAtSortedArray(int num) {
    if (numElem == maxElem) return "Array is full!";

    bubbleSort();
    int position = 0;
    for (int i = 0; i < numElem; i++) {
        if (num < myArray[i]) {
            position = i;
            break;
        }
    }
    for (int i = numElem; i > position; i--) {
        myArray[i] = myArray[i - 1];
    }
    myArray[position] = num;
    numElem++;
    return "Element successfully inserted into sorted array!";
}

string deleteFromTheEnd() {
    if (numElem > 0) {
        numElem--;
        return "Element successfully deleted from the end!";
    }
    return "Array is empty. Cannot delete.";
}

string deleteFromBeginning() {
    if (numElem > 0) {
        for (int i = 0; i < numElem - 1; i++) {
            myArray[i] = myArray[i + 1];
        }
        numElem--;
        return "Element successfully deleted from the beginning!";
    }
    return "Array is empty. Cannot delete.";
}

string deleteFromGivenElement(int element) {
    int position = binary_search( element, 0, numElem);
    /* for (int i = 0; i < numElem; i++) {
        if (myArray[i] == element) {
            position = i;
            break;
        }
    } */
    if (position == -1) return "Element not found!";

    for (int i = position; i < numElem - 1; i++) {
        myArray[i] = myArray[i + 1];
    }
    numElem--;
    return "Element successfully deleted!";
}

int binarySearch(int num, int lowest, int highest) {
    while (lowest <= highest) {
        int middle = lowest + (highest - lowest) / 2;
        if (myArray[middle] == num) {
            return middle;
        }
        if (myArray[middle] < num) {
            lowest = middle + 1;
        } else {
            highest = middle - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    //Example usage:
    myArray[0] = 3;
    myArray[1] = 7;
    myArray[2] = 9;
    myArray[3] = 19;
    myArray[4] = 20;
    myArray[5] = 37;
    myArray[6] = 128;
    myArray[7] = 256;
    numElem = 8;

    bubbleSort(); // Sort before binary search

    cout << "Binary search for 20: Index = " << binarySearch(20, 0, numElem - 1) << endl;
    cout << "Binary search for 38: Index = " << binarySearch(38, 0, numElem - 1) << endl;

    //Further testing (optional):
    cout << insertAtTheEnd(10) << endl;
    traverseArray();
    cout << deleteFromGivenElement(20) << endl;
    traverseArray();

    return 0;
}