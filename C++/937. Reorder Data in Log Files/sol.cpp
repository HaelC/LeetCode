bool compareLog(string s1, string s2) {
    size_t space_index1 = s1.find(' '), space_index2 = s2.find(' ');
    string id1 = s1.substr(0, space_index1), id2 = s2.substr(0, space_index2);
    string log1 = s1.substr(space_index1 + 1), log2 = s2.substr(space_index2 + 1);

    if (isdigit(log1[0]) && isdigit(log2[0])) {
        return false;
    }
    if (isdigit(log2[0])) {
        return true;
    }
    if (isdigit(log1[0])) {
        return false;
    }
    return log1 < log2 || (log1 == log2 && id1 < id2);
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), compareLog);
        return logs;
    }
};