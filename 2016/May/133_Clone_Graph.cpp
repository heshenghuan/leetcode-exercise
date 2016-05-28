/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map; // the map of original node to it's clone
        /* notice that all the node of cloneGraph should be a clone */
        unordered_map<UndirectedGraphNode *, bool> visited;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        while(!q.empty()){
            // BFS
            UndirectedGraphNode *now = q.front();
            q.pop();
            
            /* if a node is already been cloned, pass it */
            if(!visited[now]) {
                visited[now] = true;
                UndirectedGraphNode *cur;
                // Clone the node 'now' itself
                if(map.find(now)==map.end()) {
                    cur = new UndirectedGraphNode(now->label);
                    map[now] = cur;
                }
                else {
                    cur = map[now];
                }
                // Clone the neighbors node of the node 'now'
                for(int i=0;i<now->neighbors.size();i++) {
                    if(map.find(now->neighbors[i])==map.end()) {
                        UndirectedGraphNode *nei = new UndirectedGraphNode(now->neighbors[i]->label);
                        map[now->neighbors[i]] = nei;
                        cur->neighbors.push_back(nei);
                        
                        // BFS: add a new node to the queue
                        q.push(now->neighbors[i]);
                    }
                    else {
                        cur->neighbors.push_back(map[now->neighbors[i]]);
                    }
                }
            }
        }
        return map[node];
    }
};