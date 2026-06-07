class Solution {
public:
    bool consecutiveSetBits(int n) {
        int isPrevSet = 0;
        int isTrue = 0;
        int cnt = 0;
        for(int i=0; i<31; i++) {
            if((1<<i)&n) {
                if(isPrevSet==0) isPrevSet++;
                else if(isTrue>0) {
                    isTrue = -1;
                    cnt--;
                }
                else if(isPrevSet>0 && isTrue==-1) isPrevSet++;
                else {
                    isTrue = 1;
                    cnt++;
                }
            }
            else if(isPrevSet) {
                isTrue = 0;   
                isPrevSet = 0;
            }
        }

        return (cnt==1);
    }
};