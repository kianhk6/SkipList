
### Pointers and References

1. **Declaring a Pointer**
   ```cpp
   int* ptr; // Pointer to an int
   ```

2. **Declaring a Reference**
   ```cpp
   int& ref = someInt; // Reference to an int
   ```

3. **Dereferencing a Pointer**
   ```cpp
   int value = *ptr; // Access the value pointed by ptr
   ```

4. **Getting a Pointer from a Reference**
   ```cpp
   int* ptrFromRef = &ref; // Get pointer from reference
   ```

5. **Getting a Reference from a Pointer**
   ```cpp
   int& refFromPtr = *ptr; // Get reference from pointer
   ```

### Function Calls with References and Pointers

1. **Function Taking a Reference**
   ```cpp
   void funcRef(int& ref) { /* ... */ }
   funcRef(someInt); // Call with int variable
   ```

2. **Function Taking a Pointer**
   ```cpp
   void funcPtr(int* ptr) { /* ... */ }
   funcPtr(&someInt); // Call with address of int variable
   ```

3. **Reference to Pointer as Function Argument**
   ```cpp
   void funcRefToPtr(int*& refToPtr) { /* ... */ }
   int* somePtr = &someInt;
   funcRefToPtr(somePtr); // Call with pointer
   ```

4. **Calling Function with Reference Argument using Pointer**
   ```cpp
   void func(int& ref) { /* ... */ }
   int value = 5;
   int* ptr = &value;
   func(*ptr); // Dereference pointer to pass as reference
   ```

### Accessing Values

1. **Accessing Value through Pointer**
   ```cpp
   int val = *ptr; // Dereference pointer to access value
   ```

2. **Accessing Value through Reference**
   ```cpp
   int val = ref; // Directly use reference to access value
   ```

### Accessing Members of Class/Struct

1. **Accessing Member via Object Reference**
   ```cpp
   MyClass obj;
   MyClass& ref = obj;
   ref.memberFunc(); // Accessing member function
   int mem = ref.memberVar; // Accessing member variable
   ```

2. **Accessing Member via Object Pointer**
   ```cpp
   MyClass* ptr = &obj;
   ptr->memberFunc(); // Accessing member function
   int mem = ptr->memberVar; // Accessing member variable
   ```

3. **Accessing Member via Reference to Pointer**
   ```cpp
   void accessMember(MyClass*& refToPtr) {
       refToPtr->memberFunc(); // Accessing member function
       int mem = refToPtr->memberVar; // Accessing member variable
   }
   MyClass* somePtr = &obj;
   accessMember(somePtr);
   ```

### Dynamic Memory Allocation

1. **Allocating and Deallocating**
   ```cpp
   int* ptr = new int(5); // Allocation
   delete ptr;            // Deallocation
   ```

2. **Array Allocation**
   ```cpp
   int* arrayPtr = new int[10]; // Allocating array
   delete[] arrayPtr;           // Deallocating array
   ```

### Smart Pointers (Modern Memory Management)

1. **Unique Pointer**
   ```cpp
   #include <memory>
   std::unique_ptr<int> uniqPtr(new int(10));
   ```

2. **Shared Pointer**
   ```cpp
   std::shared_ptr<int> sharedPtr(new int(20));
   ```

3. **Weak Pointer**
   ```cpp
   std::weak_ptr<int> weakPtr = sharedPtr;
   ```


Sure, let's explore how to use `std::unique_ptr` and `std::shared_ptr` in C++, including accessing the managed object and passing these smart pointers to functions. Here's a detailed guide:

### Unique Pointer (`std::unique_ptr`)

1. **Include Memory Header**
   ```cpp
   #include <memory>
   ```

2. **Creating a Unique Pointer**
   ```cpp
   std::unique_ptr<int> uniqPtr = std::make_unique<int>(10); // Create a unique pointer
   ```

3. **Accessing the Managed Object**
   ```cpp
   int value = *uniqPtr; // Dereference to access the value
   int value2 = uniqPtr->method(); // Access method (if it's a pointer to an object)
   ```

4. **Passing Unique Pointer to a Function**
   - Pass by reference if you don't want to transfer ownership.
     ```cpp
     void useUniquePtr(const std::unique_ptr<int>& ptr) {
         int value = *ptr; // Use the unique pointer
     }
     useUniquePtr(uniqPtr);
     ```

   - Pass by value (move) if you need to transfer ownership.
     ```cpp
     void transferOwnership(std::unique_ptr<int> ptr) {
         int value = *ptr; // Ownership is transferred
     }
     transferOwnership(std::move(uniqPtr));
     ```

### Shared Pointer (`std::shared_ptr`)

1. **Creating a Shared Pointer**
   ```cpp
   std::shared_ptr<int> sharedPtr = std::make_shared<int>(20); // Create a shared pointer
   ```

2. **Accessing the Managed Object**
   ```cpp
   int sharedValue = *sharedPtr; // Dereference to access the value
   int sharedValue2 = sharedPtr->method(); // Access method (if it's a pointer to an object)
   ```

3. **Passing Shared Pointer to a Function**
   - Pass by value for shared ownership.
     ```cpp
     void useSharedPtr(std::shared_ptr<int> ptr) {
         int value = *ptr; // Shared ownership
     }
     useSharedPtr(sharedPtr);
     ```

   - Pass by reference to avoid increasing the reference count.
     ```cpp
     void useRefSharedPtr(const std::shared_ptr<int>& ptr) {
         int value = *ptr; // No change in ownership or reference count
     }
     useRefSharedPtr(sharedPtr);
     ```

4. **Copying a Shared Pointer**
   - Shared pointers can be copied to share ownership.
     ```cpp
     std::shared_ptr<int> anotherPtr = sharedPtr; // Both pointers now own the memory
     ```





