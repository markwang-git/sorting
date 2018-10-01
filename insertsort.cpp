#include <iostream>
#include <cmath>
#include <cstdlib>

#define MAX   7   // size of the array

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

    // Insersion sort
    for (i = 1; i < size; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (A[j] > A[i])
            {
                tmp = A[i];
                for (k = i - 1; k >= j; k--)
                {
                    A[k + 1] = A[k];
                }
                A[j] = tmp;
                break;
            }
        }
        showlist(A, size);
    }

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

