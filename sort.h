#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

class Sort{
    // always sorts ascending
private:
    void bubbleSort();
    void selectionSort();
    void mergeSort();
    void mergesort(int st,int ed,int *temp);
    void merge(int st,int mid,int ed,int *temp);
    void quickSort();
    int quicksort(int st,int ed);
    void conquer(int st,int ed);
    void radixSort();
    int *num;
    int n;
    // You may add other stuff here
    // Size of data in unknown in compile time

public:
    Sort(string filename,int n);
    ~Sort();
    void method(int n);
    void printdt(string filename);
    // You may need other stuff here
    // What about a constructor?
    // What about a sort function calling other sort algorithms?
    // If you have dynamic data, don't forget destructor
};