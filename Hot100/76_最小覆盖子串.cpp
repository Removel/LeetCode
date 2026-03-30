#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
    //听完题解之后自己写的不知道为什么会报错。。。。。。
    //算了自己写的是垃圾别看
    /*
    if(s.length()==-||t.length()==0)return "";
    string res;
        unordered_map<char, int> window;
        unordered_map<char,int >tchars;
        int l=0,r=0;
        int minsize=INT_MAX;
        int have=0,tcount=0;
        for(int i=0;i<t.size();++i){
            tchars[t[i]]+=1;
        }
        tcount=tchars.size();
        while(r<s.size()){
            while(have<tcount){
                if(t.find(s[r])){
                    if(window[s[r]]==tchars[s[r]]-1){
                        have++;
                    }
                    window[s[r]]++;
                }
                r++;
            }
            minsize=min(minsize,r-l+1);
            if(minsize==r-l+1){
                res=s.substr(r,l+1);
            }
            while(have>=tcount){
                if(t.find(s[l])){
                    if(window[s[l]]==tchars[s[l]]+1){
                        have--;
                    }
                    window[s[l]]--;
                }
                l++;
            }
        }
        return res;
    */
   //题解:
   if(s.length()==0||t.length()==0)return "";
   unordered_map<char,int>u_mapT;//t map
   unordered_map<char,int>u_mapW;//window map
   for(int i=0;i<t.size();++i){
    u_mapT[t[i]]++;
   }
   int tcount=u_mapT.size();
   int have=0;
   int resstart=0,reslen=INT_MAX;
   int l=0,r=0;
   while(r<s.length()){
    if(u_mapT.count(s[r])){
        u_mapW[s[r]]++;
        if(u_mapW[s[r]]==u_mapT[s[r]]){
            have++;
        }
    }
    while(have==tcount){
        if(r-l+1<reslen){
            reslen=r-l+1;
            resstart=l;
        }
        if(u_mapT.count(s[l])){
            u_mapW[s[l]]--;
            if(u_mapT[s[l]]>u_mapW[s[l]]){
                --have;
            }
        }
        ++l;
    }
    ++r;
   }
   if(reslen==INT_MAX)return "";
   return s.substr(resstart,reslen);
}
};




int main(){

}