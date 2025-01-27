#include <iostream>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //ok so this is like a class topo sort problem, course prereq graph uh so how do i do topo sort again lol okay lets find out

        //so im given basically a list of edges for a dag, and i have to do a topological sort on the dag

        //alirhgt so my strat is to take the list of edges, then make an adj list, then using the adj find the node with in degree 0
        // then do a topo sort on the root (in deg = 0 node) to get a dictionary where key = course num, val = order it was found in toposort
        // that way i can loop through the queries and check if query[i][0] appears earlier in toposort than query[i][1]

        //ok wait i just realized like while writing that toposort wont help much because a course appearing earlier than another
        //in a toposort doesnt really directly mean its a prereq

        // for example prereq = [[a,b], [b,c], [a,e]] might give me a toposort of a,e,b,c but just cause e appears earlier
        //than c in the toposort doesnt mean its a prereq, so yeah it'd just be better instead to construct an adj list
        //then do dfs starting at each query[i][0] and returning whether query[i][1] is found in the dfs or not

        //first i need to construct the adj list using the nodes

        unordered_map<int, vector<int>> adj_list(numCourses);
        for(vector<int> edge: prerequisites){
            adj_list[edge[0]].push_back(edge[1]);
        }

        // cout << "[";
        // for(vector<int> list: adj_list){
        //     cout << "[";
        //     for(int thing: list){
        //         cout << thing;
        //         cout << ",";
        //     }
        //     cout << "]";
        // }
        // cout << "]" << endl;
        vector<bool> answers(queries.size());
        for(int i = 0; i < queries.size(); i++){
            vector<bool> visited(numCourses, false);
            answers[i] = dfs(adj_list, queries[i][0], queries[i][1], visited);
        }
        return answers;
        
    }

    bool dfs(unordered_map<int, vector<int>>& adj_list, int start, int target, vector<bool>& visited){
        if(start == target){
            return true;
        }
        visited[start] = true;
        bool r = false;
        for(int neighbor: adj_list[start]){
            
            if (!visited[neighbor]){
                r = r + dfs(adj_list, neighbor, target, visited);
            }
        }
        return r;

    }


};