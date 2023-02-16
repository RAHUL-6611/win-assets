class Solution 
{
    //Function to find a continuous sub-array which adds up to a given number.
    subarraySum(arr, n, s)
    {
        var start=0,i;
        var end = -1
        let sum=0
        for (i=0;i<n;i++){
            sum+=arr[i]

            while (sum>s && start<i){
                  sum -= arr[start];
                  start++
              }
            if (sum == s){
                end = i;
                break;
            }
        }
        return [start,end]
      
    }
}
const a = new Solution();
console.log(a.subarraySum([2,3,4,40,0,5],8,49))


       let start = 0;
        let end = -1
        let sum=0
        for(var i=0;i<=n;i++) {
            sum+=arr[i];
            while(sum>s && start<i) {
                // console.log('inside')
                sum-=arr[start];
                start++;
                // console.log('sum=', sum)
            }
            console.log('ouside sum=', sum, 'start=', start,"index=",i)
            if(sum==s) {
                end = i;
                break;
            }
        }
        if(end===-1) {
            return [-1]
        }
        return [start+1, end+1]