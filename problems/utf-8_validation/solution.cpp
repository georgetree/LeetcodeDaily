class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int bit = 0;
        for(auto & d: data){
            if(bit == 0){
                if((d >> 5) == 0b110) bit = 1;
                else if((d>>4) == 0b1110) bit = 2;
                else if((d>>3) == 0b11110) bit = 3;
                else if(d>>7) return false;
            }
            else{
                if((d>>6) != 0b10) return false;
                else bit--;
            }
        }
        return bit == 0;
    }
};