/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // first leftCorner A,B rightCorner C, D
        // second leftCorner E,F rightCorner G,H
        int overLape = 0;
        int firstArea = (C - A) * (D - B);
        int secondArea = (G - E) * (H - F);
        std::cout << "firstArea: " << firstArea << " " << " secondArea: " << secondArea << std::endl;
        if ((A >= G && B >= G) || (E >= C && F >= D)) return firstArea + secondArea;
        else {
            int firstLeft = std::max(A, E);
            int firstRight = std::max(B, F);
            int secondLeft = std::min(C, G);
            int secondRight = std::min(D, H);
            if (firstLeft < secondLeft && firstRight < secondRight) 
                overLape = (secondLeft - firstLeft) * (secondRight - firstRight);
            else overLape = 0;
        }
        return firstArea + secondArea - overLape;
    }
};

int main(int argc, char** argv) {
    std::cout << Solution().computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << std::endl; 
    return 0;
}
// @lc code=end

