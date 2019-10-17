#include <iostream>
#include <vector>

void partition(int left, int high, int pivot, std::vector<int>& arr)
{
    // std::cout<<"I've entered partition"<<std::endl;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     std::cout<<"partition array"<<arr[i]<<std::endl;
    // }
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

    // std::cout<<"here we go"<<std::endl;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     std::cout<<"partition array"<<arr[i]<<std::endl;
    // }
}

void QuickSort(std::vector<int>& arr, int low, int high)
{
    // std::cout<<"I've entered QuickSort"<<std::endl;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     std::cout<<"partition array"<<arr[i]<<std::endl;
    // }

    int pivot = high;
    partition(low, high, high, arr);

    QuickSort(arr, low, pivot - 1);

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     std::cout<<"first array"<<arr[i]<<std::endl;
    // }

    QuickSort(arr, pivot + 1, high);

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     std::cout<<"second array"<<arr[i]<<std::endl;
    // }
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