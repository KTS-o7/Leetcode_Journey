// Better Solution

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> mergedArray;
        auto iter = 0;
        auto size1 = nums1.size(), size2 = nums2.size();
        while (iter != size1)
        {
            mergedArray.push_back(nums1[iter]);
            iter++;
        }
        iter = 0;
        while (iter != size2)
        {
            mergedArray.push_back(nums2[iter]);
            iter++;
        }
        sort(mergedArray.begin(), mergedArray.end());

        if (mergedArray.size() % 2 != 0)
            return (double)mergedArray[mergedArray.size() / 2];
        else
            return ((double)mergedArray[mergedArray.size() / 2] + (double)mergedArray[mergedArray.size() / 2 - 1]) / 2;
    }
};

// Initial Solution

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> mergedArray;
        // if(nums1.empty())
        // return (double) nums2[nums2.size()/2];
        //  if( nums2.empty())
        // return (double) nums1[nums1.size()/2];

        int size1 = nums1.size();
        int size2 = nums2.size();
        auto iter1 = 0, iter2 = 0;
        while (iter1 != size1 && iter2 != size2)
        {
            if (nums1[iter1] > nums2[iter2])
            {
                mergedArray.push_back(nums2[iter2]);
                iter2++;
            }

            else
            {
                mergedArray.push_back(nums1[iter1]);
                iter1++;
            }
        }

        while (iter1 != size1)
        {
            mergedArray.push_back(nums1[iter1]);
            iter1++;
        }
        while (iter2 != size2)
        {
            mergedArray.push_back(nums2[iter2]);
            iter2++;
        }

        // for(auto it:mergedArray)
        // cout<<it<<endl;
        if (mergedArray.size() % 2 != 0)
            return (double)mergedArray[mergedArray.size() / 2];
        else
            return ((double)mergedArray[mergedArray.size() / 2] + (double)mergedArray[mergedArray.size() / 2 - 1]) / 2;
    }
};
