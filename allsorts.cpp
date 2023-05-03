#include <iostream>
using namespace std;

class Sorting
{
public:
    // Constructor to initialize array
    int *arr, size;
    int create()
    {
        cout << "Size of the arr=";
        cin >> size;
        arr = new int[size];
        cout << "\nEnter arr elements:\n";

        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }

        cout << "\n Your arr is : ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        //return size;
    }

    // Method to print the array
    void print_arr()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Iterative insertion sort
    void iterative_insertion_sort()
    {
        for (int i = 1; i < size; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // Recursive insertion sort
    void recursive_insertion_sort(int n)
    {
        if (n <= 1)
        {
            return;
        }
        recursive_insertion_sort(n - 1);
        int last = arr[n - 1];
        int j = n - 2;
        while (j >= 0 && arr[j] > last)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = last;
    }

    // Iterative merge sort
    void iterative_merge_sort()
    {
        int curr_size;
        int left_start;

        for (curr_size = 1; curr_size <= size - 1; curr_size = 2 * curr_size)
        {
            for (left_start = 0; left_start < size - 1; left_start += 2 * curr_size)
            {
                int mid = min(left_start + curr_size - 1, size - 1);

                int right_end = min(left_start + 2 * curr_size - 1, size - 1);

                merge(left_start, mid, right_end);
            }
        }
    }

    // Recursive merge sort
    void recursive_merge_sort(int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;

            recursive_merge_sort(l, m);
            recursive_merge_sort(m + 1, r);

            merge(l, m, r);
        }
    }

    // Helper method for merge sort
    void merge(int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1], R[n2];

        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Iterative quick sort
    void iterative_quick_sort()
    {
        int stack[size];

        int top = -1;
        stack[++top] = 0;
        stack[++top] = size - 1;

        while (top >= 0)
        {
            int high = stack[top--];
            int low = stack[top--];

            int pivot = partition(low, high);

            if (pivot - 1 > low)
            {
                stack[++top] = low;
                stack[++top] = pivot - 1;
            }

            if (pivot + 1 < high)
            {
                stack[++top] = pivot + 1;
                stack[++top] = high;
            }
        }
    }

    // Recursive quick sort
    void recursive_quick_sort(int low, int high)
    {
        if (low < high)
        {
            int pivot = partition(low, high);

            recursive_quick_sort(low, pivot - 1);
            recursive_quick_sort(pivot + 1, high);
        }
    }

    // Helper method for quick sort
    int partition(int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);

        return (i + 1);
    }

    // Heap sort
    void heap_sort()
    {
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(size, i);

        for (int i = size - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);

            heapify(i, 0);
        }
    }

    // Helper method for heap sort
    void heapify(int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);

            heapify(n, largest);
        }
    }
};

int main()
{
    Sorting s; 
    s.create(); // Creating an object of Sorting class with array size of 6
    s.print_arr(); // Printing the array before sorting
    // Sorting using iterative insertion sort
    //s.iterative_insertion_sort();
    //s.print_arr();

    // Sorting using recursive insertion sort
    s.recursive_insertion_sort(s.size);
    s.print_arr();

    // Sorting using iterative merge sort
    s.iterative_merge_sort();
    s.print_arr();

    // Sorting using recursive merge sort
    s.recursive_merge_sort(0, s.size - 1);
    s.print_arr();

    // Sorting using iterative quick sort
    s.iterative_quick_sort();
    s.print_arr();

    // Sorting using recursive quick sort
    s.recursive_quick_sort(0, s.size - 1);
    s.print_arr();

    // Sorting using heap sort
    s.heap_sort();
    s.print_arr();

    return 0;
}