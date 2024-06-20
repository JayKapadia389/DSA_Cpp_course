class Solution {
public:
    map<int , vector<int>> preMap ;
    map<int,bool> completed ;
    vector<int> ans ;
    map<int , bool> visited ;

    bool dfs(int crs){

        if(visited[crs] == 1){
            return false ;
        }

        if(preMap[crs].size() == 0){
            if(!completed[crs]){
                completed[crs] = 1 ;
                ans.push_back(crs) ;

            }

            return true ;

        }

        visited[crs] = 1 ;

        for(auto i : preMap[crs]){
            if(!dfs(i)){
                return false ;
            }
        }

        visited[crs] = 0; 
        completed[crs] = 1 ;
        ans.push_back(crs) ;
        preMap[crs] = {} ;

        return true ;

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> empty ;

        for(int i = 0 ; i< prerequisites.size() ; i++){

            preMap[prerequisites[i][0]].push_back(prerequisites[i][1]) ;

        }

        set<int> noPreq ;

        for(int i = 0 ; i< prerequisites.size() ; i++){

            noPreq.insert(i) ;
            cout << "in>>" << i << endl;

        }

        for(int i = 0 ; i< prerequisites.size() ; i++){

            auto it = noPreq.find(prerequisites[i][0]) ;

            if(it != noPreq.end()){
                noPreq.erase(it) ;
            }

        }

        if(noPreq.empty()){
            cout << "err>1" ;
            return empty ;
        }

        for(auto it : noPreq){
            if(!dfs(it)) {
                 cout << "err>2" ;
                return empty ;
            }
        }

        if(ans.size() != numCourses){
            cout << "err>3" ;
            return empty ;
        }

        return ans ;

        
    }
};