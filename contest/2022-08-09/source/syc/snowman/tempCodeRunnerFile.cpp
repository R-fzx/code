<=r)
    {
        int mid=l+r>>1;
        if(check(mid))
            l=mid+1,ans=mid;
        else
            r=mid-1;
    }