#include  <iostream>
#include  <string>
#include  <vector>  
#include  <unordered_set>
using namespace std;

/*
非常巧妙的方法一：
·我们只关心最后的x/y坐标，所以我们可以使用一个滑动窗口来模拟删除子串的过程。
·对于每个窗口，我们计算删除该窗口后最终的坐标，删除该窗口对应的新坐标只是在最终坐标上进行相应的调整，我们可以直接计算删除子串后最终的坐标，而不需要模拟整个过程。
·然后存储在一个无序集合中。
·最后集合的大小就是不同的结果数量。

非常巧妙的方法二：
·对于存储x，y坐标的无序集合，我们可以将x和y坐标编码成一个64位整数（例如使用高32位存储x，低32位存储y），这样可以更高效地存储和比较坐标。
·从而防止了过大的空间存储
*/


// 谁家小longlong最乖？（半藏音）
class Solution {
public:
    int distinctPoints(string s, int k) {
        int x=0,y=0;
        unordered_set<long long>rec;
        //注：从汇编层面来讲，使用switch-case语句可能会比使用if-else语句更高效，因为编译器可以将switch-case优化成跳转表，而if-else语句则需要逐个比较条件。
        //以下就是使用if-else语句的实现，当然也可以使用switch-case语句来实现。
        // 全部扫描一遍得到没有子串时最终的结果
        for(char ch : s ){
            if(ch=='U')y++;
            else if(ch=='D')y--;
            else if(ch=='L')x--;
            else if(ch=='R')x++;
        }

        // 使用偏移量避免负数（假设坐标范围不会超过1e6，可以调整）
        const int OFFSET = s.size();  // 足够大的偏移量，此处用s的长度

        int tmpX=x,tmpY=y;
        //初始化滑动窗口，对于滑动窗口中的每一个字符对应的操作，
        //删去时对最终的影像就是产生反向操作
        for(int i=0;i<k;++i){
            if(s[i]=='U')tmpY--;
            else if(s[i]=='D')tmpY++;
            else if(s[i]=='L')tmpX++;
            else if(s[i]=='R')tmpX--;
        }

        // 如果第一个窗口的结果不一样那么计数器+1，并加入到无序集合中
        long long code = 1LL * (tmpX + OFFSET) << 32 | (tmpY + OFFSET);
        if (rec.find(code) == rec.end()) {
            rec.insert(code);
        }

        //滑动窗口移动
        for(int i=k;i<s.size();++i){
            //加入的字符对应的操作对结果的影响是该操作的反操作
            if(s[i]=='U')tmpY--;
            else if(s[i]=='D')tmpY++;
            else if(s[i]=='L')tmpX++;
            else if(s[i]=='R')tmpX--;
            //离开的字符需要修正回对结果的影响
            if(s[i-k]=='U')tmpY++;
            else if(s[i-k]=='D')tmpY--;
            else if(s[i-k]=='L')tmpX--;
            else if(s[i-k]=='R')tmpX++;
            // 如果这次移动导致结果不一样那么计数器+1，并加入到无序集合中
            long long newCode = 1LL * (tmpX + OFFSET) << 32 | (tmpY + OFFSET);
            if (rec.find(newCode) == rec.end()) {
                rec.insert(newCode);
            }
        }
        //返回结果
        return rec.size();
    }
};