class Solution {
public:
    string add(string& s1, string& s2){
        string s3;
        int carry =0;
        int i=0, j=0;
        for(; i<s1.size() && j<s2.size(); i++,j++){
            int d1 = s1[i] - '0';
            int d2 = s2[j] - '0';
            int d3 = d1 + d2 + carry;
            carry = d3 /10;
            d3 %= 10;
            s3.push_back(d3+'0');
        }
        
        while(i<s1.size()){
            int d1 = s1[i] - '0';
            int d3 = d1 + carry;
            carry = d3 /10;
            d3 %= 10;
            s3.push_back(d3+'0');
            i++;
        }

        while(j<s2.size()){
            int d1 = s2[j] - '0';
            int d3 = d1 + carry;
            carry = d3 /10;
            d3 %= 10;
            s3.push_back(d3+'0');
            j++;
        }

        if(carry){
            s3.push_back('1');
        }
        // cout<<s3<<endl;
        return s3;
    }

    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if(num1.size() < num2.size()) swap(num1, num2);
        
        string prev;
        for(int i=0; i<num2.size(); i++){
            int carry = 0;
            int d1 = num2[i] - '0';
            string temp;
            for(int j=0; j<i; j++){
                temp.push_back('0');
            }

            for(int j=0; j<num1.size(); j++){
                int d2 = num1[j] - '0';
                int d3 = d1 * d2 + carry;
                // cout<<d3<<endl;
                carry = d3 /10;
                d3 %= 10;

                temp.push_back(d3+'0');
            }

            if(carry){
                // cout<<carry<<endl;
                temp.push_back('0' + carry);
            }

            // cout<<temp<<endl;
            prev = add(prev, temp);
        }

        while(prev.back() == '0' && prev.size() > 1){
            prev.pop_back();
        }
        reverse(prev.begin(), prev.end());
        return prev;
    }
};
