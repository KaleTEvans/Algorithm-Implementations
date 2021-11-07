#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// the two sum brute force solution would be to take each number in the array and search the rest of the array to see if there is a number that would add up to the sum
// a better approach would be to use a hash map, inserting each difference of the array value and the target value as the key and the index as the value
// you can then search the map with each loop to determine if the array value matches any in the map

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> Map;

    if (nums.size() == 2) {
        return {0, 1};
    }

    for (int i=0; i < nums.size(); i++) {
        if (Map.find(target - nums[i]) == Map.end()) {
            Map.insert(make_pair(nums[i], i));
        } else {
            return {i, Map[target - nums[i]]};
        }
    }

}

int main() {
    vector<int> nums = {3, 3};
    int target = 6;

    vector<int> solution = twoSum(nums, target);

    cout << solution[0] << endl;
    cout << solution[1] << endl;
}