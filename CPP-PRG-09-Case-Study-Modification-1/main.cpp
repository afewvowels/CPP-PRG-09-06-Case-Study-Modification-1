//
//  main.cpp
//  CPP-PRG-09-Case-Study-Modification-1
//
//  Created by Keith Smith on 10/30/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Modify Program 9-19 (the United Cause case study program) so it can be used with
//  any set of donations. The program should dynamically allocate the donations array
//  and ask the user to input its values.

#include <iostream>

using namespace std;

void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);

int main()
{
    const int NUM_DONATIONS = 15;
    
    int donations[NUM_DONATIONS] = { 5, 100, 5, 25, 10,
                                     5, 25, 5, 5, 100,
                                     10, 15, 10, 5, 10 };
    
    int *arrPtr[NUM_DONATIONS] = { nullptr, nullptr, nullptr, nullptr, nullptr,
                                   nullptr, nullptr, nullptr, nullptr, nullptr,
                                   nullptr, nullptr, nullptr, nullptr, nullptr };
    
    for (int count = 0 ; count < NUM_DONATIONS ; count++)
    {
        arrPtr[count] = &donations[count];
    }
    
    arrSelectSort(arrPtr, NUM_DONATIONS);
    
    cout << "The donations, sorted in ascending order, are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS);
    
    cout << "The donations, in their original order, are: \n";
    showArray(donations, NUM_DONATIONS);
    
    return 0;
}

void arrSelectSort(int *arr[], int size)
{
    int startScan, minIndex;
    int *minElem;
    
    for (startScan = 0 ; startScan < (size - 1) ; startScan++)
    {
        minIndex = startScan;
        minElem = arr[startScan];
        for (int index = startScan + 1 ; index < size ; index++)
        {
            if(*(arr[index]) < *minElem)
            {
                minElem = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

void showArray(const int arr[], int size)
{
    for (int count = 0 ; count < size ; count++)
    {
        cout << arr[count] << " ";
    }
    cout << endl;
}

void showArrPtr(int *arr[], int size)
{
    for (int count = 0 ; count < size ; count++)
    {
        cout << *(arr[count]) << " ";
    }
    cout << endl;
}
