/********************************************************************************** 
* 
* Given an array S of n integers, find three integers in S such that the sum is 
* closest to a given number, target. Return the sum of the three integers. 
* You may assume that each input would have exactly one solution.
* 
*     For example, given array S = {-1 2 1 -4}, and target = 1.
* 
*     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define INT_MAX 2147483647
//solution:  http://en.wikipedia.org/wiki/3SUM
//the idea as blow:
//  1) sort the array.
//  2) take the element one by one, calculate the two numbers in reset array.
//
//notes: be careful the duplication number.
//
// for example:
//    [-4,-1,-1,1,2]    target=1
// 
//    take -4, can cacluate the "two number problem" of the reset array [-1,-1,1,2] while target=5
//    [(-4),-1,-1,1,2]  target=5  distance=4
//           ^      ^ 
//    because the -1+2 = 1 which < 5, then move the `low` pointer(skip the duplication)
//    [(-4),-1,-1,1,2]  target=5  distance=2
//                ^ ^ 
//    take -1(skip the duplication), can cacluate the "two number problem" of the reset array [1,2] while target=2
//    [-4,-1,(-1),1,2]  target=2  distance=1
//       

int threeSumClosest(vector<int>& num, int target)
{
    sort(num.begin(), num.end());

    int n = num.size();
    int distance = INT_MAX;
    int result;

    for (int i = 0; i < n-2; i++)
    {
        //skip the duplication
        if (i > 0 && num[i-1] == num[i])
            continue;
        int a = num[i];
        int low  = i + 1;
        int high = n - 1;
        //convert the 3sum to 2sum problem
        while (low < high)
        {
            int b = num[low];
            int c = num[high];
            int sum = a + b + c;
            if (0 == sum - target)
            {
                //got the final soultion
                return target;
            }
            else
            {
                //tracking the minmal distance
                if (abs(sum - target) < distance)
                {
                    distance = abs(sum - target);
                    result = sum;
                }

                if (sum - target > 0)
                {
                    while (high > 0 && num[high] == num[high-1])
                        high--;
                    high--;
                }
                else
                {
                    while (low < n && num[low] == num[low+1])
                        low++;
                    low++;
                }
            }
        }
    }
    return result;
}

int main()
{
    int a[] = {-1, 2, 1, -4};
    vector<int> n(a, a+sizeof(a)/sizeof(int));
    int target = 1;
    cout << threeSumClosest(n, target) << endl;
    return 0;
}
