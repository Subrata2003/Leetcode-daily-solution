class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<tuple<int,int>> items;
        for (int i = 0; i < size(scores); ++i) items.push_back({scores[i], ages[i]});
        sort(begin(items), end(items));

        map<int,int> res; res[0] = 0;
        for(auto [sc, ag] : items) {
            auto it0 = res.upper_bound(ag);
            int sc2 = sc + (--it0)->second;
            auto it = res.insert(it0, {ag, sc2});
            if (it->second < sc2) it->second = sc2;
            ++it;
            while (it != res.end() && it->second <= sc2) {
                auto it2 = it++;
                res.erase(it2);
            }
        }
        return res.rbegin()->second;
    }
};