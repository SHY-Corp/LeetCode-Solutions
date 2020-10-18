class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        if(s.length()<p.length())
            return new ArrayList<Integer>();
        List<Integer> l = new ArrayList<Integer>();
        int[] a = new int[26];
        int[] b = new int[26];
        for(int i=0;i<26;i++)
        {
            a[i] = 0;
            b[i] = 0;
        }
        for(int i=0;i<p.length();i++){
            b[p.charAt(i)-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(i<p.length())
                a[s.charAt(i)-'a']++;
            else{
                boolean f = true;
                for(int j=0;j<26;j++){
                    if(a[j]!=b[j])
                    {
                        f = false;break;
                    }
                }
                if(f)
                {
                    l.add(new Integer(i-p.length()));
                }
                a[s.charAt(i-p.length())-'a']--;
                a[s.charAt(i)-'a']++;
            }
        }
        boolean f = true;
        for(int j=0;j<26;j++){
            if(a[j]!=b[j])
            {
                f = false;break;
            }
        }
         if(f)
         {
            l.add(new Integer(s.length()-p.length()));
         }
        return l;
    }
}