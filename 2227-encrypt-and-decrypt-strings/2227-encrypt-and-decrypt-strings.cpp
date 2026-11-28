class Encrypter {
public:
    vector<string> mp;
    unordered_map<string,int> freq;

    Encrypter(vector<char>& keys,
              vector<string>& values,
              vector<string>& dictionary) {

        mp.assign(26, "");

        // build encryption mapping
        for (int i = 0; i < keys.size(); i++) {
            mp[keys[i] - 'a'] = values[i];
        }

        // encrypt every dictionary word once
        // and count frequency
        for (auto &word : dictionary) {

            string enc = "";

            bool ok = true;

            for (char &ch : word) {

                if (mp[ch - 'a'] == "") {
                    ok = false;
                    break;
                }

                enc += mp[ch - 'a'];
            }

            if (ok)
                freq[enc]++;
        }
    }

    string encrypt(string word1) {

        string s = "";

        for (char &ch : word1) {

            if (mp[ch - 'a'] == "")
                return "";

            s += mp[ch - 'a'];
        }

        return s;
    }

    int decrypt(string word2) {

        return freq[word2];
    }
};