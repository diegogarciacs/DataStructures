#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "searchSortAlgorithms.cpp"
#define SIZE 10000
using namespace std;

void print(int list[], int length);

int main() 
{
    int intList[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
	    intList[i] = rand() % 1000;
    }
    int intList2[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
	    intList2[i] = rand() % 1000;
    }
    int intList3[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
	    intList3[i] = rand() % 1000;
    }
    int intList4[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
	    intList4[i] = rand() % 1000;
    }
    auto start = chrono::high_resolution_clock::now();
    quickSort(intList,0,SIZE - 1); 
    auto end = chrono::high_resolution_clock::now();
    // print(intList,SIZE);
    std::chrono::duration<float> duration = end - start;
    cout << duration.count() << " second(s) taken " << endl;

    auto start2 = chrono::high_resolution_clock::now();
    quickSortB(intList2,0,SIZE - 1); 
    auto end2 = chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration2 = end2 - start2;
    // print(intList2, SIZE);
    cout << duration2.count() << " second(s) taken " << endl;

    auto start3 = chrono::high_resolution_clock::now();
    quickSortC(intList3,0,SIZE - 1); 
    auto end3 = chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration3 = end3 - start3;
    // print(intList3, SIZE);
    cout << duration3.count() << " second(s) taken " << endl;
    
    auto start4 = chrono::high_resolution_clock::now();
    quickSortC(intList4,0,SIZE - 1); 
    auto end4 = chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration4 = end4 - start4;
    // print(intList4, SIZE);
    cout << duration4.count() << " second(s) taken " << endl;

    return 0;
}

void print(int list[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << list[i] << " ";
	}
    cout << endl;
}