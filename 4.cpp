class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
vector<int> shortNums = (nums1.size() < nums2.size()) ? nums1 : nums2;
        vector<int> longNums  = (nums1.size() < nums2.size()) ? nums2 : nums1;
        
        double medianVal;
        size_t totalLen = shortNums.size() + longNums.size();
        size_t halfTotalLen = totalLen / 2;
        for (size_t i = 0; i <= shortNums.size(); ++i) {
            int shortLVal = (i == 0                              ) ? INT_MIN : shortNums[i - 1];
            int shortRVal = (i == shortNums.size()               ) ? INT_MAX : shortNums[i];
            int longLVal  = (i == halfTotalLen                   ) ? INT_MIN : longNums[halfTotalLen - i - 1];
            int longRVal  = (halfTotalLen == i + longNums.size() ) ? INT_MAX : longNums[halfTotalLen - i];
            
            if (shortLVal <= longRVal && longLVal <= shortRVal) {
                if (totalLen & 0x1) {
                    medianVal = (shortRVal < longRVal) ? shortRVal : longRVal;
                } else {
                    double a = (shortLVal > longLVal) ? shortLVal : longLVal;
                    double b = (shortRVal < longRVal) ? shortRVal : longRVal;
                    medianVal = (a + b) / 2;
                }
            }
        }
        return medianVal;
        
    }
};
