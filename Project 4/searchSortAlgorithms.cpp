#ifndef SEARCHSORTALGORITHMS_CPP
#define SEARCHSORTALGORITHMS_CPP
using namespace std;

template <class elemType>
int seqSearch(const elemType list[], int length, const elemType& item)
{
	int loc = 0;
    bool found = false; 

	while (loc < length && !found)
	{
		cout << "cycle: " << loc << " ";
		if (list[loc] == item)
			found = true;
		else
			loc++;
	}
	cout << endl;
    if (found)
        return loc;
    else
        return -1;
} //end seqSearch


template <class elemType>
int binarySearch(const elemType list[], int length, const elemType& item)
{
    int first = 0;
    int last = length - 1;
	int mid = int();

    bool found = false;

    while (first <= last && !found)
    {
		mid = (first + last) / 2;
		//cout << "mid: " << mid << endl;

        if (list[mid] == item)
            found = true;
        else if (list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found)
        return mid;
    else 
        return -1;
} //end binarySearch

template <class elemType>
void bubbleSort(elemType list[], int length)
{
    for (int i = 1; i < length; i++)
    {
        for (int index = 0; index < length-i; index++)
        {
            if (list[index] > list[index + 1])
            {
				//swap them
                elemType temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
        }
    }
} //end bubbleSort

template <class elemType>
void selectionSort(elemType list[], int length)
{
    int minIndex = 0;
	
    for (int loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length-1);
		//cout << "minIndex :" << minIndex << " ";
        //swap(list, loc, minIndex);
		elemType temp = list[loc];
		list[loc] = list[minIndex];
		list[minIndex] = temp;
    }
} //end selectionSort

template <class elemType>
void swap(elemType list[], int first, int second)
{
    elemType temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
} //end swap

template <class elemType>
int minLocation(elemType list[], int first, int last)
{
    int minIndex = first;
	
	for (int loc = first + 1; loc <= last; loc++)
	{
		if (list[loc] < list[minIndex])
		{
			minIndex = loc;
		}
	}
    return minIndex;
} //end minLocation

template <class elemType>
void insertionSort(elemType list[], int length)
{
	for (int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
	{
		if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
		{
			elemType temp = list[firstOutOfOrder];
			int location = firstOutOfOrder;

			do
			{
				list[location] = list[location - 1];
				location--;
			} while (location > 0 && list[location - 1] > temp);

			list[location] = temp;
		}
	}
} //end insertionSort

void quickSort(int list[],int first, int last) 
{
    if (first < last)
    {
        int a = first;
        int b = last;
        int pivot = list[(a+b) / 2];
        int x = (a + b) / 2;
        int temp;
        while (a < b)
        {
            while (list[b]>pivot)
            {
                b--;
            }
            while (list[a] <= pivot && a <= b)
            {
                a++;
            }
            if (a < b)
            {
            temp = list[b]; // swapping left and right position elements
            list[b] = list[a];
            list[a] = temp;
            }
        }
        list[b] = pivot;
        quickSort(list, first, b - 1);
        quickSort(list, b + 1, last);
    }
}

void quickSortB(int list[],int first, int last) 
{
    int mid = (first + last) / 2;
    int pivot = (first + last + mid) / 3;
    int startIndex = first;
    if (first < last)
    {
        int temp1 = list[first];
        list[first] = list[pivot];
        list[pivot] = temp1;

        for (int i = first + 1; i<=last; i++)
        {
            if (list[i] <= list[first])
            {
                startIndex++;
                int temp2 = list[i];
                list[i] = list[startIndex];
                list[startIndex] = temp2;
            }
        }
        int temp3 = list[first];
        list[first] = list[startIndex];
        list[startIndex] = temp3;

        pivot = startIndex;
        quickSortB(list,first,pivot - 1);
        quickSortB(list,pivot + 1, last);
    }
}

void quickSortC(int list[],int first, int last) 
{
    if (first - last < 20)
    {
        insertionSort(list,sizeof(list));
    }
    if (first < last)
    {
        int a = first;
        int b = last;
        int pivot = list[(a+b) / 2];
        int x = (a + b) / 2;
        int temp;
        while (a < b)
        {
            while (list[b]>pivot)
            {
                b--;
            }
            while (list[a] <= pivot && a <= b)
            {
                a++;
            }
            if (a < b)
            {
            temp = list[b]; // swapping left and right position elements
            list[b] = list[a];
            list[a] = temp;
            }
        }
        list[b] = pivot;
        quickSort(list, first, b - 1);
        quickSort(list, b + 1, last);
    }
}
void quickSortD(int list[], int first, int last)
{
    int mid = (first + last)/2;
    int pivot = (first + last + mid) / 3;
    int startIndex = first;
    if (last - first < 20)
    {
        insertionSort(list,sizeof(list));
    }
    else if (first < last)
    {
        int temp1 = list[first];
        list[first] = list[pivot];
        list[pivot] = temp1;
        for (int i = first + 1; i <= last; i++)
        {
            if (list[i]<= list[first])
            {
                startIndex++;
                int temp2 = list[i];
                list[i] = list[startIndex];
                list[startIndex] = temp2;
            }
        }
        int temp3 = list[first];
        list[first] = list[startIndex];
        list[startIndex] = temp3;
        pivot = startIndex;

        quickSortD(list, first, pivot - 1);
        quickSortD(list, pivot + 1, last);
    }
}



#endif