/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

int bs(int s, int e, MountainArray &mountainArr, int target ){ //2,3
    while(s <= e){
        int mid = s + (e-s)/2;
        if(mountainArr.get(mid) < target){
            s = mid + 1;
        }
        else if(mountainArr.get(mid) > target){
            e = mid-1;
        }
        else{
            return mid;
        }
        
    }
    return -1;
}
int ultabs(int s, int e, MountainArray &mountainArr, int target ){ //2,3
    while(s <= e){
        int mid = s + (e-s)/2;
        if(mountainArr.get(mid) < target){
            e = mid-1;
        }
        else if(mountainArr.get(mid) > target){
           s = mid + 1;
        }
        else{
            return mid;
        }
        
    }
    return -1;
}


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        //1st -> find mountain peek
        //2nd -> if target > peek, return -1.
        //3rd -> if target == peek, return peek
        //4th -> if target < peek, binary search for target.
        int n = mountainArr.length();
        int i = 0;
        int peek = 0;
        
       int f = 0;
       int g = n-1;
       while(f <= g){
           int mid = f + (g-f)/2;
           if(mountainArr.get(mid) < mountainArr.get(mid+1)){
               f = mid+1;
           }
           else{
               g = mid-1;
           }
       }
         peek = f;
        
        int peek_el =  mountainArr.get(peek);
        if(target>peek_el){
            return -1;
        }
        else if(target == peek_el){
            return peek;
        }
        
        int index = -1;

        // int rev_len = ((n-1)  - peek);
        // int x = peek+1;
        // int y = n-1;
        // while(x<=y){
        //     swap(mountainArr.get(peek),mountainArr.get(n+1));
        //     x++;
        //     y--;
        // }
        index =  ultabs(peek+1,n-1,mountainArr,target); //aate wakt reverse sorted rehta hai
        int index2 = bs(0,peek,mountainArr,target);
        // cout<<"index1 : "<<index<<" index2 : "<<index2;
if (index2 != -1 && (index == -1 || index2 < index)) {
    return index2;
} else if (index != -1) {
    return index;
}
return -1;
    }
};
