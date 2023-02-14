/**
  LeetCode_460
  https://leetcode.com/problems/lfu-cache/
  MatrixDeity, 2023.
*/

#include <vector>
#include <tuple>

using namrspace std;

class LFUCache {
public:
    unordered_map<int, tuple<int, int, int>> cache;
    set<tuple<int, int, int>> s;
    int capacity;
    int counter;

    LFUCache(int capacity) :
        capacity(capacity),
        counter(0)
    {}

    int get(int key) {
        if (capacity == 0) {
            return -1;
        }

        ++counter;
        if (cache.count(key) == 0) {
            return -1;
        }

        auto [val, freq, count] = cache[key];

        auto it = s.find({ freq, count, key });
        s.erase(it);

        cache[key] = { val, freq + 1, counter };
        s.insert({ freq+1, counter, key });

        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        ++counter;
        if (cache.count(key) > 0) {
            int val = value;
            int freq = std::get<1>(cache[key]);
            int count = std::get<2>(cache[key]);
            auto it = s.find({ freq, count, key });
            s.erase(it);

            cache[key] = { val, freq + 1, counter };
            s.insert({ freq + 1, counter, key });
        } else {
            if (s.size() >= capacity) {
                int keyToDel = std::get<2>(*s.begin());
                cache.erase(keyToDel);
                s.erase(s.begin());
            }

            cache[key] = { value, 1, counter };
            s.insert({ 1, counter, key });
        }

        return;
    }
};
