class Solution {
public:
    //for storing mappings of longUrl with it's tiny url and vice-versa
    unordered_map<string, string> code, url;
    //length of this string = 10 + 26 + 26 = 62, which is further used with random function to
    //generate a string for encoding
    string data = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    //helper function to convert a url to its tiny form
    string tinyURL()
    {
        string cipher = "";
        for(int i=0; i<6; i++)
            cipher += data[rand() % 62];
        return "http://tinyurl.com/" + cipher;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        //if a cipher(encoded text) already exists for the given url, return it
        if(url.find(longUrl) != url.end())
            return url[longUrl];
        //storing an encoded string into this variable
        string cipher = tinyURL();

        //generating cipher texts again if they are already present in the code map for some url
        while(code.find(cipher) != code.end())
            cipher = tinyURL();
        //mapping the cipher text with its original url
        code[cipher] = longUrl;
        //mapping the long url with its cipher
        url[longUrl] = cipher;
        //returning the encoded string
        return cipher;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        //the code map will have short url(cipher) mapped to its original url
        return code[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

/*
    TIME COMPLEXITY:
    encode: O(N), for finding values in the maps
    decode: O(1)
    SPACE COMPLEXITY:
    encode: O(N) to save urls lookup
    decode: O(1)
*/
