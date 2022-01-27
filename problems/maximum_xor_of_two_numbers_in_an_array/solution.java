class Solution {
    public int findMaximumXOR(int[] nums) {
        int res = 0;
        int mask = 0;

        for(int i = 30; i >= 0; i--){
            mask = mask | (1 << i);

            HashSet<Integer> set = new HashSet<>();

            for(int num : nums)
                set.add(num & mask);
            
            int targetMax = res | (1 << i);
            for(Integer prefix : set){
                int temp = prefix ^ targetMax;

                if(set.contains(temp)){
                    res = targetMax;
                    break;
                }
            }
        }

        return res;
    }
}

