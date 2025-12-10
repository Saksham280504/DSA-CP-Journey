    int r;
    cin >> r;

    for(int c=1; c<=r; c++) {
        int value;
        value = nCr(r-1,c-1);
        cout << value << " ";
    }