class Solution {
public:
    unordered_map<string,string> encoded;
    unordered_map<string,string> decoded;
    string base = "http://tinyurl.com/";

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(encoded.find(longUrl)==encoded.end()){
            string shorturl = base + encoded[longUrl];
            encoded[longUrl] = shorturl;
            decoded[shorturl] = longUrl;
        }
        return encoded[longUrl];

    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(decoded.find(shortUrl)==decoded.end()){
            string longurl = base + decoded[shortUrl];
            decoded[shortUrl] = longurl;
            encoded[longurl] = shortUrl;
        }
        return decoded[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));