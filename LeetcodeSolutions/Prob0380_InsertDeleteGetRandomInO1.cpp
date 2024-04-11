class RandomizedSet {

// Vector to store elements

vector<int> v;

// Unordered map to store element-to-index mapping

unordered_map<int, int> m;

  

public:

// Constructor

RandomizedSet() {

// Improve input/output operations performance

std::ios::sync_with_stdio(false);

// Untie cin and cout for performance improvement

cin.tie(nullptr);

}

// Function to insert a value into the set

bool insert(int val) {

// Check if the value already exists in the map

if (m.find(val) != m.end())

return false;

  

// Add the value to the vector

v.push_back(val);

  

// Update the index of the value in the map

m[val] = v.size() - 1;

  

// Return true indicating successful insertion

return true;

}

// Function to remove a value from the set

bool remove(int val) {

// Check if the value exists in the map

if (m.find(val) == m.end())

return false;

  

// Find the iterator to the value in the map

auto it = m.find(val);

  

// Replace the element to be removed with the last element in the vector

v[it->second] = v.back();

  

// Pop the last element from the vector

v.pop_back();

  

// Update the index of the swapped element in the map

m[v[it->second]] = it->second;

  

// Erase the value from the map

m.erase(val);

  

// Return true indicating successful removal

return true;

}

// Function to get a random element from the set

int getRandom() {

// Generate a random index within the vector size

int ind = (rand() % v.size());

// Return the element at the random index

return v[ind];

}

};

  

// Main function to demonstrate the usage of the RandomizedSet class

// Your RandomizedSet object will be instantiated and called as such:

// RandomizedSet* obj = new RandomizedSet();

// bool param_1 = obj->insert(val);

// bool param_2 = obj->remove(val);

// int param_3 = obj->getRandom();


// Time Complexity: O(1) for all operations
// Space Complexity: O(N) where N is the number of elements in the set

/*Code Explained :
Approach
The RandomizedSet class uses a vector v to store elements and an unordered_map m to store the mapping of elements to their indices. The insert operation appends the element to the vector and updates its index in the map. The remove operation swaps the element with the last element in the vector, updates the index in the map, and then removes the last element. The getRandom operation generates a random index and returns the element at that index in the vector.

Algorithm
Insert Operation

Check if the element already exists in the map.
If not, add the element to the vector and update its index in the map.
Remove Operation

Check if the element exists in the map.
If it does, find the element's iterator in the map.
Swap the element with the last element in the vector.
Update the index of the swapped element in the map.
Pop the last element from the vector.
Erase the element from the map.
GetRandom Operation

Generate a random index within the size of the vector.
Return the element at the random index.*/