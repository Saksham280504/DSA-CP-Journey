    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            int sum = 0;
            for(int l=i; l<=j; l++) {
                sum += arr[l];
                if(sum == k) counter++;
            }   
        }
    }
