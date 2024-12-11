#include"HashTable.h"
#include <iostream>


using namespace std;
Node** HashTable::GetHashTable() {
    Node** temp = _table;
    return temp;
}

int HashTable::GetSize() {
    return _size;
}

int  HashTable::GetCapacity() {
    return _capacity;
}


HashTable::HashTable() :_capacity(5), _size(0) {
    _table = new Node*[_capacity]();
    for (int i = 0; i < _capacity; i++)
    {
        _table[i] = nullptr;
    }
}

bool HashTable::CompareKeys(Node* nodeFirst, Node* nodeSecond) {
    if (nodeFirst->Key == nodeSecond->Key) {
        nodeFirst->Value = nodeSecond->Value;
        return true;
    }
    return false;
}

void HashTable::Put(string key, int data) {
    int index = PearsonHash(key);
    Node* newNode = new Node(key, data);

    if (_table[index] == nullptr)
    {
        _table[index] = newNode;
    }
    else
    {
        Node* current = _table[index];

        if (CompareKeys(current, newNode)) {
            return;
        }
        while (current->Next != nullptr)
        {
            current = current->Next;

            if (CompareKeys(current->Prev,newNode)||CompareKeys(current, newNode)) {
                return;
            }
        }
        current->Next = newNode;
        newNode->Prev = current;
    }
    _size++;
}

void HashTable::DeleteElement(string key) {
    if (_size!=0)
    {
        int count=1;
        int index = PearsonHash(key);
        Node* temp = _table[index];
        if (temp != nullptr) {
            Node* head = _table[index];
            head->Prev = nullptr;
            Node* prev = new Node();
            while (temp->Key != key) {
                prev = temp;
                temp = temp->Next;
                count++;
            }
            if (temp->Prev == nullptr && temp->Next == nullptr) {
                head = nullptr;
                /*temp = nullptr;*/
            }
            else if (temp->Next == nullptr) {
                temp->Prev->Next = nullptr;
                /*temp = nullptr;*/
            }
            else if (temp->Prev == nullptr && temp->Next != nullptr) {
                temp = head;
                head = temp->Next;
                /*temp = nullptr;*/
            }
            else if (temp->Next != nullptr) {
                temp->Next->Prev = temp->Prev;
                /*head = temp->Prev;*/
                /*temp = nullptr;*/
            }
            if (temp->Prev != nullptr) {
                temp->Prev->Next = temp->Next;
            }
            temp = nullptr;

            _table[index] = head;
            _size--;
        }
    }
}

int HashTable::Hash(string key)
{
    int hashValue = 0;
    for (char c : key)
    {
        hashValue += static_cast<int>(c);
    }
    return hashValue % 5;
}
unsigned int HashTable::PearsonHash(string key)
{
     static const unsigned char table[256] =
     { 219, 453, 67, 812, 314, 945, 276, 598, 487, 382, 10, 215, 759, 145, 932, 688,
        341, 83, 729, 614, 965, 192, 240, 24, 854, 905, 174, 638, 502, 301, 444, 990,
        72, 103, 258, 412, 819, 207, 36, 555, 473, 330, 100, 800, 630, 789, 962, 14,
        477, 531, 24, 236, 712, 680, 1000, 483, 420, 642, 116, 357, 837, 419, 801,
        96, 125, 659, 5, 435, 215, 668, 746, 238, 120, 948, 811, 413, 475, 827, 146,
        136, 654, 816, 23, 223, 893, 37, 328, 130, 487, 378, 612, 988, 310, 165, 980,
        147, 559, 172, 313, 711, 571, 399, 733, 92, 389, 311, 50, 689, 304, 250, 461,
        776, 216, 647, 278, 830, 908, 76, 574, 897, 23, 370, 294, 815, 893, 639, 295,
        17, 59, 489, 372, 322, 763, 968, 505, 195, 743, 213, 820, 81, 38, 105, 628,
        471, 280, 466, 634, 902, 289, 842, 624, 118, 471, 567, 666, 90, 918, 929, 636,
        325, 14, 461, 269, 616, 154, 879, 538, 979, 185, 292, 440, 936, 97, 201, 837,
        761, 566, 3, 453, 196, 393, 341, 794, 207, 536, 174, 991, 825, 957, 121, 208,
        892, 756, 1, 852, 12, 774, 342, 412
         };

     unsigned int hash = 0;
     for (char c : key)
     {
         hash = table[hash ^ static_cast<unsigned char>(c)] % _capacity;
     }
     return hash;
 }

int HashTable::SearchingValue(string key)
{
    int index = PearsonHash(key);
    Node* current = _table[index];

    while (current != nullptr)
    {
        if (current->Key == key)
        {
            return current->Value;
        }
        current = current->Next;
    }

    return -1; // ���������� -1, ���� �������� �� �������
}