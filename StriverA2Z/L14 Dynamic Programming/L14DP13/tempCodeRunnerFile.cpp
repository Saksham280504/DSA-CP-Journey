    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    cout << maxChoco(0,0,c-1,r,c,grid,dp) << endl;