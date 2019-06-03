//3. 无重复字符的最长子串
//时间复杂度：O(n)，将会迭代n次。
//空间复杂度（HashMap）：O(n)。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       map<char,int> mymap;
        map<char,int>::iterator iter;
        int n = 0,max=0,j=0;
        for(int i=0;i<s.length();i++)
        {
	        if(mymap.find(s[i])!= mymap.end()&&mymap[s[i]]>=j)
            {
	          n =n - mymap[s[i]]+j-1;
              j= mymap[s[i]]+1;  
            }
          mymap[s[i]]=i;
	   n++;
	   if(n>max)
          max=n;
        }
        return max;
    }
};
