#include<string>
#include<cstring>
#include<vector>
using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        if(isIPv4(IP)) return string("IPv4");
        if(isIPv6(IP)) return string("IPv6");
        return string("Neither");
    }
    bool isIPv6(string IP){
        nums.clear();
        int temp,i,j;
        split(IP,nums,':');
        if(nums.size()!=8) return false;
        for(i=0;i<8;i++){
            if(nums[i].size()==0 || nums[i].size()>4) return false;//³ß´ç¼ì²é
            //if(nums[i].size()>1 && nums[i][0]=='0') return false;//Ê×0¼ì²é
            for(j=0;j<nums[i].size();j++){
                if(!(nums[i][j] >= '0' && nums[i][j] <= '9' 
                || nums[i][j] >= 'a' && nums[i][j]<='f'
                || nums[i][j] >= 'A' && nums[i][j] <= 'F')){
                    return false;
                }
            }//×Ö·û¼ì²é
        }
        return true;
    }
    bool isIPv4(string IP){
        nums.clear();
        int temp;
        split(IP,nums,'.');
        if(nums.size()!=4) return false;
        for(int i=0;i<4;i++){
            for(int j=0;j<nums[i].size();j++){
                if(nums[i][j]<'0' || nums[i][j]>'9') 
                    return false;
            }
            if(nums[i].size() >3 || nums[i].size()<1) return false;
            if(nums[i].size() > 1 && nums[i][0] == '0') return false;
            temp = stoi(nums[i]);
            if(temp >= 256) return false;
        }
        return true;
    }
    void split(string source, vector<string> &result, char ch){
        int start = 0, end = 0;
        while(1){
            while(end < source.size() && source[end]!=ch) end++;
            result.push_back(source.substr(start,end-start));
            if(end==source.size()) break;
            start = ++end;
        }
    }
    vector<string> nums;
};