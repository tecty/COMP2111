unsigned int uniq(unsigned int n, char *a[], char *b[]){
    int i,j,k;
    // store the length of String
    int aLength, bLength,flag;
    if(n > 0){
        aLength= 0;
        
        while(a[0][aLength]!='\0'){
            aLength = aLength+1;
        }
        
        k= 0;
        while(k <= aLength ){
                b[0][k] = a[0][k];
                k= k+1;
        }
        i =j =1;
    }
    else{
        i = j=0;
    }
    while(i<n){
        aLength =bLength = 0;
        while(a[i][aLength]!='\0'){
            aLength = aLength+1;
        }
        while(a[i-1][bLength]!='\0'){
            bLength = bLength+1;
        }
        flag = 1;
        if(aLength == bLength)
        {
            k =0;
            while (k <= aLength){
                if (a[i][k]!= a[i-1][k]){
                    flag = 0;
                }
                else{
                    // skip
                }
                k= k+1;
            }
        }
        else{
            flag =0;
        }
        if (!flag){
            k= 0;
            while(k <= aLength){
                b[j][k] = a[i][k];
                k= k+1;
            }
            j++;
        }
        else{
            // skip
        }
        i++;
    }
    return j;
}