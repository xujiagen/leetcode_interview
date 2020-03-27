#include <iostream>
#include <vector>

void printList(const std::vector<int> vecList) {
    if (vecList.size() < 1) return;
    for (std::size_t i = 0; i < vecList.size(); i++) {
        std::cout << vecList[i] << " ";
    }
    std::cout << std::endl; 
}

class Solution {
  public:
  std::vector<int> TargetList(int N, int L) {
      std::vector<int> res;
      if (L == 1 || N == 1) {
          res.push_back(N);
          return res;
      }
      std::vector<std::vector<int>> vecList;
      int left = 1, right = 2;
      int tmpSum = left;
      while (right < N / 2 + 1) {
          std::cout << "left: " << left << " right: " << right << std::endl; 
          tmpSum += right++;
          if (tmpSum == N) {
              std::vector<int> tmpList;
              for (int i= left; i <= right; i++) {
                  tmpList.push_back(i);
              }
              std::cout << "tmpList size: " << tmpList.size() << std::endl;
              if (tmpList.size() < static_cast<std::size_t>(L)) continue;
              vecList.push_back(tmpList);

          } 
          else if (tmpSum < N) continue;
          else if (tmpSum > N) {
              while (tmpSum > N ) {
                  std::cout << tmpSum << " " << left << std::endl;
                  tmpSum -= left;
                  left++;
              }
              if (tmpSum == N) {
                  std::vector<int> tmpList;
                  for (int i = left; i < right; i++) {
                      tmpList.push_back(i);
                  }
                  if (tmpList.size() < static_cast<std::size_t>(L)) continue;
                  vecList.push_back(tmpList);
              }
          }
      }
      //std::cout << vecList.size() << std::endl;
      int min = 0;
      for (std::size_t i = 0; i < vecList.size(); i++) {
          //std::cout << vecList[i].size() << " " << vecList[min].size() << std::endl; 
          if (vecList[i].size() < vecList[min].size()) min = i;
      }
      for (std::size_t i = 0; i < vecList.size(); i++) {
          printList(vecList[i]);
      }
      return vecList[min];
  }  
};


int main(int argc, char** argv) {
    std::vector<int> vecList = Solution().TargetList(34, 2);
    printList(vecList);
    return 0;
}