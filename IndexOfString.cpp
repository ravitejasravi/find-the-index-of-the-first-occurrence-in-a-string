class Solution {
public:
    int strStr(string haystack, string needle) {

        int NeedleIndex = 0, NeedleLen = needle.length(), HaystackLen = haystack.length();
        int PreviousIndex = -1;

        if(HaystackLen < NeedleLen)
            return -1;
        
        for(int i = 0; i < HaystackLen; i++) {

            if(NeedleIndex != 0 && haystack[i] == needle[0] && PreviousIndex == -1)
                    PreviousIndex = i;
                    
            if(haystack[i] == needle[NeedleIndex]) 
                NeedleIndex++;
                
            else if(NeedleIndex == NeedleLen)
                return i - NeedleIndex;

            else{
                NeedleIndex = 0;

                if(PreviousIndex != -1) {
                    i = PreviousIndex - 1;
                    PreviousIndex = -1;
                }
            }
                
        }

        if(NeedleIndex == NeedleLen)
            return HaystackLen - NeedleIndex;

        return -1;
    }
};