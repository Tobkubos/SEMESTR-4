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
void ViewTable(vector<long long>& tab, int max)
{
    for (int i = 0; i < max; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

// Zamien miejscami w kopcu rekurencyjnie
void Heapify(vector<long long>& tab, int id)
{
    int largest = id;

    int leftChild = left(id);
    int rightChild = right(id);

    if (leftChild < tab.size() && tab[leftChild] >= tab[largest]) 
        largest = leftChild;

    if (rightChild < tab.size() && (tab[rightChild] >= tab[largest])) 
        largest = rightChild;

    if (largest != id)
    {
        swap(tab[id], tab[largest]);
        Heapify(tab, largest);
    }
}

int parent(int id)
{
    return (id - 1) / 2;
}

void heapAdd(vector<long long>& heap, int id) {
    while (id > 0 && ((heap[parent(id)] < heap[id])))
    {
        swap(heap[parent(id)], heap[(id)]);
        id = parent(id);
    }
}
//sort
void heapSort(vector<long long>& tab)
{
    vector<long long> heap; //kopiec

    for (int it = 0; it < tab.size(); it++)
    {
        heap.push_back(tab[it]);
        heapAdd(heap, heap.size() - 1);
    }

    ViewTable(heap, heap.size());

    //zmniejszaj kopiec zapisując wynik sortowania usuwając korzeń kopca
    int newArrayIt = tab.size() - 1;
    while (heap.size() > 0)
    {
        tab[newArrayIt] = heap[0];
        swap(heap[newArrayIt], heap[0]);
        heap.erase(heap.begin() + newArrayIt);
        Heapify(heap, 0);
        if (heap.size() > 1) ViewTable(heap, heap.size());
        newArrayIt--;
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