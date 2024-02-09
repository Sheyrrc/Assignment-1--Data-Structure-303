#include <iostream>
using namespace std;

#define MAX_SIZE  100

void readFile(const char* filename, int arr[], int& size);
void writeFile(const char* filename, int arr[], int size);
int funcExist(int arr[], int size, int value);
int funcModify(int arr[], int size, int index, int newValue, int& oldValue);
int* funcAdd(int* arr, int& size, int newValue);
int* funcDel(int* arr, int& size, int index, int newValue);
