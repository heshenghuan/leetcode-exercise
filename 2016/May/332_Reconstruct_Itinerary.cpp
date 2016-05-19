class Solution {
public:
    /*
    * 一条路走到黑，走到死路就回退，因为如果存在题目所述的itinerary的话，不可能存在超过一条的单向路线
    * 并且因为是行程，所以一定不会出现到达不了的情况，然后把单向路线上的站点按照出栈顺序加上去即可
    * 例如：[["JFK","MUC"],["MUC","SFO"],["SFO","JFK"],["MUC","LHR"]]这样的行程是不可能的
    * 所以一条路走到黑然后回退，一定能保证这条死路是能够添加上的
    */
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        vector<string> ans;
        if(tickets.size() < 1) return ans;
        std::map<string, std::priority_queue<string, vector<string>, greater<string> > > mymap;
        for (int i=0;i<tickets.size();i++) {
            if (mymap.end() == mymap.find(tickets.at(i).first)) {
                priority_queue<string, vector<string>, greater<string> > des;
                mymap[tickets.at(i).first] = des;
            }
            mymap.at(tickets.at(i).first).push(tickets.at(i).second);     
        }
        
        string now = "JFK";
        std::stack<string> s;
        for (int i=0;i<tickets.size();i++) {
            while(mymap.find(now) == mymap.end() || mymap.at(now).empty()) {
                s.push(now);
                now = ans.back();
                ans.pop_back();
            }
            ans.push_back(now);
            string curr = now;
            now = mymap.at(curr).top();
            mymap.at(curr).pop();
        }
        ans.push_back(now);
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};