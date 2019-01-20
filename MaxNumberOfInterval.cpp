

#include <iostream>
#include <vector>

using namespace std;
int findMax(int arr[], int n) {
    int max = arr[0];
    int indexMax = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            indexMax = i;
        }
    }
    return indexMax;
}
bool isOverlap(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first && b.first < a.second)
        return true;
    else if (b.first < a.first && a.first < b.second)
        return true;
    return false;
}
int main()
{
    vector<pair<int, int>> v = {{1, 2}, {3, 8}, {2, 5}, {4, 8}, {5, 9}};
    int count[v.size()] = {0};
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (isOverlap(v[i], v[j])) {
                    count[i]++;
                    count[j]++;
                }
        }
    }
    for (int i = 0; i < v.size(); i++)
        cout << count[i] << " ";
        cout << endl;
    bool eraseElement[v.size()] = {false};
    while(true) {
        int indexMax = findMax(count, v.size());
        if (count[indexMax] > 0) {
            count[indexMax] = 0;
            eraseElement[indexMax] = true;
            for (int i = 0; i < v.size(); i++)
                if (isOverlap(v[i], v[indexMax]) && i != indexMax)
                    count[i]--;
        }
        else
            break;
    }
    for (int i = 0; i < v.size(); i++) {
        if (eraseElement[i] == false) {
            cout << v[i].first << v[i].second << endl;
        }
    }

    return 0;
}
