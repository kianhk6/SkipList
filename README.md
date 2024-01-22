### Iterator Basics

1. **Include the Iterator Header**
   ```cpp
   #include <iterator>
   ```

2. **Declaring Iterators**
   ```cpp
   std::vector<int>::iterator it; // Iterator for a vector of ints
   ```

### Initializing an Iterator and Dereferencing It

```cpp
auto iterator = container.begin(); // Initialize iterator to the beginning of the container
int value = *iterator; // Dereference the iterator to obtain the first element's value
```

### Common Iterator Functions

1. **Begin and End**
   ```cpp
   auto it = container.begin(); // Iterator to the beginning
   auto it_end = container.end(); // Iterator to the end (past-the-last element)
   ```

4. **Advance an Iterator**
   ```cpp
   std::advance(it, n); // Move iterator it forward by n steps
   ```

### Algorithms Using Iterators

1. **Sort Using Iterators**
   ```cpp
   std::sort(container.begin(), container.end()); // Sort elements in the container
   ```

2. **Finding Elements**
   ```cpp
   auto found_it = std::find(container.begin(), container.end(), value); // Find 'value'
   ```

3. **Copy Elements**
   ```cpp
   std::copy(src.begin(), src.end(), dest.begin()); // Copy from src to dest
   ```

4. **Accumulate Values**
   ```cpp
   int sum = std::accumulate(container.begin(), container.end(), 0); // Sum values
   ```

5. **Replace Values**
   ```cpp
   std::replace(container.begin(), container.end(), old_val, new_val); // Replace old_val with new_val
   ```

6. **Remove Elements**
   ```cpp
   auto new_end = std::remove(container.begin(), container.end(), value); // Remove 'value'
   container.erase(new_end, container.end()); // Erase the removed elements
   ```

7. **Unique Elements**
   ```cpp
   auto new_end = std::unique(container.begin(), container.end()); // Remove consecutive duplicates
   container.resize(std::distance(container.begin(), new_end)); // Resize container
   ```

### Iterating Over Containers

- **Using Range-Based For Loop**
  ```cpp
  for (auto& element : container) {
      // Use element
  }
  ```

- **Using Traditional Iterators**
  ```cpp
  for (auto it = container.begin(); it != container.end(); ++it) {
      // Use *it
  }
  ```

