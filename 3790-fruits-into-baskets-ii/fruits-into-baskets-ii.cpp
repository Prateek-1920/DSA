class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // vector<int>placed;
        int placed = 0;
        for(int i=0;i<fruits.size();i++){
            int qty = fruits[i];
            for(int j=0;j<baskets.size();j++){
                int size = baskets[j];
                if(qty<=size){
                    // placed.push_back();
                    placed++;
                    baskets[j] = -1;
                    break;
                }
            }
        }
        return fruits.size()-placed;
    }
};