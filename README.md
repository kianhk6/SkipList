
1. **Include Necessary Headers**
   ```cpp
   #include <string>
   #include <iostream>
   ```

2. **Declare and Initialize String**
   ```cpp
   std::string str = "example string";
   ```

3. **Using `std::replace` from `<algorithm>`**
   - Replace all occurrences of character 'x' with 'y'.
   ```cpp
   #include <algorithm>
   std::replace(str.begin(), str.end(), 'x', 'y');
   ```

4. **Using `std::replace_if` for Conditional Replacement**
   - Replace characters based on a custom condition.
   ```cpp
   #include <algorithm>
   #include <cctype> // for std::isupper
   std::replace_if(str.begin(), str.end(), [](char c) { return std::isupper(c); }, 'X');
   ```

### Advanced Replacements

1. **Replace Substring with Another Substring**
   - Replace "old_substring" with "new_substring".
   ```cpp
   size_t pos = str.find("old_substring");
   if (pos != std::string::npos) {
       str.replace(pos, std::string("old_substring").length(), "new_substring");
   }
   ```

2. **Using Regular Expressions for Pattern-Based Replacement**
   - For more complex pattern-based replacements.
   ```cpp
   #include <regex>
   std::regex pattern("[aeiou]"); // Pattern to match vowels
   str = std::regex_replace(str, pattern, "*");
   ```

