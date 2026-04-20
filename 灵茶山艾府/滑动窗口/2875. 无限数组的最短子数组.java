class Solution {
    public int minSizeSubarray(int[] nums, int target) {
        // 统计数组总和
        long total = 0;
        for(int num : nums){
            total+=num;
        }
        // 滑动窗口：我们只需要知道知道target%total的值是多少，在剩下的两个nums数组拼接的情况下必定能拼出target%total
        int left = 0;
        int sum = 0;
        int res = Integer.MAX_VALUE;
        // 这里right的最大值要小于两倍数组长度
        for(int right=0;right<2*nums.length;++right){
            sum += nums[right%nums.length];     //这里必须取余
            while(sum>target%total){    //对应上面解释内容
                sum -= nums[left%nums.length];
                left++;
            }
            if(sum == target % total){      //对应上面解释内容
                res = Math.min(res,right-left+1);
            }
        } 
        //结果注意：1、要判断是否能达到，否则返回-1     2、要补回原来的被跳跃计算掉的多个整数组数量
        return res== Integer.MAX_VALUE ? -1:res+(int)(target/total)*nums.length;    
    }
}