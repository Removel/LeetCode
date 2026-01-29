#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:

//尚未优化版本，dp，时间复杂度为O(n*n)
    int lengthOfLIS(vector<int>& nums) {
        //dp记录的是当前nums对应元素为止能得到的最大的要求的子序列长度
        vector <int> dp(nums.size(),1);
        dp[0]=1;
        int maxsize = 1;
        //遍历nums数组
        for(int i=0;i<nums.size();++i){
            //遍历当前元素之前的记录的所有dp元素
            for(int j=0;j<i;++j){
                //如果当前元素比遍历到的dp对应的nums元素更大，说明可以作为当前遍历到的dp元素所在子序列的一个元素
                //此时比较dp[i]跟dp[j]+1谁更大即可
                if(nums[i]>nums[j])dp[i]=max(dp[j]+1,dp[i]);    
            }
            maxsize = max(dp[i],maxsize);
        }
        return maxsize;
    }


/*
//不会喵，自己以后再看喵~
//优化版本，使用二分法与贪心算法，降低时间复杂度到O（nlogn）
    int lengthOfLIS(vector<int>& nums) {
            int len = 1, n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } else {
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/longest-increasing-subsequence/solutions/147667/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
        }  
*/  
};

int main(){

}