package edu.neu.coe.info6205.union_find;

import java.util.Random;

public class HWQUPC_Solution {
    public static boolean are_allConnected(UF_HWQUPC Present_Uf,int n){
        int tempvar;
        int fvar=Present_Uf.find(0);
        for(int i=1;i<n;i++){
           tempvar = Present_Uf.find(i);
           if(tempvar!=fvar)return false;


        }
        return true;
    }
    public static long count(int n){
        int rand_int1;
        int rand_int2;
        Random rand = new Random();
            UF_HWQUPC Present_Uf = new UF_HWQUPC(n, true);
            int number_of_Connections = 0;

            while (!are_allConnected(Present_Uf,n)) {
                    rand_int1 = rand.nextInt(n);
                    rand_int2 = rand.nextInt(n);
                    if (!Present_Uf.connected(rand_int1, rand_int2)) {
                        Present_Uf.union(rand_int1, rand_int2);
                        number_of_Connections++;
                    }
                }

        return number_of_Connections;
    }
    public static void main(String[] args){
        int count=15;
        int n_val=10;
        while(count!=0){
            System.out.println( n_val +","+ count(n_val) );
            count--;
            n_val*=2;
        }


    }

}
