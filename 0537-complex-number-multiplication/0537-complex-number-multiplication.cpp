class Solution {
public:
    vector<int>parse(string str) {

        string str1 = "";
        string str2 = "";

        int i = 0;
        for(i;i<str.size();i++) {
            if(str[i] == '+')
            break;
            str1+=str[i];
        }
        i++;
        for(i;i<str.size();i++) {
            if(str[i] == 'i')
                break;
            str2+=str[i];
        }
        cout<<str1<<" "<<str2<<endl;
        return {stoi(str1),stoi(str2)};
    }
    string complexNumberMultiply(string num1, string num2) {
        

        vector<int>v1 = parse(num1);
        vector<int>v2 = parse(num2);

        int x1 = v1[0],y1 = v1[1];
        int x2 = v2[0],y2 = v2[1];

        int real = (x1*x2) - (y1*y2);
        int img = (x1*y2) + (y1*x2);

        return to_string(real) + "+" + to_string(img) + "i";

    }
};