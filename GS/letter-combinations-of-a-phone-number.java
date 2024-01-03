// Problem Link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
    public List<String> letterCombinations(String digits) {
      List<String> ans = permutations("", digits);
      if(ans.size()==1){
       return Collections.emptyList();
      }
      return ans;
    }
    static ArrayList<String> permutations(String p, String up){
        if(up.isEmpty()){
            ArrayList<String> list = new ArrayList<>();
            list.add(p);
            return list;
        }
        int digit = up.charAt(0)-'0';
        int start=0, end=0;
        if(digit>=2 && digit<=6){
             start=(digit-2)*3;
             end=(digit-1)*3;
        }
        if(digit==7){
         start=15;
             end=19;
        }
        if(digit==8){
             start=19;
             end=22;
        }
        if(digit==9){
              start=22;
             end=26;
        }
        ArrayList<String> left=new ArrayList();
        for(int i=start; i<end; i++){
            char ch = (char)('a'+(i));
            
        left.addAll(permutations(p+ch, up.substring(1)));
        }
        
        return left;
    }
}