#include <iostream>
#include <vector>
#include "28_Index_of_first_occurence/index_of_first_occurence.h"

void testRabinKarp(const std::string& text, const std::string& pattern) {
    std::cout << "Text: \"" << text << "\", Pattern: \"" << pattern << "\"\n";
    int index = index_of_first_occurence(pattern, text); // Call your Rabin-Karp function
    if (index != -1)
        std::cout << "✅ Found at index: " << index << "\n";
    else
        std::cout << "❌ Not found\n";
    std::cout << "----------------------\n";
}

int main() {
    // 1. Basic Match
    testRabinKarp("hello world", "world");

    // 2. Pattern at the Beginning
    testRabinKarp("abcde", "abc");

    // 3. Pattern at the End
    testRabinKarp("this is a test", "test");

    // 4. No Match
    testRabinKarp("abcdef", "xyz");

    // 5. Single-Character Match
    testRabinKarp("a", "a");

    // 6. Single-Character No Match
    testRabinKarp("a", "b");

    // 7. Pattern Longer Than Text
    testRabinKarp("short", "longer");

    // 8. Repeated Characters (Hash Collision Test)
    testRabinKarp("aaaaaa", "aaa");
    testRabinKarp("aaaaab", "aab");

    // 9. Large Input (Performance Test)
    std::string largeText(1000000, 'a');
    testRabinKarp(largeText, "aaa");

    // 10. Special Characters & Spaces
    testRabinKarp("hello, world!", ", wo");

    // 11. Case Sensitivity
    testRabinKarp("HelloWorld", "helloworld");

    // 12. Unicode Characters (UTF-8 Handling)
    testRabinKarp("こんにちは世界", "世界"); // Japanese "Hello World" -> "World"

    return 0;
}
