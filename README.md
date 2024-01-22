### Upper case and Lower Case

1. **Include Necessary Headers**
   ```cpp
   #include <string>
   #include <iostream>
   #include <cctype>  // for std::toupper, std::tolower
   #include <algorithm>  // for std::transform
   #include <locale>  // for std::locale
   ```

2. **Declare and Initialize String**
   ```cpp
   std::string str = "Example String";
   ```

### Convert to Uppercase

1. **Using Character-by-Character Manipulation**
   - Convert each character to uppercase using `std::toupper`.
   ```cpp
   for (char& c : str) {
       c = std::toupper(c);
   }
   ```

2. **Using `std::transform` with `std::toupper`**
   - Convert the entire string to uppercase in one line.
   ```cpp
   std::transform(str.begin(), str.end(), str.begin(),
                  [](unsigned char c) { return std::toupper(c); });
   ```

### Convert to Lowercase

1. **Using Character-by-Character Manipulation**
   - Convert each character to lowercase using `std::tolower`.
   ```cpp
   for (char& c : str) {
       c = std::tolower(c);
   }
   ```

2. **Using `std::transform` with `std::tolower`**
   - Convert the entire string to lowercase in one line.
   ```cpp
   std::transform(str.begin(), str.end(), str.begin(),
                  [](unsigned char c) { return std::tolower(c); });
   ```

