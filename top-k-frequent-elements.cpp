// ! leetcode program , won't execute 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int , int > m ;
        vector<int> ans ;

        for(int i = 0 ;i< nums.size() ;i++){
            m[nums[i]]++ ;
        }

        priority_queue<pair<int,int>> heap ;

        map<int,int> :: iterator it ;

        for(it = m.begin() ; it != m.end() ; it++){
            heap.push(make_pair(it->second , it->first));
        }

        for(int i= 0 ; i< k ; i++){
            ans.push_back(heap.top().second);
            heap.pop();
        }

        return ans;
        
    }
};