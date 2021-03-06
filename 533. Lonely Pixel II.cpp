/*533. Lonely Pixel II

Given a picture consisting of black and white pixels, and a positive integer N, 
find the number of black pixels located at some specific row R and column C that align with all 
the following rules:

Row R and column C both contain exactly N black pixels.
For all rows that have a black pixel at column C, they should be exactly the same as row R

The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white 
pixels respectively.

Example:

Input:                                            
[['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'W', 'B', 'W', 'B', 'W']] 

N = 3
Output: 6
Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
        0    1    2    3    4    5         column index                                            
0    [['W', 'B', 'W', 'B', 'B', 'W'],    
1     ['W', 'B', 'W', 'B', 'B', 'W'],    
2     ['W', 'B', 'W', 'B', 'B', 'W'],    
3     ['W', 'W', 'B', 'W', 'B', 'W']]    
row index

Take 'B' at row R = 0 and column C = 1 as an example:
Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as 
row R = 0.

*/

/*这道题是531.Lonely Pixel I的拓展，完全换了一种玩法。给了一个整数N，说对于均含有N个个黑像素的某行某列，如果该列中
所有的黑像素所在的行都相同的话，该列的所有黑像素均为孤独的像素，让我们统计所有的这样的孤独的像素的个数。那么跟之前那题类似，
我们还是要统计每一行每一列的黑像素的个数，而且由于条件二中要比较各行之间是否相等，如果一个字符一个字符的比较写起来比较麻烦，
我们可以用个trick，把每行的字符连起来，形成一个字符串，然后直接比较两个字符串是否相等会简单很多。然后我们遍历每一行和每一
列，如果某行和某列的黑像素刚好均为N，我们遍历该列的所有黑像素，如果其所在行均相等，则说明该列的所有黑像素均为孤独的像素，
将个数加入结果res中，然后将该行的黑像素统计个数清零，以免重复运算，这样我们就可以求出所有的孤独的像素了*/
 
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty() || picture[0].empty()) return 0;
        int nrows = picture.size(), ncols = picture[0].size();
        int res = 0, k = 0;
        vector<int> rowCnt(nrows, 0), colCnt(ncols, 0);
        vector<string> rows(nrows, "");
        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < ncols; j++) {
                rows[i].push_back(picture[i][j]);
                if (picture[i][j] == 'B') {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < ncols; j++) {
                if (rowCnt[i] == N && colCnt[j] == N) {
                    for (k = 0; k < nrows; k++) {
                        if (picture[k][j] == 'B' && rows[i] != rows[k]) break;
                    }
                    if (k == nrows) {
                        res += colCnt[j];
                        colCnt[j] = 0;
                    }
                }
            }
        }
        return res;
    }
};

/*解法二：用哈希表来做，建立黑像素出现个数为N的行和其出现次数之间的映射，然后我们就只需要统计每列的黑像素的个数，然后我
们遍历哈希表，找到出现次数刚好为N的行，说明矩阵中有N个相同的该行，而且该行中的黑像素的个数也刚好为N个，那么第二个条件就
已经满足了，我们只要再满足第一个条件就行了，我们在找黑像素为N个的列就行了，有几列就加几个N即可*/
 
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty() || picture[0].empty()) return 0;
        int nrows = picture.size(), ncols = picture[0].size();
        vector<int> colCnt(ncols, 0);
        unordered_map<string, int> m;
        for (int i = 0; i < nrows; i++) {
            int cnt = 0;
            for (int j = 0; j < ncols; j++) {
                if (picture[i][j] == 'B') {
                    colCnt[j]++;
                    cnt++;
                }
            }
            if (cnt == N){ 
                string s = string(picture[i].begin(), picture[i].end());
                m[s]++;
            }
        }
        int res = 0;
        for (auto &x : m) {
            if (x.second != N) continue;
            for (int i = 0; i < ncols; i++) {
                res += (x.first[i] == 'B' && colCnt[i] == N) ? N : 0;
            }
        }
        return res;
    }
};









