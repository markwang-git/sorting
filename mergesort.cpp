#include <iostream>
#include <cmath>
#include <cstdlib>

#define MAX   8   // size of the array

using namespace std;

void showlist(int array[], int total);
void mrg_sort(int data[], int size);
void mrg_pass(int to[], int from[], int size, int len);
void merge(int to[], int from[], int low, int mid, int high);

int A[MAX];

int main()
{
    int i;
    int size;

    size = MAX;
    srand(time(NULL));
    for (i = 0; i < size; i++)
        A[i] = rand() % 100;

    showlist(A, size);

    mrg_sort(A, size);
    showlist(A, size);

    return 0;
} // main()

void mrg_sort(int data[], int size)
{
    int tmp[2048];
    int len = 1;

    while( len < size )
    {
        cout << "mrg_pass 1" << endl;
        mrg_pass(tmp, data, size, len);
        len *= 2;
        cout << "mrg_pass 2" << endl;
        mrg_pass(data, tmp, size, len);
        len *= 2;
    }
} // mrg_sort()

void mrg_pass(int to[], int from[], int size, int len)
{
    int low = 0;

    while (low <= size - 2 * len)
    {
        merge(to, from, low, low + len - 1, low + 2 * len - 1);
        cout << "low = " << low << endl;
        cout << "from = ";
        showlist(from, size);
        cout << "to   = ";
        showlist(to, size);
        low += 2 * len;
        cout << "-----------" << endl;
    } // while()

    cout << "low = " << low << " len = " << len << endl;
    if (low + len - 1 < size)
    {
        merge(to, from, low, low + len - 1, size);
    }
    else
    {
        while (low < size)
        {
            to[low] = from[low];
            low++;
        }
    }
    cout << "end of mrg_pass" << endl;
    cout << "to   = ";
    showlist(to, size);
} // mrg_pass()

void merge(int to[], int from[], int low, int mid, int high)
{
    int ilow, ihigh, ito;

    ilow = ito = low;
    ihigh = mid + 1;

    while (ilow <= mid && ihigh <= high)
    {
        if(from[ilow] < from[ihigh])
        {
            to[ito] = from[ilow];
            ilow++ ;
        }
        else
        {
            to[ito] = from[ihigh];
            ihigh++;
        }
        ito++;
    }

    while (ilow <= mid)
        to[ito++] = from[ilow++];

    while (ihigh <= high)
        to[ito++] = from[ihigh++];
} // merge()

void showlist(int array[], int total)
{
    int i;

    for (i = 0; i < total; i++)
        cout << array[i] << " ";
    cout << endl;
    return;
}

