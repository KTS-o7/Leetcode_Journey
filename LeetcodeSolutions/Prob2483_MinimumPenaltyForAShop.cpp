


class Solution {
public:
    int bestClosingTime(string customers) {
        int i,maxProfit=0,Profit=0,Ind=0,maxInd=0;
        for(i=0;i<customers.size();i++)
        {
            if(customers[i]=='Y')
            {
                Profit+=1;
                Ind++;
            }

            else
            {
                Profit-=1;
                Ind--;
            }

            if(maxProfit<Profit)
            {
                maxProfit=Profit;
                maxInd = i;
            }
        }
        if(maxProfit<=0) //edge case
        return 0;

        return maxInd+1;
        
    }
};