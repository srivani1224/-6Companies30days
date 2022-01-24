/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int k, MountainArray &v) {
        int n = v.length();
        int peak = 0;
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int y = v.get(mid);
            if(v.get(mid+1) < y)
            {
                peak = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        //cout<<peak<<endl;
        l = 0;
        r = peak - 1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int y = v.get(mid);
            if(y == k)
                return mid;
            else if(y > k)
                r = mid - 1;
            else
                l = mid + 1;
        }
        l = peak;
        r = n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int y = v.get(mid);
            if(y == k)
                return mid;
            else if(y < k)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
