#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int lruPageReplacement(const vector<int>& referenceString, int capacity) {
    unordered_map<int, int> pageLastUsed;  // Maps page numbers to their last use index
    int pageFaults = 0;

    for (int i = 0; i < referenceString.size(); ++i) {
        int currentPage = referenceString[i];

        // Check if the page is in memory
        if (pageLastUsed.find(currentPage) != pageLastUsed.end()) {
            cout << "Page " << currentPage << " is already in memory (Page Hit)\n";

            // Update the last used index for the current page
            pageLastUsed[currentPage] = i;
        } else {
            // Page fault: page is not in memory
            ++pageFaults;

            // Check if the memory is full
            if (pageLastUsed.size() == capacity) {
                // Find the least recently used page
                int pageToReplace = INT_MAX;
                int leastRecentlyUsed = INT_MAX;

                for (const auto& entry : pageLastUsed) {
                    if (entry.second < leastRecentlyUsed) {
                        leastRecentlyUsed = entry.second;
                        pageToReplace = entry.first;
                    }
                }

                // Remove the least recently used page
                pageLastUsed.erase(pageToReplace);
                cout << "Page " << pageToReplace << " is replaced by Page " << currentPage << "\n";
            }

            // Add the current page to memory with its last used index
            pageLastUsed[currentPage] = i;
            cout << "Page " << currentPage << " is loaded into memory (Page Fault)\n";
        }
    }

    return pageFaults;
}

int main() {
    int capacity;
    cout << "Enter the capacity of the memory: ";
    cin >> capacity;

    int n;
    cout << "Enter the number of reference string elements: ";
    cin >> n;

    vector<int> referenceString(n);
    cout << "Enter the reference string elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> referenceString[i];
    }

    int pageFaults = lruPageReplacement(referenceString, capacity);

    cout << "Total Page Faults: " << pageFaults << endl;

    return 0;
}
