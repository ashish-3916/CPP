void sieve()
{// O(n log log n )
    for(int i = 2 ; i*i <= 50000 ; i++)
    {
        if(check[i])
        {
            //prime.push_back(i);
            for(int j = i*i ; j <= 50000; j+=i)
                check[j]=false;
        }
    }
     for(int i=2; i<=50000 ;i++)
        {
            if(check[i]) prime.push_back(i);
        }
    
}
