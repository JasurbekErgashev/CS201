#include <iostream>
#include <vector>
 
using namespace std;
 
void print(string, vector<double>);
int bubbleSort(vector<double>);
int selectionSort(vector<double>);
int insertionSort(vector<double>);
 
vector<vector<double>> arr_per = {
{5,4,3,2,1},
{5,4,3,1,2},
{5,4,2,3,1},
{5,4,2,1,3},
{5,4,1,3,2},
{5,4,1,2,3},
{5,3,4,2,1},
{5,3,4,1,2},
{5,3,2,4,1},
{5,3,2,1,4},
{5,3,1,4,2},
{5,3,1,2,4},
{5,2,4,3,1},
{5,2,4,1,3},
{5,2,3,4,1},
{5,2,3,1,4},
{5,2,1,4,3},
{5,2,1,3,4},
{5,1,4,3,2},
{5,1,4,2,3},
{5,1,3,4,2},
{5,1,3,2,4},
{5,1,2,4,3},
{5,1,2,3,4},
{4,5,3,2,1},
{4,5,3,1,2},
{4,5,2,3,1},
{4,5,2,1,3},
{4,5,1,3,2},
{4,5,1,2,3},
{4,3,5,2,1},
{4,3,5,1,2},
{4,3,2,5,1},
{4,3,2,1,5},
{4,3,1,5,2},
{4,3,1,2,5},
{4,2,5,3,1},
{4,2,5,1,3},
{4,2,3,5,1},
{4,2,3,1,5},
{4,2,1,5,3},
{4,2,1,3,5},
{4,1,5,3,2},
{4,1,5,2,3},
{4,1,3,5,2},
{4,1,3,2,5},
{4,1,2,5,3},
{4,1,2,3,5},
{3,5,4,2,1},
{3,5,4,1,2},
{3,5,2,4,1},
{3,5,2,1,4},
{3,5,1,4,2},
{3,5,1,2,4},
{3,4,5,2,1},
{3,4,5,1,2},
{3,4,2,5,1},
{3,4,2,1,5},
{3,4,1,5,2},
{3,4,1,2,5},
{3,2,5,4,1},
{3,2,5,1,4},
{3,2,4,5,1},
{3,2,4,1,5},
{3,2,1,5,4},
{3,2,1,4,5},
{3,1,5,4,2},
{3,1,5,2,4},
{3,1,4,5,2},
{3,1,4,2,5},
{3,1,2,5,4},
{3,1,2,4,5},
{2,5,4,3,1},
{2,5,4,1,3},
{2,5,3,4,1},
{2,5,3,1,4},
{2,5,1,4,3},
{2,5,1,3,4},
{2,4,5,3,1},
{2,4,5,1,3},
{2,4,3,5,1},
{2,4,3,1,5},
{2,4,1,5,3},
{2,4,1,3,5},
{2,3,5,4,1},
{2,3,5,1,4},
{2,3,4,5,1},
{2,3,4,1,5},
{2,3,1,5,4},
{2,3,1,4,5},
{2,1,5,4,3},
{2,1,5,3,4},
{2,1,4,5,3},
{2,1,4,3,5},
{2,1,3,5,4},
{2,1,3,4,5},
{1,5,4,3,2},
{1,5,4,2,3},
{1,5,3,4,2},
{1,5,3,2,4},
{1,5,2,4,3},
{1,5,2,3,4},
{1,4,5,3,2},
{1,4,5,2,3},
{1,4,3,5,2},
{1,4,3,2,5},
{1,4,2,5,3},
{1,4,2,3,5},
{1,3,5,4,2},
{1,3,5,2,4},
{1,3,4,5,2},
{1,3,4,2,5},
{1,3,2,5,4},
{1,3,2,4,5},
{1,2,5,4,3},
{1,2,5,3,4},
{1,2,4,5,3},
{1,2,4,3,5},
{1,2,3,5,4},
{1,2,3,4,5}
};
 
vector<double> info(int arr[120]) {
    double best = arr[0];
    double worst = arr[0];
    double average = arr[0];
    for (int i = 1; i < 120; i++) {
        if (arr[i] > worst)
            worst = arr[i];
        if (arr[i] < best)
            best = arr[i];
        average += arr[i];
    }
    vector<double> ans;
    ans.push_back(best);
    ans.push_back(worst);
    ans.push_back(average/120);
    return ans;
}
 
int main()
{
    int Complexity_Bub[120] = {};
    int Complexity_Sel[120] = {};
    int Complexity_Ins[120] = {};
    for (int i = 0; i < 120; i++) {
        Complexity_Bub[i] = bubbleSort(arr_per[i]);
        Complexity_Sel[i] = selectionSort(arr_per[i]);
        Complexity_Ins[i] = insertionSort(arr_per[i]);
    }
    for (int i = 0; i < 120; i++) {
        cout << Complexity_Bub[i] << " " << Complexity_Sel[i] << " " << Complexity_Ins[i] << endl;
    }
    cout << "Info -> Bubble Sort: " << endl;
    vector<double> bubbleInfo = info(Complexity_Bub);
    cout << "Average: " << bubbleInfo[2] << " Worst: " << bubbleInfo[1] << " Best: " << bubbleInfo[0] << endl;
 
    cout << "Info -> Selection Sort: " << endl;
    vector<double> selectionInfo = info(Complexity_Sel);
    cout << "Average: " << selectionInfo[2] << " Worst: " << selectionInfo[1] << " Best: " << selectionInfo[0] << endl;
 
    cout << "Info -> Insertion Sort: " << endl;
    vector<double> insertionInfo = info(Complexity_Ins);
    cout << "Average: " << insertionInfo[2] << " Worst: " << insertionInfo[1] << " Best: " << insertionInfo[0] << endl;
    return 0;
 
    // According to the analysis,
    //                  Best Case   Average Case    Worst Case  
    //  Bubble Sort     O(N)        O(N^2)          O(N^2)      
    //  Selection Sort  O(N^2)      O(N^2)          O(N^2)    
    //  Insertion Sort  O(N)        O(N^2)          O(N^2)    
 
    // Average time complexity of all algorithms is 0(n^2) meaning that any of those 3 has complete advantage over others.
}
 
int bubbleSort(vector<double> nums)
{
    int comparisons = 0;
    int n = nums.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                comparisons++;
                swap(nums[i], nums[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
    print("Bubble sort: ", nums);
    return comparisons;
}
 
int selectionSort(vector<double> nums)
{
    int comparisons = 0;
    int n = nums.size();
    int min_idx;
    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (nums[j] < nums[min_idx]) {
                comparisons++;
                min_idx = j;
            }
        if (min_idx != i) {
            comparisons++;
            swap(nums[min_idx], nums[i]);
        }
    }
    print("Selection sort: ", nums);
    return comparisons;
}
 
int insertionSort(vector<double> nums)
{
    int comparisons = 0;
    int n = nums.size();
    double key;
    for (int i = 1; i < n; i++)
    {
        key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key)
        {
            comparisons++;
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
    print("Insertion Sort: ", nums);
    return comparisons;
}
 
void print(string info, vector<double> nums)
{
    cout << info;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}
