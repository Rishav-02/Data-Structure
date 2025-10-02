// maximum and minimum element in an array using divide and conquer

#include <stdio.h>

// Function to find min and max
void findMinMax(int arr[], int low, int high, int *min, int *max)
{
    int mid, min1, max1, min2, max2;

    // If only one element
    if (low == high)
    {
        *min = *max = arr[low];
        return;
    }

    // If two elements
    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            *min = arr[low];
            *max = arr[high];
        }
        else
        {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    // More than two elements
    mid = (low + high) / 2;

    findMinMax(arr, low, mid, &min1, &max1);
    findMinMax(arr, mid + 1, high, &min2, &max2);

    // Combine results
    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min, max;
    findMinMax(arr, 0, n - 1, &min, &max);

    printf("Minimum element = %d\n", min);
    printf("Maximum element = %d\n", max);

    return 0;
}