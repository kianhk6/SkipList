### Basic Vector Operations

1. **Include the Vector Header**
   ```cpp
   #include <vector>
   ```

2. **Declare a Vector**
   ```cpp
   std::vector<int> v;  // Vector of integers
   ```

3. **Initialize a Vector**
   ```cpp
   std::vector<int> v = {1, 2, 3, 4, 5}; // Initialize with elements
   std::vector<int> v(10, 0); // Initialize with 10 elements of value 0
   ```
   
5. **Iterators**
   ```cpp
   v.begin(); // Iterator to the beginning
   v.end();   // Iterator to the end (one past the last element)
   ```

6. **Size and Capacity**
   ```cpp
   v.size();     // Number of elements in the vector
   v.capacity(); // Storage space currently allocated to the vector
   v.empty();    // Check if the vector is empty
   ```

7. **Modify Elements**
   ```cpp
   v.push_back(6); // Add an element to the end
   v.pop_back();   // Remove the last element
   v.insert(v.begin() + 2, 20); // Insert '20' at third position
   v.erase(v.begin() + 1); // Remove the second element
   v.clear(); // Remove all elements
   ```

8. **Resize and Reserve**
   ```cpp
   v.resize(20); // Change the size to 20 elements
   v.reserve(100); // Reserve space for 100 elements
   ```

### Useful Algorithms with Vectors

1. **Find an Element**
   ```cpp
   auto it = std::find(v.begin(), v.end(), value); // Find 'value' in vector
   if (it != v.end()) {
       // Element found
   }
   ```

2. **Sort the Vector**
   ```cpp
   std::sort(v.begin(), v.end()); // Sort in ascending order
   std::sort(v.rbegin(), v.rend()); // Sort in descending order
   ```

3. **Reverse the Vector**
   ```cpp
   std::reverse(v.begin(), v.end()); // Reverse the vector
   ```

4. **Unique Elements (Remove Consecutive Duplicates)**
   ```cpp
   auto it = std::unique(v.begin(), v.end());
   v.resize(std::distance(v.begin(), it)); // Resize vector to new size
   ```

5. **Count Elements**
   ```cpp
   int count = std::count(v.begin(), v.end(), value); // Count occurrences of 'value'
   ```

6. **Binary Search**
   ```cpp
   bool found = std::binary_search(v.begin(), v.end(), value); // Binary search for 'value'
   ```

7. **Max and Min Element**
   ```cpp
   auto max_it = std::max_element(v.begin(), v.end()); // Iterator to max element
   auto min_it = std::min_element(v.begin(), v.end()); // Iterator to min element
   ```

8. **Accumulate (Sum up elements)**
   ```cpp
   int sum = std::accumulate(v.begin(), v.end(), 0); // Sum of all elements
   ```

### Vector of Vectors (2D Vectors)
1. **Declare a 2D Vector**
   ```cpp
   std::vector<std::vector<int>> vec2d(rows, std::vector<int>(cols, initialValue));
   ```

2. **Access and Modify Elements**
   ```cpp
   vec2d[row][col]; // Access element at row, col
   ```

### Miscellaneous
  ```cpp
  for (auto& elem : v) {
      // Use elem
  }
  ```

