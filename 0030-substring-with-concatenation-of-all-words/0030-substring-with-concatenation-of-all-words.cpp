class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> dummy;
        unordered_map<string, int> freq;
        vector<int> result;
        int size = words[0].size(), complete = 0;

        for(int i=0; i<words.size(); i++){
            if(freq.find(words[i]) != freq.end()){
                freq[words[i]]--;
                continue;
            }
            freq[words[i]] = 0;
        }
        dummy = freq;

        for (int offset = 0; offset < size; offset++) {
            freq = dummy;
            int l = offset;
            int i = offset;
            bool perm = false;

            while (i <= s.size()) {
                string word = s.substr(i, size);

                if (freq.find(word) != freq.end()) {
                    freq[word]++;
                    complete++;
                    if (freq[word] > 1) {
                        while (freq[word] > 1) {
                            string leftWord = s.substr(l, size);
                            freq[leftWord]--;
                            complete--;
                            l += size;
                        }
                    }
                    if (complete == words.size()) {
                        result.push_back(l);
                    }

                    i += size;

                } else {
                    freq = dummy;
                    complete = 0;
                    i += size;
                    l = i;
                }
            }
        }

        return result;
    }
};