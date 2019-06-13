class Solution {
public:
    int reverse(int x) {
        if (x == 0)
			return 0;
		try
		{
			string s = to_string(x);
			if (s[0] == '-')
				std::reverse(s.begin() + 1, s.end());
			else
				std::reverse(s.begin(), s.end());
			return stoi(s);
		}
		catch (std::out_of_range e)
		{
			return 0;
		}	
    }
};
