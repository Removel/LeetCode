#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        //随便加入一个堆，这里假定加入smallPart
        smallPart.push(num);
        //动态调整大小
        //1、保证smallPart的最大值不大于bigPart的最小值
        if(smallPart.size()&&bigPart.size()&&smallPart.top()>bigPart.top()){
            int tmp = smallPart.top();
            bigPart.push(tmp);
            smallPart.pop();
        }
        //2、保证两个堆的大小差不超过1，将多的堆的堆顶元素加到另一个堆中
        //不能用if-else语句，这样会破坏更新逻辑
        if(smallPart.size()>bigPart.size()+1) {
            int tmp = smallPart.top();
            smallPart.pop();
            bigPart.push(tmp);
        }
        if(bigPart.size()>smallPart.size()+1) {
            int tmp = bigPart.top();
            bigPart.pop();
            smallPart.push(tmp);
        }
    }
    
    double findMedian() {
        //如果两个堆的大小相等，说明总数为偶数，返回两个堆顶的平均值
        if(smallPart.size()==bigPart.size()){
            double result = (smallPart.top()+bigPart.top())/2.0;
            return result;
        }
        //如果两个堆的大小不相等，说明总数为奇数，返回大小更大的堆的堆顶
        else if(smallPart.size()>bigPart.size()){
            return smallPart.top();
        }
        else return bigPart.top();
    }
private:
    //大顶堆存储较小的一半数据，堆顶为较小的一半的最大值
    priority_queue<int>smallPart;
    //小顶堆存储较大的一半数据，堆顶为较大的一半的最小值
    priority_queue<int ,vector<int>,greater<int>>bigPart;    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){}