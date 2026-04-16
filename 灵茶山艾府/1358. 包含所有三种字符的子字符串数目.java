class Solution {
    public int numberOfSubstrings(String s) {
        // 参数准备
        char[] S = s.toCharArray();     // 将字符串转化为字符数组
        int left = 0;
        int res = 0;
        int[] count = new int[3];       // 对三个字母记录
        for(char c : S){
            count[c-'a']++;
            // 我们在这里只需要找到最短的合法的子字符串
            while(count[0]>0&&count[1]>0&&count[2]>0){      
                count[S[left]-'a']--;
                left++;
            }
            // 对于当前的合法的子字符串，前面无论什么前缀，包括这段前缀在内的子字符串都一定合法，个数为left个
            res += left;
        } 
        return res;
    }
}