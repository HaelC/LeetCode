class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> addresses;
        for (string email : emails) {
            string address = "";
            bool server = false;
            for (int i = 0; i < email.length();) {
                if (email[i] == '.' && !server) {
                    i++;
                }
                else if (email[i] == '@') {
                    server = true;
                    address += '@';
                    i++;
                }
                else if (email[i] == '+') {
                    while (email[i] != '@') {
                        i++;
                    }
                }
                else {
                    address += email[i++];
                }
            }
            // cout << address << endl;
            addresses.insert(address);
        }
        return addresses.size();
    }
};