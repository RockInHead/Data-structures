#include "DynamicArray.h"
#include <iostream>
#include <windows.h>
#include <stdexcept>
using namespace std;
//using namespace DYNAMIC_ARRAY_H;
//struct DynamicArray
//{
    // ���������� �������

    //����������� �������� �������
    int Capacity = 4;
    //���-�� ��������� � ������� �������
    int Length = 0;
    int* currentArray = new int[Capacity] {NULL, NULL, NULL, NULL};

    DynamicArray::DynamicArray() : Capacity(4), Length(0) {
        currentArray = new int[Capacity](); // ������������� ������� ������
    }
    // ������� ���������� �������
    void DynamicArray::ExpandArray()
    {
        if (Length == Capacity)
        {
            int* expandedArray = new int[Capacity * 2];

            for (int i = 0; i < Capacity * 2; i++)
            {
                expandedArray[i] = NULL;
            }
            for (int i = 0; i < Length; i++)
            {
                expandedArray[i] = currentArray[i];
            }
            Capacity *= 2;
            delete[] currentArray;
            currentArray = expandedArray;
        }
    }
    void DynamicArray::ReduceArray() {
        if (Length <= Capacity / 2 && Capacity != 4)
        {
            int* reducedArray = new int[Capacity / 2];

            for (int i = 0; i < Capacity / 2; i++)
            {
                reducedArray[i] = NULL;
            }
            for (int i = 0; i < Length; i++)
            {
                reducedArray[i] = currentArray[i];
            }
            Capacity /= 2;
            delete[] currentArray;
            currentArray = reducedArray;
        }
    }

    // ������� ���������� �������� � ����� �������
    void DynamicArray::AddElement(int array[], int newElement)
    {
        for (int i = 0; i < Capacity; i++)
        {
            if (array[i] == NULL)
            {
                //cout << "Enter a new element:";
                //cin >> array[i];
                array[i] = newElement;
                Length++;
                break;
                break;
            }
        }
    }
    // ������� ������� �������� �������
    void DynamicArray::AddElmentStart(int array[], int newElement)
    {
        /*int newElement;
        cout << "Enter a new element:";
        cin >> newElement;*/
        for (int i = Length + 1; i > 0; i--)
        {
            array[i] = array[i - 1];
        }
        array[0] = newElement;
        Length++;
    }
    // ������� ������� �������� �� �������
    void DynamicArray::Insert(int array[], int newElement, int indexOfElement)
    {

        Length++;
        //ExpandArray();
        for (int i = Length - 1; i > indexOfElement; i--)
        {

            array[i] = array[i - 1];
        }
        array[indexOfElement] = newElement;
    }
    // ������� �������� �������� �� �������
    void DynamicArray::DeleteElementIndex(int array[], int indexOfElement)
    {
        //int indexOfElement;
        //cout << "Enter the index of the item to delete:";
        //cin >> indexOfElement;
        array[indexOfElement] = NULL;
        for (int i = indexOfElement; i <= Length - 1; i++)
        {
            if (array[i] == array[Length - 1])
            {
                array[i] = NULL;
                break;
            }
            array[i] = array[i + 1];
        }
        Length--;
    }
    // ������� �������� �������� �� ��������
    void DynamicArray::DeleteElementValue(int array[], int DeletedElement)
    {
        /*int DeletedElement;*/
        int indexOfElement;
        /*cout << "Enter the item to delete:";
        cin >> DeletedElement;*/
        for (int i = 0; i < Capacity; i++)
        {
            if (array[i] == DeletedElement)
            {
                array[i] = NULL;
                indexOfElement = i;
                break;
            }
        }
        for (int i = indexOfElement; i <= Length - 1; i++)
        {
            if (array[i] == array[Length - 1])
            {
                array[i] = NULL;
                break;
            }
            array[i] = array[i + 1];

        }
        Length--;
    }
    // ������� ��������� ������ �������� � �������
    int DynamicArray::LinearSearch(int array[], int seacrhingElement)
    {
        /*int seacrhingElement;
        cout << "Enter seacrhing elemnt:";
        cin >> seacrhingElement;*/
        for (int i = 0; i < Length; i++)
        {
            if (array[i] == seacrhingElement)
            {
                /*cout << "Index of seacrhing element is ";
                cout << i << endl;*/
                return i;
                break;
            }
        }
    }
    void DynamicArray::Merge(int array[], int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // ������� ��������� �������
        int* L = new int[n1];
        int* R = new int[n2];

        // �������� ������ �� ��������� ������� L[] � R[]
        for (int i = 0; i < n1; i++)
            L[i] = array[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = array[mid + 1 + j];

        // ������� ��������� ������� ������� � array[left..right]
        int i = 0;    // ������ ������� ����������
        int j = 0;    // ������ ������� ����������
        int k = left; // ������ ���������� ����������

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                array[k] = L[i];
                i++;
            }
            else
            {
                array[k] = R[j];
                j++;
            }
            k++;
        }

        // �������� ���������� �������� L[], ���� ����
        while (i < n1)
        {
            array[k] = L[i];
            i++;
            k++;
        }

        // �������� ���������� �������� R[], ���� ����
        while (j < n2)
        {
            array[k] = R[j];
            j++;
            k++;
        }

        // ����������� ������
        delete[] L;
        delete[] R;
    }
    void DynamicArray::MergeSortHelper(int array[], int left, int right)
    {
        if (left < right)
        {
            // ������� �������� �������
            int mid = left + (right - left) / 2;

            // ���������� ��������� ��� ��������
            DynamicArray::MergeSortHelper(array, left, mid);
            DynamicArray::MergeSortHelper(array, mid + 1, right);

            // ������� ��������������� ��������
            DynamicArray::Merge(array, left, mid, right);
        }
    }
    void DynamicArray::MergeSort(int array[])
    {
        // ����� ��������������� ������� � �������� ���������
        DynamicArray::MergeSortHelper(array, 0, Length - 1);
    }

   
   


    // ������� ��������� ������
    int DynamicArray::BinarySearch(int array[], int target) {
        // ������� ����� �������
        //int* array = new int[Length];
        //for (int i = 0; i < Length; i++) {
        //    array[i] = originalArray[i];
        //}

        // ��������� ������
        DynamicArray::MergeSort(array);

        // ��������� �������� �����
        int left = 0;
        int right = Length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (array[mid] == target) {
                // ����������� ������
                return mid; // ���������� ������ ���������� ��������
            }
            if (array[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        // ����������� ������
        return -1; // ������� �� ������
    }

    

    //// ������� ���������� ������� �� �����������
    //void SortAscending(int array[])
    //{
    //    for (int i = 0; i < Capacity; i++)
    //    {
    //        for (int j = 0; j < Capacity - 1; j++)
    //        {
    //            // for(int j=1;j<)
    //            if (array[j] > array[j + 1])
    //            {
    //                int element = array[j];
    //                array[j] = array[j + 1];
    //                array[j + 1] = element;
    //            }
    //        }
    //    }
    //}
    //// ������� ���������� ������� �� ��������
    //void SortDescending(int array[])
    //{
    //    for (int i = 0; i < Capacity; i++)
    //    {
    //        for (int j = 0; j < Capacity - 1; j++)
    //        {
    //            // for(int j=1;j<)
    //            if (array[j] < array[j + 1])
    //            {
    //                int element = array[j];
    //                array[j] = array[j + 1];
    //                array[j + 1] = element;
    //            }
    //        }
    //    }
    //}
//};