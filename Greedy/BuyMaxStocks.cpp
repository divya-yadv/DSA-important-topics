int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int> > v;
 
    // Making pair of product cost and number
    // of day..
    for (int i = 0; i < n; ++i)
        v.push_back(make_pair(price[i], i + 1));   
 
    // Sorting the vector pair.
    sort(v.begin(), v.end());   
 
    // Calculating the maximum number of stock
    // count.
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += min(v[i].second, k / v[i].first);
        k -= v[i].first * min(v[i].second,
                               (k / v[i].first));
    }
 
    return ans;
}
