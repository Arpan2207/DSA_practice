#include <iostream>
#include <string>
#include <list>
#include <vector>

class HashTable {
private:
    static const int DEFAULT_SIZE = 10;
    std::vector<std::list<std::pair<std::string, std::string>>> table;
    
    // Simple hash function
    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % table.size();
    }
    
public:
    HashTable(int size = DEFAULT_SIZE) {
        table.resize(size);
    }
    
    // Insert a key-value pair
    void insert(const std::string& key, const std::string& value) {
        int index = hashFunction(key);
        
        // Check if key already exists and update its value
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        
        // Key doesn't exist, insert new pair
        table[index].push_back({key, value});
    }
    
    // Search for a key
    bool search(const std::string& key, std::string& value) {
        int index = hashFunction(key);
        
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        
        return false;
    }
    
    // Remove a key
    bool remove(const std::string& key) {
        int index = hashFunction(key);
        
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return true;
            }
        }
        
        return false;
    }
    
    // Print hash table (for debugging)
    void display() {
        for (int i = 0; i < table.size(); i++) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& pair : table[i]) {
                std::cout << "(" << pair.first << ": " << pair.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};

// Test function
int main() {
    HashTable ht;
    
    // Insert some key-value pairs
    ht.insert("name", "John");
    ht.insert("age", "30");
    ht.insert("city", "New York");
    ht.insert("job", "Engineer");
    
    // Display the hash table
    std::cout << "Hash Table after insertions:" << std::endl;
    ht.display();
    
    // Search for keys
    std::string value;
    if (ht.search("name", value)) {
        std::cout << "Found name: " << value << std::endl;
    }
    
    if (!ht.search("country", value)) {
        std::cout << "country not found in hash table" << std::endl;
    }
    
    // Remove a key
    ht.remove("age");
    
    // Display again after removal
    std::cout << "\nHash Table after removing 'age':" << std::endl;
    ht.display();
    
    return 0;
}
