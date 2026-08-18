class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        std::string s1="qwertyuiop";
        std::string s2="asdfghjkl";
        std::string s3="zxcvbnm";
        std::vector<std::string> ans;
        for(int i=0;i<words.size();++i){
            bool same=1;int prev=0;
            for(int j=0;j<words[i].size();++j){
                if(s1.contains(std::tolower(words[i][j]))){
                    if(prev!=0&&prev!=1){
                        same=false;
                        break;
                    }
                    prev=1;
                }
                else if(s2.contains(std::tolower(words[i][j]))){
                    if(prev!=0&&prev!=2){
                        same=false;
                        break;
                    }
                    prev=2;
                }
                else{
                    if(prev!=0&&prev!=3){
                        same=false;
                        break;
                    }
                    prev=3;
                }
            }
            if(same){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};