class Pascal {

    public static int[] triangle(int n) {

        if(n == 1)
            return new int[]{1};

        int[] other = triangle(n-1);
        int[] result = new int[n];
        result[0] = 1;
        
        for(int i = 1; i < n-1; i++)
            result[i] = other[i] + other[i-1];
        
        result[n-1] = 1;
        
        return result;
    }
}