#include <iostream>
#include <vector>

using namespace std;

//lewe dziecko
int left(int i)
{
    return 2 * i + 1;
}

//prawe dziecko
int right(int i)
{
    return 2 * i + 2;
}

//pokaz tablice
void ViewTable(vector<long long> &tab, int max)
{
    for (int i = 0; i < max; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

// Zamien miejscami w kopcu rekurencyjnie
void Heapify(vector<long long> &tab, int i)
{
    bool leftInRange = false;
    bool rightInRange = false;

    int parent = tab[i];
    int leftChild = tab[left(i)];
    int rightChild = tab[right(i)];
    int largest_id = i;

    if (left(i) < tab.size())
    {
        leftInRange = true;
    }

    if (right(i) < tab.size())
    {
        rightInRange = true;
    }

    if (rightInRange == true)
    {
        if (leftChild >= rightChild)
        {
            largest_id = left(i);
        }

        else
        {
            largest_id = right(i);
        }
    }

    if (leftInRange == true && rightInRange == false)
    {
        if (parent < leftChild)
        {
            largest_id = left(i);
        }
    }

    if (leftInRange == false && rightInRange == false)
    {
        largest_id = i;
    }

    if (parent < tab[largest_id])
    {
        swap(tab[i], tab[largest_id]);
        Heapify(tab, largest_id);
    }
}

//sort
void heapSort(vector<long long> &tab)
{
    vector<long long> heap; //kopiec

    for (int i = 0; i < tab.size(); i++)
    {
        //budujemy kopiec
        heap.push_back(tab[i]);
    }

    //sortujemy od dołu
    for (int i = heap.size() - 1; i >= 0; i--)
    {
        Heapify(heap, i);
    }
    
    ViewTable(heap, heap.size());

    for (int i = heap.size() - 1; i >= 0; i--)
    {
        swap(heap[0], tab[i]);
        swap(heap[i], heap[0]);
        heap.erase(heap.begin() + i);
        for (int j = heap.size() - 1; j >= 0; j--)
        {
            Heapify(heap, i);
        }
        if (heap.size() > 1)
        {
            ViewTable(heap, heap.size());
        }
    }
    ViewTable(tab, tab.size());
}

int main()
{
    int Cases = 0;
    cin >> Cases;
    for (int i = 0; i < Cases; i++)
    {
        int VectorSize = 0;
        cin >> VectorSize;
        vector<long long> tab;
        for (int j = 0; j < VectorSize; j++)
        {
            int temp = 0;
            cin >> temp;
            tab.push_back(temp);
        }
        heapSort(tab);
        cout << endl;
    }

    return 0;
}
