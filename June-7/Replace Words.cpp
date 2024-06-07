------------------->>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<----------------------
// time complexity of the code is O(n * m + k * l)
// space complexity of the code is O(n * m + k + sentence length)

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        set<string> s(begin(dict), end(dict));
        istringstream iss(sentence);
        vector<string> temp;
        string word, res; 

        while(iss >> word) temp.push_back(word);
        for(string t : temp) {
            int i = 0;
            while(i++ <= t.length()) {
                string curr = t.substr(0, i);
                if(s.find(curr) != s.end()) {
                    res += curr + " ";
                    break;
                }
                
                if(i == t.length()) res += curr + " ";
            }
        }

        res.erase(res.size() - 1);
        return res;
    }
};



 ------------------------------->>>>>>>>>>>> Approach-2 <<<<<<<<<<<<<<<<<<<<<----------------------
// Time Complexity: O(k + n + w * l^2)
// Space Complexity: O(k + n)



 class Solution {
public:
     
      // Helper function to split a sentence into words
    vector<string> split(const string& s, char delimiter) {
    vector<string> words;  // Vector to store the substrings
    string word;           // Temporary string to hold each substring
    istringstream stream(s); // Initialize a stream with the input string
    
    // Read each word separated by the delimiter
    while (getline(stream, word, delimiter)) {
        words.push_back(word); // Add the extracted substring to the vector
    }
    
    return words; // Return the vector of substrings
}

  
    // Helper function to join words into a sentence
string join(const vector<string>& words, char delimiter) {
    ostringstream joined; // Initialize an output string stream

    // Loop through each word in the vector
    for (size_t i = 0; i < words.size(); ++i) {
        if (i != 0) { // If it's not the first word
            joined << delimiter; // Add the delimiter before the word
        }
        joined << words[i]; // Add the word to the stream
    }

    return joined.str(); // Convert the stream to a string and return it
   }
     



    // Function to replace words in the sentence based on the dictionary
    string replaceWords(vector<string>& dictionary, string sentence) {
        // Convert dictionary to a set for fast lookup
        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
        
        // Split the sentence into individual words
        vector<string> words = split(sentence, ' ');
        
        // Loop through each word in the sentence
        for (string& word : words) {
            // Try to find the smallest prefix in the dictionary
            for (int len = 1; len <= word.size(); ++len) {
                // Extract the prefix
                string prefix = word.substr(0, len);
                // If the prefix is in the dictionary, replace the word
                if (dictSet.find(prefix) != dictSet.end()) {
                    word = prefix;
                    break; // Stop checking longer prefixes
                }
            }
        }
        
        // Join the words back into a single string
        return join(words, ' ');
    }
    

   

};