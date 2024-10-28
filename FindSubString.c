#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define HASH_MAP_SUBSTRING_SEARCH   (1)
#define CHARSET_SIZE                256  // Total number of ASCII characters

// Global hash maps for pattern and window
int pattern_map[CHARSET_SIZE] = {0};
int window_map[CHARSET_SIZE] = {0};

// Function to create a hash map for character frequency
void build_hash_map(const char *str, int len, int *hash_map) {
    for (int i = 0; i < len; i++) {
        hash_map[(unsigned char)str[i]]++;
    }
}

// Function to check if two hash maps are equal
bool are_equal() {
    for (int i = 0; i < CHARSET_SIZE; i++) {
        if (pattern_map[i] != window_map[i]) return false;
    }
    return true;
}

// Hash map-based substring search
int hash_map_substring_search(const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    if (m > n) return -1;  // Pattern longer than text

    // Reset the global hash maps
    memset(pattern_map, 0, sizeof(pattern_map));
    memset(window_map, 0, sizeof(window_map));

    // Create hash maps for pattern and initial window in text
    build_hash_map(pattern, m, pattern_map);
    build_hash_map(text, m, window_map);

    // Slide the window over the text
    for (int i = 0; i <= n - m; i++) {
        // If hash maps match, check character by character
        if (are_equal()) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) break;
            }
            if (j == m) return i;  // Substring found
        }

        // Update the hash map for the next window
        if (i < n - m) {
            window_map[(unsigned char)text[i]]--;         // Remove the first character of the current window
            window_map[(unsigned char)text[i + m]]++;     // Add the next character of the next window
        }
    }

    return -1;  // Substring not found
}


// Brute-force substring search
int find_substring(const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    // Iterate over the main string
    for (int i = 0; i <= n - m; i++) {
        int j;
        // Check for substring match
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        // If j reaches the length of pattern, we found a match
        if (j == m) {
            return i;  // Return the starting index of the substring
        }
    }
    return -1;  // Substring not found
}

int FindSubStringMain() {
    const char *text = "0x12345A78BC0DEF";
    const char *pattern = "A78";
    
    #if HASH_MAP_SUBSTRING_SEARCH
    int index = hash_map_substring_search(text, pattern);
    #else
    int index = find_substring(text, pattern);
    #endif

    if (index != -1) {
        printf("Substring found at index %d\n", index);
    } else {
        printf("Substring not found!\n");
    }


    return 0;
}
