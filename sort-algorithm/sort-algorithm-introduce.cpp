#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

template <class T>
class Solution {
    public:
    /*
    冒泡排序算法： 一次比较两个元素， 如果它们的顺序错误则交换这两个元素，本质上是将当前排序的过程中
    大的元素移动到数组的最后面
    */
    typename std::vector<T> BubbleSort(const typename std::vector<T> &_VecList) {
        std::vector<T> res(_VecList.begin(), _VecList.end());
        if (_VecList.size() < 1) return res;
        for (int i = 0; i < _VecList.size(); i++) {
            for (int j = 1; j < _VecList.size() - i; j++) {
                if (res[j] < res[j - 1]) std::swap(res[j], res[j - 1]); 
            }
        } 
        return res;
    }

    /*
    选择排序算法： 在剩下的数组里面，寻找最小的元素，和头一个元素进行交换，将最小的元素放在开始
    整个程序都是比较，只有关键位置的交换，但是复杂度上面没有下降，因为不论原本是不是已经排好序的
    数组，数据都需要经过固定次数的比较  
    */
    typename std::vector<T> SelectionSort(typename std::vector<T> &_VecList) {
        std::vector<T> res(_VecList.begin(),  _VecList.end());
        if (_VecList.size() < 1) return res;
        for (int i = 0; i < res.size(); i++) {
            int minIndex = i;
            for (int j = i + 1; j < res.size(); j++) {
                if (res[j] < res[minIndex]) minIndex = j;
            }
            std::swap<T>(res[i], res[minIndex]);
        }
        return res;
    }

    /*
    对于每次新加入的元素，在已经排序的数组中，找到这个元素的合适的位置，插入这个元素
    时间主要消耗在找到这个元素的过程中，数据逐渐向后移动一位的过程中
    */
    std::vector<T> InsertionSort(const std::vector<T> &_VecList) {
        std::vector<int> res(_VecList.begin(), _VecList.end());
        for (int i = 0; i < res.size() - 1; i++) {
            int val =  res[i + 1];
            int preIndex = i;
            while (preIndex >= 0 && val < res[preIndex]) {
                res[preIndex + 1] = res[preIndex];
                preIndex--;
            }
            res[preIndex + 1] = val;
        }
        return res;
    }

    /*
    quick sort 快速排序是在数组里面选择一个元素作为参考点，在参考点后面的元素根据大小，
    如果比参考点大移动到后面，如果比参考点小，移动到前面
    */
    std::vector<T> QuickSort(const std::vector<T> &_VecList) {
        std::vector<T> res(_VecList.begin(), _VecList.end());
        if (_VecList.size() < 1) return res;
        partition(res, 0, res.size() - 1);
        return res;
    }
    void partition(std::vector<T> &_VecList, int _Start, int _End) {
        if (_Start > _End) return;
        int left = _Start, right = _End;
        int temp = _VecList[left];
        while (left < right) {
            while (left < right && _VecList[right] > temp) right--;
            if (left < right) {
                _VecList[left++] = _VecList[right];
            }
            while (left < right && _VecList[left] < temp) left++;
            if  (left < right) {
                _VecList[right--] = _VecList[left];
            }
        }
        _VecList[left] = temp;
        partition(_VecList, _Start, left - 1);
        partition(_VecList, left + 1, _End);
    }
};

template <class T>
void printList(const typename std::vector<T> &_VecList) {
    if (_VecList.size() < 1) return;
    for (int i = 0; i < _VecList.size(); i++) {
        std::cout << _VecList[i] << " ";
    }
    std::cout << std::endl; 
}

int main(int argc, char** argv) {
    std::vector<int> vecList = {2, 4, 5, 2, 7, 1, 3, 6, 11};
    std::cout << "original order: " << std::endl; 
    printList<int>(vecList);

    std::cout << "Bubble sort order: " << std::endl; 
    std::vector<int> bubbleList = Solution<int>().BubbleSort(vecList);
    printList<int>(bubbleList);

    std::cout << "Selection sort order: " << std::endl; 
    std::vector<int> selectionList = Solution<int>().SelectionSort(vecList);
    printList<int>(selectionList);

    std::cout << "Insert sort order: " << std::endl; 
    std::vector<int> insertList = Solution<int>().InsertionSort(vecList);
    printList<int>(insertList);
    
    std::cout << "quick sort order: " << std::endl; 
    std::vector<int> quickList = Solution<int>().QuickSort(vecList);
    printList<int>(quickList);
    return 0;
}