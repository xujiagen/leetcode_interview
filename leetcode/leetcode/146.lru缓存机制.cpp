/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>
#include <stack>

class LRUCache {
public:
    LRUCache(int capacity) : queueCapacity(capacity) {
    }
    int get(int key) {
        if (map.find(key) != map.end()) {
            int value = (*map[key]).second;
            std::list<std::pair<int, int>>::iterator it = map[key];
            cache.erase(it);
            cache.push_front(std::make_pair(key, value));
            map[key] = cache.begin();
            return value;
        }
        return -1;
    }
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            std::list<std::pair<int, int>>::iterator it = map[key];
            cache.erase(it);
            cache.push_front(std::make_pair(key, value));
            map[key] = cache.begin();
        } else {
            if (cache.size() < queueCapacity) {
                cache.push_front(std::make_pair(key, value));
                map[key] = cache.begin();
            } else {
                map.erase(cache.back().first);
                cache.pop_back();
                cache.push_front(std::make_pair(key, value));
                map[key] = cache.begin();
            }
        }
    }
    const int queueCapacity;
    std::list<std::pair<int, int>> cache;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;
};
/*
int main() {
    return 0;
}
*/
// @lc code=end

