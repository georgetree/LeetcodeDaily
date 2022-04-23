class Solution {
public:
    unordered_map<unsigned long,string> s;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        hash<string> h;
        auto t = h(longUrl);
        s.emplace(t,longUrl);
        return "http://tinyurl.com/"+to_string(t);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string t = "http://tinyurl.com/";
        shortUrl.replace(0,t.size(),"");
        
        return s[stoul(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));