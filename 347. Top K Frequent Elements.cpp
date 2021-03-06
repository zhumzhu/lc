/*347. Top K Frequent Elements
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

/* 这道题给了我们一个数组，让我们统计前k个高频的数字，那么对于这类的统计数字的问题，首先应该考虑用HashMap来做，
建立数字和其出现次数的映射，然后再按照出现次数进行排序。我们可以用堆排序来做，使用一个最大堆来按照映射次数从大到小排列，
在C++中使用priority_queue来实现，默认是最大堆 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>> q;
        vector<int> res;
        for (auto n : nums)
            m[n]++;
        
        for (auto &x : m) 
            q.push({x.second, x.first});
        
        for (int i = 0; i < k; i++) {
            res.push_back(q.top().second); 
            q.pop();
        }
        return res;
    }
};












