class Solution {
public:
    string convert(string s, int numRows) {
vector<string> vs(numRows);
        string r;
        if(numRows==1)
            return s;
        for (int i=0; i < numRows; i++) {
            if (i == 0) {
                for (int k=0; k*(2 * numRows - 2) < s.size(); k++) {
                    r+= s[k*(2 * numRows - 2)];
                }
            }
            else if (i == numRows - 1) {
                for (int k=0; k*(2 * numRows - 2) + numRows - 1 < s.size();k++) {
                    r+= s[k*(2 * numRows - 2) + numRows - 1];
                }
            }
            else {
                for (int k=0; k*(2 * numRows - 2) + i <s.size() || (k+1)*(2*numRows-2)-i<s.size();k++) {
                    r+= s[k*(2 * numRows - 2) + i];
                    if ((k + 1)*(2 * numRows - 2) - i < s.size()) {
                        r+= s[(k + 1)*(2 * numRows - 2) - i];
                    }
                }
            }
        }
        return r;
    }
};
