string isPossible(int a,int b,int c,int d){

    while(c>=a && d>=b){

        if(c==a && d==b)
            return "Yes";

        if(c>d)
            c-=d;
        else
            d-=c;
    }

    return "No";
}
