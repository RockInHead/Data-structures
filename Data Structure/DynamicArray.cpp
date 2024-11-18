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
    int _capacity ;
    //���-�� ��������� � ������� �������
    int _length ;
    //������ �����
    int _growthFactor;
    //������� ������
    int* _currentArray = new int[_capacity];

    //�������� ������� ����� �������
    int DynamicArray::GetLength() const {
        return _length;
    }

    //�������� ������� �������������� �������
    int DynamicArray::GetCapacity() const {
        return _capacity;
    }

    //�������� ������
    int* DynamicArray::GetArray() const {
        return _currentArray;
    }


    DynamicArray::DynamicArray() : _capacity(4), _length(0),_growthFactor(2) {
        _currentArray = new int[_capacity](); // ������������� ������� ������
    }

   /* DynamicArray::DynamicArray(int initCapacity, int growthFactor)
        : _length(0), _capacity(initCapacity), _growthFactor(growthFactor) {
        _currentArray = new int[_capacity];
    }*/

    /*void DynamicArray::Resize(int newCapacity) {
        int* newArray = new int[newCapacity];
        for (int i = 0; i < _length; i++) {
            newArray[i] = _currentArray[i];
        }
        delete[] _currentArray;
        _currentArray = newArray;
        _capacity = newCapacity;
    }*/

    // ������� ���������� �������
    void DynamicArray::ExpandArray()
    {
        if (_length == _capacity)
        {
            int* expandedArray = new int[_capacity * _growthFactor];

            for (int i = 0; i < _capacity * 2; i++)
            {
                expandedArray[i] = NULL;
            }
            for (int i = 0; i < _length; i++)
            {
                expandedArray[i] = _currentArray[i];
            }
            _capacity *= _growthFactor;
            delete[] _currentArray;
            _currentArray = expandedArray;
        }
    }
    // ������� ���������� �������
    void DynamicArray::ReduceArray() {
        if (_length <= _capacity / _growthFactor && _capacity != 4)
        {
            int* reducedArray = new int[_capacity / _growthFactor];

            for (int i = 0; i < _capacity / _growthFactor; i++)
            {
                reducedArray[i] = NULL;
            }
            for (int i = 0; i < _length; i++)
            {
                reducedArray[i] = _currentArray[i];
            }
            _capacity /= _growthFactor;
            delete[] _currentArray;
            _currentArray = reducedArray;
        }
    }

    // ������� ���������� �������� � ����� �������
    void DynamicArray::AddElement( int newElement)
    {
        
        ExpandArray();
        _currentArray[_length] = newElement;
        _length++;
        //for (int i = 0; i < _capacity; i++)
        //{
        //    if (_currentArray[i] == NULL)
        //    {
        //        //cout << "Enter a new element:";
        //        //cin >> array[i];
        //        _currentArray[i] = newElement;
        //        _length++;
        //        break;
        //        break;
        //    }
        //}
        ExpandArray();
    }
    // ������� ������� �������� �������
    void DynamicArray::AddElmentStart(int newElement)
    {
        /*int newElement;
        cout << "Enter a new element:";
        cin >> newElement;*/
        ExpandArray();
        for (int i = _length; i > 0; i--)
        {
            _currentArray[i] = _currentArray[i - 1];
        }
        _currentArray[0] = newElement;
        _length++;
        ExpandArray();
    }
    // ������� ������� �������� �� �������
    void DynamicArray::Insert( int newElement, int indexOfElement)
    {
        if (indexOfElement<=_length && indexOfElement >= 0) {
            ExpandArray();
            _length++;
            //ExpandArray();
            for (int i = _length - 1; i > indexOfElement; i--)
            {

                _currentArray[i] = _currentArray[i - 1];
            }
            _currentArray[indexOfElement] = newElement;
            ExpandArray();
        }

    }
    /*void DeleteELement(int indexOfElement) 
    {
        for
    }*/
    // ������� �������� �������� �� �������
    void DynamicArray::DeleteElementIndex( int indexOfElement)
    {
        //int indexOfElement;
        //cout << "Enter the index of the item to delete:";
        //cin >> indexOfElement;
        if (indexOfElement < _length && indexOfElement>=0) {
            _currentArray[indexOfElement] = NULL;

            for (int i = indexOfElement; i <= _length - 1; i++)
            {
                if (_currentArray[i] == _currentArray[_length - 1])
                {
                    _currentArray[i] = NULL;
                    break;
                }
                _currentArray[i] = _currentArray[i + 1];
            }
            _length--;
            ReduceArray();
        }
    }
    // ������� �������� �������� �� ��������
    void DynamicArray::DeleteElementValue( int DeletedElement)
    {
        /*int DeletedElement;*/
        int indexOfElement=-1;
        /*cout << "Enter the item to delete:";
        cin >> DeletedElement;*/
        for (int i = 0; i < _capacity; i++)
        {
            if (_currentArray[i] == DeletedElement)
            {
                _currentArray[i] = NULL;
                indexOfElement = i;
                break;
            }
        }
        if (indexOfElement !=-1) {
            for (int i = indexOfElement; i <= _length - 1; i++)
            {
                if (_currentArray[i] == _currentArray[_length - 1])
                {
                    _currentArray[i] = NULL;
                    break;
                }
                _currentArray[i] = _currentArray[i + 1];

            }
            _length--;
            ReduceArray();
        }
    }
    // ������� ��������� ������ �������� � �������
    int DynamicArray::LinearSearch( int seacrhingElement)
    {
        /*int seacrhingElement;
        cout << "Enter seacrhing elemnt:";
        cin >> seacrhingElement;*/
        for (int i = 0; i < _length; i++)
        {
            if (_currentArray[i] == seacrhingElement)
            {
                /*cout << "Index of seacrhing element is ";
                cout << i << endl;*/
                return i;
                break;
            }
        }
        return -1;
    }
    //������� ����������� ��������
    void DynamicArray::Merge( int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // ������� ��������� �������
        int* L = new int[n1];
        int* R = new int[n2];

        // �������� ������ �� ��������� ������� L[] � R[]
        for (int i = 0; i < n1; i++)
            L[i] = _currentArray[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = _currentArray[mid + 1 + j];

        // ������� ��������� ������� ������� � array[left..right]
        int i = 0;    // ������ ������� ����������
        int j = 0;    // ������ ������� ����������
        int k = left; // ������ ���������� ����������

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                _currentArray[k] = L[i];
                i++;
            }
            else
            {
                _currentArray[k] = R[j];
                j++;
            }
            k++;
        }

        // �������� ���������� �������� L[], ���� ����
        while (i < n1)
        {
            _currentArray[k] = L[i];
            i++;
            k++;
        }

        // �������� ���������� �������� R[], ���� ����
        while (j < n2)
        {
            _currentArray[k] = R[j];
            j++;
            k++;
        }

        // ����������� ������
        delete[] L;
        delete[] R;
    }
    //��������������� ������� ��� ���������� �������.
    void DynamicArray::MergeSortHelper( int left, int right)
    {
        if (left < right)
        {
            // ������� �������� �������
            int mid = left + (right - left) / 2;

            // ���������� ��������� ��� ��������
            DynamicArray::MergeSortHelper( left, mid);
            DynamicArray::MergeSortHelper( mid + 1, right);

            // ������� ��������������� ��������
            DynamicArray::Merge( left, mid, right);
        }
    }
    //���������� ������� � ������� MergeSort
    void DynamicArray::MergeSort()
    {
        // ����� ��������������� ������� � �������� ���������
        DynamicArray::MergeSortHelper( 0, _length - 1);
    }
    // ������� ��������� ������
    int DynamicArray::BinarySearch( int target) {
        // ������� ����� �������
        //int* array = new int[_length];
        //for (int i = 0; i < _length; i++) {
        //    array[i] = originalArray[i];
        //}

        // ��������� ������
        DynamicArray::MergeSort();

        // ��������� �������� �����
        int left = 0;
        int right = _length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (_currentArray[mid] == target) {
                // ����������� ������
                return mid; // ���������� ������ ���������� ��������
            }
            if (_currentArray[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        // ����������� ������
        return -1; // ������� �� ������
    }
