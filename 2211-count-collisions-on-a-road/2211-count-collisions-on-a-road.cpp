class Solution {
public:
    int countCollisions(string directions) {

        stack<char>st;

        // st.push(directions[0]);
        int res = 0;

        for(int i = 0;i<directions.size();i++) {

            if(directions[i] == 'S') {
                while(st.size() and st.top() == 'R') {
                        res++;
                        st.pop();
                    }
                st.push('S');
            }
            else if(directions[i] == 'L') {

                if(st.size()) {
                    if(st.top() == 'S') {
                        res++;
                        st.push('S');
                    }
                    else if(st.top() == 'R') {
                        res+=2;
                        st.pop();
                        while(st.size() and st.top() == 'R') {
                            res++;
                            st.pop();
                        }
                        st.push('S');
                    }
                }
                else st.push('L');
            }
            else {
                st.push('R');
            }
        }        
        return res;
    }
};

