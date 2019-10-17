# algorithms
Solving algorithm design questions
Quick Sort

{

#include <iostream>
#include <vector>

void partition(int left, int high, int pivot, std::vector<int>& arr)
{
    int count = 0;
    int tmp = 0;
    while(left < high)
    {
        if (arr[left] < arr[pivot])
        {
            tmp = arr[count];
            arr[count] = arr[left];
            arr[left] = tmp; 

            count++;          
        }

        left++;
    }

    tmp = arr[count];
    if(arr[count] < arr[high])
    {
        tmp = arr[count];
        arr[count] = arr[high];
        arr[high] = tmp;
    }
}

void QuickSort(std::vector<int>& arr, int low, int high)
{
    int pivot = high;
    partition(low, high, high, arr);

    QuickSort(arr, low, pivot - 1);

    QuickSort(arr, pivot + 1, high);
}

int main() {

    std::vector<int> nums;
    nums.push_back(50);
    nums.push_back(23);
    nums.push_back(9);
    nums.push_back(18);
    nums.push_back(61);
    nums.push_back(32);

    QuickSort(nums, 0 , nums.size() - 1);

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout<<nums[i]<<std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

}

