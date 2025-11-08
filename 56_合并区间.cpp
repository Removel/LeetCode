 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 
 class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector <vector <int> >res;
    if(intervals.size()==0)return res;
    sort(intervals.begin(),intervals.end(),[](const vector <int>&interval1,const vector <int >&interval2){return interval1[0]<interval2[0];});
    int tempstart=intervals[0][0];
    int tempend=intervals[0][1];
    for(int i=0;i<intervals.size();++i){
        if(intervals[i][0]<=tempend){
            tempend=max(tempend,intervals[i][1]);
        }
        else{
            res.push_back({tempstart,tempend});
            tempstart=intervals[i][0];
            tempend=intervals[i][1];
        }
    }
    res.push_back({tempstart,tempend});
    return res;
}
};
 

 int main(){

 }