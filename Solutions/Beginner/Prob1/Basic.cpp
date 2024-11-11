#include <iostream> /* for std::cout */
#include <iomanip> /* for std::boolalpha */
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
    /* Creates a copy of str for reversal as reversed_str */
    std::string reversed_str = str;
    
    /* Reverses reversed_str using std::reverse */
    std::reverse(reversed_str.begin(), reversed_str.end());
    
    /* Checks if str is equal to reversed_str */
    return reversed_str == str;
}

/* int main() is the entry point of a programme */
int main()
{
    /* Creates a std::string str = "racecar" which is a palindrome */
    std::string str = "racecar";
    
    /* As expected result is true */
    std::cout << "Is "<< str << " a palindrome: " << std::boolalpha << isPalindrome(str);
    /* OUTPUT : 
     * Is racecar a palindrome: true
     */
     
    /* return 0 shows successful execution */
    return 0;
}
