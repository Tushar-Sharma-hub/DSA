// 721. Accounts Merge
// Given a list of accounts where each element accounts[i] is a list of strings, 
// where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
// Now, we would like to merge these accounts. Two accounts definitely belong to the same person 
// if there is some common email to both accounts. Note that even if two accounts have the same name, 
// they may belong to different people as people could have the same name. A person can have any number of accounts initially, 
// but all of their accounts definitely have the same name.
// After merging the accounts, return the accounts in the following format: the first element of each account is the name, 
// and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.


//Steps:
//1.We will use DSU to join the accounts with common emails.
//2.We will use a map to store the email and the index of the account it belongs to.
//3.We will iterate through the accounts and for each email, we will check if it is already present in the map. 
//If it is not present, we will add it to the map with the index of the account. If it is present, 
//we will unite the current account with the account present in the map.
//4.After that we will iterate through the map and for each email, we will find the root of the account it belongs to 
//and add the email to the merged list of that account.
//5.Finally we will iterate through the merged list and for each account, we will sort the emails and 
//add the name of the account to the beginning of the list and add it to the answer list.

class DSU {
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }
    void unite(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string, int> emailMap;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailMap.find(email) == emailMap.end()) {
                    emailMap[email] = i;
                } else {
                    ds.unite(i, emailMap[email]);
                }
            }
        }
        vector<string> merged[n];
        for (auto it : emailMap) {
            int root = ds.find(it.second);
            merged[root].push_back(it.first);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (merged[i].empty()) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(), merged[i].begin(), merged[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};