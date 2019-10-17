#include <iostream>
#include <vector>

int findMin(std::vector<int>& arr, int left)
{
    int min = INT_MAX;
    int idMin = -1;
    for (int i = left; i < arr.size(); i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            idMin = i;
        }
    }

    return idMin;
}

void selectionSort(std::vector<int>& arr, int index)
{
    if (index == arr.size())
        return;

    int minIndex = findMin(arr, index+1);

    int tmp = arr[index + 1];
    arr[index + 1] = arr[minIndex];
    arr[minIndex] = tmp;

    selectionSort(arr, index + 1);    
}

int main() {

    std::vector<int> nums;
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);

   // vector<int> sortedArray;
    selectionSort(nums, -1);

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout<<nums[i]<<std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}