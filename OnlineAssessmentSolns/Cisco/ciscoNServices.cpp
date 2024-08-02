int getMinTime(int n, vector<int> cache) {
   int m = cache.size();
   vector<int> endTime(n+1,0);
   unordered_map<int, queue<int>>sq;
   for(int i =0;i<m;i++)
   {
       sq[cache[i]].push(i+1);
   }
   int tot = 0;
   while(true)
   {
       bool aq = true;
       for(int s = 1;s<=n;s++)
       {
           if(!sq[s].empty())
           {
               aq = false;
               
               int req = sq[s].front();
               sq[s].pop();
               
               if(endTime[s]>0)
                endTime[s]+=1;
            
               else
               endTime[s]+=tot+2;
           }
       }
       if(aq)
        break;
    tot+=1;
   }
   return tot;
}

