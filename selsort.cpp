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
    int i, j;
    int min;
    int tmp;

    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i; j < size; j++)
            if (data[min] > data[j])
                min = j;
        if (i == min)
        {
            cout << "i = " << i << ": ";
            showlist(data, size);
            cout << "-------------------------------" << endl << endl;
            continue;
        }
        else
        {
            tmp = data[i];
            data[i] = data[min];
            data[min] = tmp;
        }

        cout << "i = " << i << ": ";
        showlist(data, size);
        cout << "-------------------------------" << endl << endl;
    }
} //select_sort();
