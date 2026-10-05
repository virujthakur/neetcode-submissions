class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int newNum = 0;
        do{
            newNum = a ^b;
            carry = (a & b ) << 1;
            a = newNum;
            b = carry;

        }while(carry != 0);
        
        return newNum;
    }
};
