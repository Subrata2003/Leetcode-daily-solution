class Solution {

    public int[] shortestAlternatingPaths(int n, int[][] red, int[][] blue) {
            int ans[]= new int[n];
        List<List<List<Integer>>> list = new ArrayList<>();
        for(int i=0; i<n; i++)
        {
            List<List<Integer>> curr= new ArrayList<>();
            curr.add(new ArrayList<>()); curr.add(new ArrayList<>());
            list.add(curr);
        }
        for(int curr[]:red)
        {
            list.get(curr[0]).get(0).add(curr[1]);
        }
        
        for(int curr[]:blue)
        {
            list.get(curr[0]).get(1).add(curr[1]);
        }
        PriorityQueue<int[]> pq= new PriorityQueue<>((a,b)->a[0]-b[0]);
        pq.add(new int[]{0, 0, 0});
        Arrays.fill(ans, Integer.MAX_VALUE);
        boolean[][] visited= new boolean[n][2]; 
        
        while(!pq.isEmpty())
        {
        int size= pq.size();
            
        while(size-->0)
        { int curr[]=pq.remove();
         if(visited[curr[2]][1] && visited[curr[2]][0] )
             continue;
            
         ans[curr[2]]=Math.min(curr[0], ans[curr[2]]);
         if(curr[2]==0)
         {
             int t=0;
             List<Integer> list1 = list.get(curr[2]).get(t);
             for(int next:list1)
             {
                 int nt=1;
               
                     pq.add(new int[]{curr[0]+1, nt, next });
             }
             t=1;
             list1 = list.get(curr[2]).get(t);
             for(int next:list1)
             {
                 int nt=0;
                 
                     pq.add(new int[]{curr[0]+1, nt, next });
             }
             visited[0][1]=true;
             visited[0][0]=true;
         }
         else
         { 
             
             int t=curr[1]==1?1:0;
             if(visited[curr[2]][t]) continue;
             visited[curr[2]][t]=true;
             List<Integer> list1 = list.get(curr[2]).get(t);
             for(int next:list1)
             {
                 int nt=t==1?0:1;
                 
                     pq.add(new int[]{curr[0]+1, nt, next });
             }
         }
            
        }
        }
        for(int i=0; i<n; i++)
            if(ans[i]==Integer.MAX_VALUE)
                ans[i]=-1;
        return ans;
    }
   
    
    }
