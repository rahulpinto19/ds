/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* applyOperations(int* nums, int numsSize, int* returnSize)
{
int i,j;
for(i=0;i<numsSize-1;i++)
{
    if(nums[i]==nums[i+1])
    {
        nums[i]*=2;
        nums[i+1]=0;
    }
}
*returnSize=numsSize;
int pos=numsSize-1;
int k;
    for(k=0;k<10;k++)
   { for(i=0;i<numsSize;i++)
    {
        if(nums[i]==0)
        {for(j=i;j<numsSize-1;j++)
        {
            nums[j]=nums[j+1];
            
        }
        nums[j]=0;
        }
    }}
return nums;
}