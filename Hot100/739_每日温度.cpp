#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
/*
    //最常规的方法是使用双重扫描，时间复杂度为O(n*n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector <int> res;
        for(int i=0;i<temperatures.size();++i){
            for(int j=i+1;j<temperatures.size();++j){
                if(temperatures[i]<temperatures[j]){
                    res.push_back(j-i);
                    break;
                }
                if(j==temperatures.size()-1)res.push_back(0);
            }
        }
        res.push_back(0);
        return res;
    }
*/
    //既然来都来了那就不要只写上面那种东西了
    //单调栈：栈当中的元素从栈底到栈顶单调递增或者递减，本题当中的单调栈为单调递减栈
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //初始化栈和结果数组
        stack <int>rec;
        vector<int>ans(temperatures.size(),0);
        //遍历传入的数组
        for(int i=0;i<temperatures.size();++i){
            /*
            条件：栈非空并且当前遍历到的元素比栈顶元素大
            这样保证了既能找到天数又能使得栈是单调栈，解释如下：
                对于当前元素有：
                1、当前元素比栈顶指向元素更大：说明当前元素是栈顶指向元素的第一个合法结果
                -》更新：更新ans，弹出栈顶指向，查看弹出之后的栈顶指向元素与当前元素的关系
                （由于栈维护成单调递减栈，使得下一个比较的指向元素会是最接近被弹出的指向元素的更大元素）
                2、当前元素比栈顶指向元素更小：入栈，维护栈的单调递减性质
            */
            while(!rec.empty()&&temperatures[i]>temperatures[rec.top()]){ 
                //在这里栈储存的是索引而不是具体数字，能够更好的获取与更新
                //对于栈顶元素的索引index有：其下一个比它更高温度的天数为i-index
                int index=rec.top();
                ans[index]=i-index;
                //记得在更新完之后弹栈
                rec.pop();
            }
            //将当前元素入栈
            rec.push(i);
        }
        //对于最后可能有些元素没有经历上面的做法，即说明之后没有比它更高的温度了，在初始化的时候已经自动填充好了0
        //返回结果
        return ans;
    }
};

int main(){

}