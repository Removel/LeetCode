#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
/*
    //笨的做法
    //显然会超时，于是我们不要用这种笨蛋方法
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        //获取最大值和已经有的数量
        int maxNum = 0;
        int whiteNum = 0;
        for(auto nums : tiles){
            maxNum = max(maxNum,nums[1]);
        }
        //根据最大值声明数组
        vector<bool> record(maxNum+1,false);
        //根据区间将数组对应位置更新成白色（true）
        for(auto nums: tiles){
            int left = nums[0];
            int right = nums[1];
            for(int i = left;i<=right;++i){
                record[i]=true;
                whiteNum++;
            }
        }
        //定长滑动窗口查看数组当中的最大覆盖数
        //初始化滑动窗口
        int maxCount = 0;
        if(carpetLen>=maxNum)return whiteNum;
        for(int i = 0;i<carpetLen;++i){
            if(record[i]){
                maxCount++;
            }
        }
        //移动滑动窗口
        int count = maxCount;
        for(int i=carpetLen;i<record.size();++i){
            if(record[i]){
                count++;
            }
            if(record[i-carpetLen]){
                count--;
            }
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
*/ 
/*
解析来自力扣官方评论区
提示 1
一定存在至少一种覆盖砖块最多的方案，它的起始位置是在某一段连续瓷砖的第一个。

提示 1 解释
我们可以使用反证法证明。假设某一种起始位置不在某一段连续瓷砖第一个的覆盖方案覆盖的数量高于任何起始位置在连续瓷砖第一个的方案，则会有以下两种情况：
1、起始位置没有瓷砖，此时假设起始位置距离下一个瓷砖为 m（如果不存在下一段瓷砖，则覆盖数量一定为 0，不符合要求），那么我们将起始位置右移 m 格，由于移开的这 m 格没有瓷砖，因此数量一定不会减少，这就产生了矛盾；
2、起始位置在某段连续瓷砖的中间位置，此时假设起始位置距离该段瓷砖起始位置距离为 m，那么我们将起始位置左移 m 格，由于加入的这 m 格一定都有瓷砖，因此数量一定不会减少，这也产生了矛盾。

来源：力扣（LeetCode）
*/
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        int n = tiles.size();
        int res = 0; //结果变量
        int count = 0;  //记录当前能够覆盖白色瓷砖的最大数量
        int right = 0;  //右指针变量
        for(int left = 0 ;left<n;++left){
            //最开始left为0的时候跳过count减少,从1开始移动时就需要减少之前的连续的白色瓷砖
            if(left){
                count -= tiles[left-1][1]-tiles[left-1][0]+1;
            }
            //右移right指针，增加能覆盖到的面积
            while(right<n&&tiles[right][1]-tiles[left][0]<carpetLen){  //即：1、右指针不能超过边界 2、右指针指向的区间末尾和左指针指向的区间开始的长度必须要小于地毯长度的
                //若符合那么更新count数量:右指针指向区间的长度
                count+=tiles[right][1]-tiles[right][0]+1;
                //移动右指针
                ++right;
            }
            //如果右指针移动到最后了仍未超过地毯长度，那么说明之后不会有更多的覆盖瓷砖数量，那么我们直接比较更新结果然后返回
            if(right==n){
                res = max(res,count);
                return res;
            }
            /*此时右指针右移结束之后只会有两种情况：
            1、毯子的右边端点处不在白色瓷砖的区间之内，此时右指针指向毯子完全覆盖区间的下一个白色瓷砖区间
            2、毯子的右边端点处在白色瓷砖的区间之内，此时右指针指向毯子不能完全覆盖的白色瓷砖区间
            对于第一种情况，count不用增加
            对于第二种情况，count需要增加这段没有完全覆盖的那块被部分覆盖的区间，计算公式为：
            extra =tiles[l][0] + carpetLength - tiles[right][0]  长区间-短区间
            根据以上可总结为 extra = max(0,tiles[l][0] + carpetLength - tiles[right][0])
            */
            int extra = max(0,tiles[left][0] + carpetLen - tiles[right][0]);
            //更新结果:当前已有结果与count+extra的更大值
            res = max(count+extra,res);
        }
        return res;
    }
};
//这道题其实还是蛮难理解的