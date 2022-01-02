class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) 
	{
	    set<ull> s;
	    if(n<=5)
	        return n;
	    s.insert(1);
	    n--;
	    while(n)
	    {
	        auto it = s.begin();
	        ull x = *it;
	        s.erase(it);
	        s.insert((x*2));
	        s.insert((x*3));
	        s.insert((x*5));
	        n--;
	    }
	    return *s.begin();
	}
};
