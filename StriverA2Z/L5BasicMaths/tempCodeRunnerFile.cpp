void checkPrime(int n){
    int counter=0;
    for(int i=1; i*i<=n; i++){
        if(n%i==0) {
            counter++;
            if(n/i!=i) counter++;
        } 
    }
    if(counter==2) cout << n << " is prime " << endl;
    else cout << n << " is not prime " << endl;
}