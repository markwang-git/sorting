#include <iostream>
#include <cmath>
#include <cstdlib>

#define MAX   17   // size of the array

using namespace std;

void showlist(int array[], int total);

int A[MAX];

int main()
{
    int i, j, k;
    int size;
    int tmp;

    size = MAX;
    srand(time(NULL));
    for (i = 0; i < size; i++)
        A[i] = rand() % 100;

    showlist(A, size);

    // Insersion sort from back to front (reverse order)
    for (i = 1; i < size; i++)
    {
        tmp = A[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (tmp >= A[j])
            {
                A[j + 1] = tmp;
                break;
            }
            else
                A[j + 1] = A[j];
        }
        if (j == -1)
            A[0] = tmp;
    }

    cout << "Final: ";
    showlist(A, size);

    return 0;
} // main()

void showlist(int array[], int total)
{
    int i;

    for (i = 0; i < total; i++)
        cout << array[i] << " ";
    cout << endl;
    return;
} // showlist()

