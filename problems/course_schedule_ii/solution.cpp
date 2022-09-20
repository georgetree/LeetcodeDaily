class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses);
        for(auto &pr: prerequisites){
            graph[pr[1]].push_back(pr[0]);
            degree[pr[0]]++;
        }
        queue<int> q;
        for(int i=0; i< numCourses; i++){
            if(degree[i]==0)
                q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int temp = q.front();
            res.push_back(temp);
            q.pop();
            for(auto &i: graph[temp]){
                degree[i]--;
                if(degree[i]==0)
                    q.push(i);
            }
        }
        return res.size()==numCourses ? res : vector<int>();
    }
};

 