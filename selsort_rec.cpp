// select sort, recursive version
#include <iostream>
#include <ctime>
#include <cstdlib>

#define MAX 17
void showlist(int data[], int total);
void select_sort(int data[], int size);

int A[MAX];

using namespace std;

int main()
{
    int i, size;

    srand(time(NULL));
    size = MAX;
    for (i = 0; i < size; i++)
        A[i] = rand() % 100;

    cout << "This list:" << endl;
    showlist(A, size);

    select_sort(A, size);
    cout << "The sorted list:" << endl;
    showlist(A, size);

    return 0;
} // main()

void showlist(int data[], int total)
{
    int i;

    for (i = 0; i < total; i++)
        cout << data[i] << " ";

    cout << endl;
} //showlist()

void select_sort(int data[], int size)
{
    int j;
    int min;
    int tmp;

    if (size == 1)
        return;

    min = 0;
    for (j = 1; j < size; j++)
        if (data[min] > data[j])
            min = j;
    if (min)
    {
        tmp = data[0];
        data[0] = data[min];
        data[min] = tmp;
    }

    select_sort(data + 1, size - 1);
} //select_sort();
