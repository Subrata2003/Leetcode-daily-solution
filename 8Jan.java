class Solution {
  public int maxPoints(int[][] points) {
    int N=points.length;
     if(N<2)
       return N;
    HashMap<Double,Integer> hm = new HashMap<>();
    int curr_max,vertical,same,horizontal;
    int max=0;
    for(int i=0;i<N;i++)
    {
       
        curr_max=vertical=same=horizontal=0;
        int x1=points[i][0];
        int y1=points[i][1];
        for(int j=i+1;j<N;j++)
        {
            int x2=points[j][0] ;
            int y2=points[j][1];
            if(x1==x2 &&y1==y2)
            {
                same++;
            }
            else if(x1==x2)
            {
                vertical++;
            }
            else if(y1==y2)
            {
            horizontal++;
            }
            else
            {
             double slope=(double)(y2-y1)/(x2-x1);
             if(!hm.containsKey(slope))
                 hm.put(slope,0);
               
             hm.put(slope,hm.get(slope)+1);
             curr_max=Math.max(curr_max,hm.get(slope));
            }
             curr_max=Math.max(curr_max,Math.max(vertical,horizontal));
        } 
        max=Math.max(max,curr_max+same+1);
        hm.clear();
    }
  
    
    return max;
}
}
