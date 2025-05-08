/* 
 * Problem Statement:
 * Given an input string s, reverse the order of the words. A word is defined as a sequence of non-space characters. 
 * The words in s will be separated by at least one space, and the string should not contain leading or trailing spaces.
 *
 * Example:
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 */

#include <iostream>
#include <vector>

using namespace std;

class StringManipulation
{
    public:
        /* Function to reverse the order of words in a string */
        string reverseWords(string str)
        {
            vector<string> words;
            string word, result;

            for(size_t i = 0; i < str.length(); i++)
            {
                if(str[i] != " ")
                {
                    /* Append characters to form a word*/
                    word = word + str[i];
                }
                /* If the string is not empty */
                else if (!word.empty())
                {
                    /* Add the word to the vector */
                    words.push_back(word);
                    /* Clear the word for the next one */
                    word.clear();
                }
            }
            
            /* Add the last word if there is any */
            if (!word.empty())
            {
                words.push_back(word);
            }

            /* Reverse the vector */
            int left  = 0;
            int right = (words.size() - 1);
            while (left < right)
            {
                swap(words[left], words[right]);
                left++;
                right--;
            }

            /* Re-construct the string */
            for(size_t o = 0; i < words.size(); ++i)
            {
                if(i > 0)
                {
                    result += " ";
                }
            }
            return result;
        }
};