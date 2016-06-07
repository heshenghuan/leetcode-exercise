class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        vector<string> paths = SplitString(path, "/");
        string ans = "";
        for(int i=0;i < paths.size(); i++) {
            if(paths[i] == ".")
                continue;
            else if (paths[i] == "..") {
                if(!s.empty())
                    s.pop();
            }
            else
                s.push(paths[i]);
        }
        while(!s.empty()){
            ans = "/" + s.top() + ans;
            s.pop();
        }
        if(ans == "")
            return "/";
        else
            return ans;
    }
    vector<string> SplitString(string terms_str, string spliting_tag) {
        vector<string> split_str;
        size_t term_beg_pos = 0;
        size_t term_end_pos = 0;
        while ((term_end_pos = terms_str.find_first_of(spliting_tag, term_beg_pos)) != string::npos) {
            if (term_end_pos > term_beg_pos) {
                string term_str = terms_str.substr(term_beg_pos, term_end_pos - term_beg_pos);
                split_str.push_back(term_str);
            }
            term_beg_pos = term_end_pos + 1;
        }
        if (term_beg_pos < terms_str.size()) {
            string end_str = terms_str.substr(term_beg_pos);
            split_str.push_back(end_str);
        }
        return split_str;
    }
};