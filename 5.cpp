class Solution {
public:
    string longestPalindrome(string s) {
        int j = 1;
        string temp="";
        string max ="";
        bool center = true;
        int bottom,upper,next;
        //if(s.length()==0)
        //    return "";
        for(int i=0;i<s.length();)
        {
            j=1;
            bottom = i-1;
            upper = i+1;
            temp = s[i];
            center =true;
            next = i+1;
            while(bottom>=0||upper<s.length())
            {
                if(center == true)
                {
                    center = false;
                    if(bottom>=0&&s[bottom]==s[i])
                    {
                        temp = s[bottom]+temp;
                        bottom--;
                        center = true;
                    }
                    if(upper<s.length()&&s[upper]==s[i])
                    {
                        temp = temp+s[upper];
                        upper++;
                        next = upper;
                        center = true;
                    }
                }
                else if(bottom>=0&&upper<s.length()&&s[bottom]==s[upper])
                {
                    temp=s[bottom]+temp+s[upper];
                    bottom--;
                    upper++;
                }
                else
                    break;
            }
            if(temp.length()>max.length())
                max=temp;
            i = next;
        }
        return max;
        
    }
};
