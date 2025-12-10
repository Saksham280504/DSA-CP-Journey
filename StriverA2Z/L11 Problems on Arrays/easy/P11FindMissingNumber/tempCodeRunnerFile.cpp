    int HashArr[n+1] = {0};

    for(int i=0; i<n-1; i++) {
        HashArr[arr[i]] = 1;
    }

    for(int i=1; i<n+1; i++){
        if(HashArr[i]==0) return i;
    }