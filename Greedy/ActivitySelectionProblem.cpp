     bool comp(pair<int,int>&p1,pair<int,int>&p2)
    {
        return (p1.second<p2.second);
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
      // we sorted according to end meeting time only so that we will be able to get maximum of them.
        sort(v.begin(),v.end(),comp);
        int ans = 1;
        int last = v[0].second;
        for(int i=1;i<n;i++)
        {
            if(v[i].first > last) // as soon as one meeting ends we can start next one.
            {
                ans ++;
                last = v[i].second;
            }
        }
        return ans;
    }
