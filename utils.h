#include <stdbool.h>
#include <string.h>

// strrev implementation. Since it's not available in linux.
// Source: https://stackoverflow.com/questions/8534274/is-the-strrev-function-not-available-in-linux/8534275#8534275
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

bool is_palindrome(char *str)
{
    // Creates a copy, since strrev modifies the string itself
    char aux_str[strlen(str) + 1];
    strcpy(aux_str, str);

    return strcmp(str, strrev(aux_str)) == 0;
}

// Source: https://www.geeksforgeeks.org/perfect-number/
bool is_perfect(long int n)
{
    // To store sum of divisors
    long int sum = 1;

    // Find all divisors and add them
    for (long int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i != n)
                sum = sum + i + n / i;
            else
                sum = sum + i;
        }
    }
    // If sum of divisors is equal to
    // n, then n is a perfect number
    if (sum == n && n != 1)
        return true;

    return false;
}
