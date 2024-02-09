#include "functions.h"
#include <iostream>
#include <fstream>

using namespace std;

void readFile(const char* filename, int arr[], int& size) {
    ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open()) {
        throw "File not found";
    }

    size =  0;
    int num;
    while (inFile >> num) {
        arr[size++] = num;
    }

    inFile.close();
}

void writeFile(const char* filename, int arr[], int size) {
    ofstream outFile;
    outFile.open(filename, ios::trunc);
    if (!outFile.is_open()) {
        throw "Failed to open file for writing";
    }

    for (int i =  0; i < size; ++i) {
        outFile << arr[i] << ' ';
    }

    outFile.close();
}

int funcExist(int arr[], int size, int value) {
    for (int i =  0; i < size; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int funcModify(int arr[], int size, int index, int newValue, int& oldValue) {
    if (index >=  0 && index < size) {
        oldValue = arr[index];
        arr[index] = newValue;
        return newValue;
    } else {
        throw "Index out of range";
    }
}

int* funcAdd(int* arr, int& size, int newValue) {
    if (size < MAX_SIZE) {
        arr[size++] = newValue;
        return arr;
    } else {
        int* newArr = new int[MAX_SIZE *  2];
        for (int i =  0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        newArr[size++] = newValue;
        delete[] arr;
        return newArr;
    }
}

int* funcDel(int* arr, int& size, int index, int newValue) {
    if (index >=  0 && index < size) {
        for (int i = index; i < size -  1; ++i) {
            arr[i] = arr[i +  1];
        }
        --size;
        return arr;
    } else {
        throw "Index out of range";
    }
}
