### Basic String Operations

1. **Include the String Header**
   ```cpp
   #include <string>
   ```

2. **Declare and Initialize Strings**
   ```cpp
   std::string str;                // Empty string
   std::string str1 = "Hello";     // Initialized with a C-string
   std::string str2(str1);         // Copy constructor
   std::string str3(5, 'a');       // Initialize with 5 'a' characters
   ```

5. **String Size and Capacity**
   ```cpp
   unsigned long len = str1.length(); // Length of the string
   unsigned long size = str1.size();  // Same as length
   bool isEmpty = str1.empty();       // Check if string is empty
   ```

6. **Substring and Erase**
   ```cpp
   std::string substr = str1.substr(1, 3); // Get substring ("ell")
   str1.erase(1, 3); // Erase part of the string, leaving "Ho"
   ```

### Advanced String Operations

1. **String Searching**
   ```cpp
   size_t found = str1.find("lo"); // Find substring, returns position
   if (found != std::string::npos) {
       // Substring found
   }
   ```

2. **Replace Substring**
   ```cpp
   str1.replace(0, 2, "Heaven"); // Replace first two characters
   ```


4. **Numeric Conversion**
   ```cpp
   int num = std::stoi("42");  // String to integer
   std::string strNum = std::to_string(42); // Integer to string
   ```

5. **Iterating Over a String**
   ```cpp
   for (char &c : str1) {
       // Use char c
   }
   ```
1. **Counting Elements**
   ```cpp
   int numA = std::count(str1.begin(), str1.end(), 'A'); // Count occurrences of 'A'
   ```

2. **Finding Substrings**
   ```cpp
   auto it = std::search(str1.begin(), str1.end(), str2.begin(), str2.end()); // Find substring str2 in str1
   if (it != str1.end()) {
       // Substring found
   }
   ```

3. **Permutations**
   ```cpp
   do {
       std::cout << str1 << std::endl;
   } while (std::next_permutation(str1.begin(), str1.end())); // Print all permutations
   ```


4. **Unique Elements (Remove Consecutive Duplicates)**
   ```cpp
   auto last = std::unique(str1.begin(), str1.end());
   str1.erase(last, str1.end()); // Remove consecutive duplicates
   ```


 **Sorting and Reversing**
   ```cpp
   #include <algorithm>
   std::sort(str1.begin(), str1.end()); // Sort string
   std::reverse(str1.begin(), str1.end()); // Reverse string
   ```

### Converting Basic Data Types to String

1. **Include the Necessary Headers**
   ```cpp
   #include <string>  // For std::string and std::to_string
   ```

2. **Integer to String**
   ```cpp
   int intValue = 42;
   std::string intStr = std::to_string(intValue); // Convert int to string
   ```

3. **Float to String**
   ```cpp
   float floatValue = 3.14f;
   std::string floatStr = std::to_string(floatValue); // Convert float to string
   ```

4. **Double to String**
   ```cpp
   double doubleValue = 2.71828;
   std::string doubleStr = std::to_string(doubleValue); // Convert double to string
   ```
Sure! Let's add how to convert strings to integer and float in C++. These conversions are common when dealing with input data or text processing where numeric values are represented as strings.

### Converting Strings to Numeric Types

1. **Include the Necessary Headers**
   ```cpp
   #include <string>  // For std::string
   #include <cstdlib> // For std::atoi and std::atof
   ```

2. **String to Integer**
   - Using `std::stoi` (throws an exception if conversion fails):
     ```cpp
     std::string intStr = "42";
     int intValue = std::stoi(intStr); // Convert string to int
     ```

   - Using `std::atoi` (returns 0 if conversion fails, part of `<cstdlib>`):
     ```cpp
     int intValue2 = std::atoi(intStr.c_str()); // Convert string to int
     ```

3. **String to Float**
   - Using `std::stof` (throws an exception if conversion fails):
     ```cpp
     std::string floatStr = "3.14";
     float floatValue = std::stof(floatStr); // Convert string to float
     ```

   - Using `std::atof` (returns 0.0 if conversion fails, part of `<cstdlib>`):
     ```cpp
     float floatValue2 = std::atof(floatStr.c_str()); // Convert string to float
     ```

4. **String to Double**
   - Using `std::stod`:
     ```cpp
     std::string doubleStr = "2.71828";
     double doubleValue = std::stod(doubleStr); // Convert string to double
     ```
