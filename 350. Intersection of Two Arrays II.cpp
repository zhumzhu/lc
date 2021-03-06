/*350. Intersection of Two Arrays II
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot 
load all elements into the memory at once?
*/

/*这道题是349.Intersection of Two Arrays的拓展，不同之处在于这道题允许我们返回重复的数字，
而且是尽可能多的返回，之前那道题是说有重复的数字只返回一个就行。那么这道题我们用哈希表来建立nums1中字符和其出现
个数之间的映射, 然后遍历nums2数组，如果当前字符在哈希表中的个数大于0，则将此字符加入结果res中，然后哈希表的对应
值自减1*/


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        for (auto n : nums1) {
            m[n]++;
        }
        for (auto n : nums2) {
            if (m[n] > 0) res.push_back(n);
            m[n]--;
        }
        return res;
    }
};









