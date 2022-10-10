/**
    LeetCode_981
    https://leetcode.com/problems/time-based-key-value-storage/
    MatrixDeity, 2022.
*/

#include <map>
#include <unordered_map>
#include <string>

using namespace std;

class TimeMap {
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        storage[key].insert({ timestamp, value });
    }

    string get(string key, int timestamp) {
        auto substorageIt = storage.find(key);
        if (substorageIt == storage.end()) {
            return "";
        }

        auto& substorage = substorageIt->second;
        auto valueIt = substorage.lower_bound(timestamp);

        if (valueIt->first == timestamp) {
            return valueIt->second;
        }
        if (valueIt == substorage.begin()) {
            return "";
        }
        return (--valueIt)->second;
    }

private:
    unordered_map<string, map<int, string>> storage;
};
