#include <bits/stdc++.h>
using namespace std;



//O(sqrt(n))
void allFactors(int n, vector<int> &v)
{
    for (int i = 1; i*i <= n; i++)
    {
        if(n%i==0)  {
            v.push_back(i);
            if(n!=i*i) v.push_back(n/i);
        }
    }
}
int sumOfFactor(int n, vector<int> &v)
{
    allFactors(n,v);

    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum+=v[i];
    }
    return sum;    
}

//Sieve Of Eratosthenes

/* 
    NOTE:
 #  n*log(n) = 1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6........
 #  log(log(n)) = 1/2 + 1/3 + 1/5 + 1/7 + 1/11 ....
*/

const int N = 1e7+1;
vector<bool> isPrime(N,true);
vector<int> lowest_prime(N,0), highest_prime(N,0);

//O(n*log(log(n)))          
void sieveOfEratosthenes(int n)
{
    isPrime[0]=isPrime[1]=false;

    for (int i = 2; i <= n; i++)   //i*i<=n
    {
        if(isPrime[i])
        {
            highest_prime[i]=lowest_prime[i]=i;

            for (int j = 2*i; j <= n; j+=i)    //int j = i*i
            {
                isPrime[j]=false;
                highest_prime[j]=i;
                if(lowest_prime[j]==0)  lowest_prime[j]=i;  
            }
        }
    }
    
}

map<int,int> primeFactorCount;
void primeFactorization(int num)
{
    sieveOfEratosthenes(num);

    while(num>1)
    {
        int primeFactor = highest_prime[num];
        while(num%primeFactor==0)
        {
            primeFactorCount[primeFactor]++;
            num/=primeFactor;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    vector<int> v;

    // allFactors(10,v);
    // cout<<sumOfFactor(10,v)<<'\n';

    // sieveOfEratosthenes(31);
    // cout<<isPrime[11]<<'\n';

    primeFactorization(49);
    for (auto it = primeFactorCount.begin(); it!= primeFactorCount.end(); it++)
    {
        cout<<it->first<<' '<<it->second<<'\n';
    }
    



    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<' ';
    // }
    
}