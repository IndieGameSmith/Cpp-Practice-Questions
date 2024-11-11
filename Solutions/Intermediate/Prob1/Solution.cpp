#include <iostream>

// A Smart Pointer class to automatically manage memory
// It ensures that the memory pointed to by the pointer is deleted when the SmartPointer object goes out of scope.
template <typename T>
class SmartPointer
{
public:
    // Constructor to initialize the pointer
    SmartPointer(T* ptr = nullptr) : ptr_(ptr)
    {
        // If a pointer is provided, we store it.
    }

    // Destructor to deallocate the memory when the object is destroyed
    ~SmartPointer()
    {
        // Delete the pointer to avoid memory leaks.
        delete ptr_;
    }

    // Copy constructor to create a deep copy of the pointer
    SmartPointer(const SmartPointer& other)
    {
        // Create a new object and copy the value from the other pointer.
        ptr_ = new T(*other.ptr_);
    }

    // Assignment operator to assign one SmartPointer to another
    SmartPointer& operator=(const SmartPointer& other)
    {
        // Self-assignment check to avoid unnecessary deletion and allocation.
        if (this != &other)
        {
            // Delete the old pointer.
            delete ptr_;
            // Create a new object and copy the value from the other pointer.
            ptr_ = new T(*other.ptr_);
        }
        // Return a reference to the current object.
        return *this;
    }

    // Move constructor to transfer ownership of the pointer
    SmartPointer(SmartPointer&& other) noexcept
    {
        // Directly transfer the pointer without creating a copy.
        ptr_ = other.ptr_;
        // Set the other pointer to null to avoid double deletion.
        other.ptr_ = nullptr;
    }

    // Move assignment operator to transfer ownership of the pointer
    SmartPointer& operator=(SmartPointer&& other) noexcept
    {
        // Self-assignment check to avoid unnecessary operations.
        if (this != &other)
        {
            // Delete the old pointer.
            delete ptr_;
            // Directly transfer the pointer without creating a copy.
            ptr_ = other.ptr_;
            // Set the other pointer to null to avoid double deletion.
            other.ptr_ = nullptr;
        }
        // Return a reference to the current object.
        return *this;
    }

    // Dereference operator to access the pointed-to object
    T* operator->()
    {
        // Return the pointer to the object.
        return ptr_;
    }

    // Conversion operator to check if the pointer is valid
    explicit operator bool() const
    {
        // Return true if the pointer is not null.
        return ptr_ != nullptr;
    }

private:
    // The raw pointer to the object.
    T* ptr_;
};

int main()
{
    // Create a SmartPointer to an integer.
    SmartPointer<int> ptr1(new int(10));

    // Create a new SmartPointer and move the ownership of the pointer from ptr1 to ptr2.
    // This avoids unnecessary copying and potential memory leaks.
    SmartPointer<int> ptr2 = std::move(ptr1);

    // After the move, ptr1 no longer owns the pointer, so it's safe to go out of scope.
    // The destructor of ptr2 will automatically delete the integer.

    return 0;
}
