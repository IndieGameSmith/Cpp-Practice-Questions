#include <iostream> /* for std::cout */
#include <iomanip> /* for std::boolalpha() */
#include <algorithm> /* for std::reverse() */
#include <string> /* for std::string */

/**
 * \brief This Function checks if the given string is a palindrome
 *
 * \param str std::string const reference
 *
 * \return true if palindrome and false if not.
 */
bool isPalindrome(const std::string& str)
{
    /* Edge case handling for empty and one length std::string */
    if (str.empty() || str.length() == 1)
    {
        return true;
    }
    
    /* Two points representing left and right of str */
    int left = 0, right = str.length() - 1;
    
    /* Checks until left and right converge */
    while (left < right)
    {
        if (!isalnum(str[left]))
        {
            left++;
            continue;
        }
        
        if (!isalnum(str[right]))
        {
            right--;
            continue;
        }
        
        if (tolower(str[left]) != tolower(str[right]))
        {
            /* if not equal then returns false */
            return false;
        }
        
     left++;
     right--;
    }
    
    /* str is a palindrome so return true */
    return true;
}

/* int main() is the entry point of a programme */
int main()
{
    /* Creates a std::string str = "racecar" which is a palindrome */
    std::string str = "madam";
    
    /* As expected result is true */
    std::cout << "Is "<< str << " a palindrome: " << std::boolalpha << isPalindrome(str);
    /* OUTPUT : 
     * Is madam a palindrome: true
     */
     
    /* return 0 shows successful execution */
    return 0;
} 
