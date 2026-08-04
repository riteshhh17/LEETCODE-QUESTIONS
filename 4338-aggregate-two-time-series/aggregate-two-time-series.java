class Solution {
    public List<List<Integer>> aggregateTimeSeries(int[][] series1, int[][] series2) {
        List<List<Integer>> ans=new ArrayList<>();
        int i=0;
        int j=0;
       // int v=0;
        //int w=0;
        while(i<series1.length || j<series2.length){
            if(j==series2.length || (i<series1.length && series1[i][0]<series2[j][0])){
                //v=series1[i][1];
                List<Integer> temp=new ArrayList<>();
                temp.add(series1[i][0]);
                int v=series1[i][1];
                int vv=(j<series2.length)?series2[j][1]:0;
                temp.add(v+vv);
                ans.add(temp);
                i++;
            }
            else if(i== series1.length || series2[j][0]<series1[i][0]){
               // w=series2[j][1];
                List<Integer> temp=new ArrayList<>();
                temp.add(series2[j][0]);
                  //int v=series[i][1];
                int v=(i<series1.length)?series1[i][1]:0;
                int vv=series2[j][1];
                temp.add(v+vv);
                ans.add(temp);
                j++;
            }
            else{
             //   v=series1[i][1];
               // w=series2[j][1];
                List<Integer> temp=new ArrayList<>();
                temp.add(series1[i][0]);
                temp.add(series1[i][1] +series2[j][1]);
                ans.add(temp);
                i++;
                j++;
            }
        }
        return ans;
    }
}