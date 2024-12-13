class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> map;
        map.clear();
        
        for(auto word: words) { // khoi tao map theo word + so luong cua no
            map[word]++;
        }
        int length = words[0].size(); 
        
        for(int offset = 0; offset < length; offset++) {// lap qua chuoi bat dau boi offset
            unordered_map<string, int> seen; // check xem so luong word da duyet qua tu vi tri offset dau tien, buoc nhay la length
            int size = 0; // kich thuoc cua cua so hien tai
            for(int i = offset; i + length <= s.size(); i = i + length) {
                auto sub = s.substr(i, length);
                auto it = map.find(sub);
                if(it == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }
                seen[sub]++;
                size++;

                while(seen[sub] > it->second) {
                    string first = s.substr(i - (size - 1)*length, length);
                    seen[first]--;
                    size--;
                }

                if(size == words.size()) {
                    res.push_back(i - (size - 1)*length);
                }
            }
        }

        return res;
    }
};
