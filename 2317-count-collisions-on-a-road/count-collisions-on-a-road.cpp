// class Solution {
// public:
//     int countCollisions(string directions) {
//         stack<char>st;
//         int count = 0;

//         for(char ch : directions){
//             if(!st.empty() && st.top()=='R' && ch =='L'){
//                 count+=2;
//                 st.pop();
//                 st.push('S');
//             }
//             else if(!st.empty() && st.top()=='R' && ch =='S'){
//                 count+=1;
//                 st.pop();
//                 st.push('S');
//             }
//             else if(!st.empty() && st.top()=='S' && ch=='L'){
//                 count+=1;
//                 // st.pop();
//                 st.push('S');
//             }
//             else{
//                 st.push(ch);
//             }
//         }
//         while(!st.empty() && st.top()=='R'){
//             st.pop();
//         }

//         while(!st.empty()){
//             if(st.top()=='R'){
//                 count++;
//             }
//             st.pop();
//         }
//         return count;

//     }
// };


class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int count = 0;

        // Ignore all cars moving away from the group at the beginning and end
        int i = 0;
        while (i < n && directions[i] == 'L') i++;
        int j = n - 1;
        while (j >= 0 && directions[j] == 'R') j--;

        // Now from i to j, all moves cause collision except 'S'
        for (int k = i; k <= j; k++) {
            if (directions[k] != 'S')
                count++;
        }
        return count;
    }
};