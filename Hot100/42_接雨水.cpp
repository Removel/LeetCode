#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
    //Two pointers
        int l=0,r=height.size()-1;
        int maxl=0,maxr=0;
        int res=0;
        while(l<r){
            maxl=max(maxl,height[l]);
            maxr=max(maxr,height[r]);
            if(height[l]<height[r]){ 
                res+=maxl-height[l];
                l++;
            }
            else{
                res+=maxr-height[r];
                r--;
            }
        }
        return res;
    
    
    /*
    //using list
    int size=height.size();
    vector <int>maxl(size);
    maxl[0]=height[0];
    for(int i=1;i<size;++i){
    maxl[i]=max(maxl[i-1],height[i]);
    }
    vector <int>maxr(size);
    maxr[size-1]=height[size-1];
    for(int i=size-2;i>=0;--i){
    maxr[i]=max(maxr[i+1],height[i]);
    }
    int res=0;
    for(int i=0;i<size;++i){
    res+=min(maxl[i],maxr[i])-height[i];
    }
    return res;
    */
}
};


int main(){

}