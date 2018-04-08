int length_str(char *a){
    int i = 0;
    while(a[i]!='\0'){
        i = i+1;
    }
    return i;
}

void copy_str(char *a, char *b){
    // copy a particular string from a to b 
    int i= 0;
    while(i <= length_str(a) ){
        b[i] = a[i];
        i++;
    }
}

int compare_str(char *a, char *b){
    int  flag = 1;
    if(length_str(a) == length_str(b))
    {
        int i =0;
        while (i <= length_str(a)){
            if (a[i]!= b[i]){
                flag = 0;
            }
            else{
                // skip
            }
            i++;
        }
    }
    else{
        flag =0;        
    }
    return flag;
}

unsigned int uniq(unsigned int n, char *a[], char *b[]){
    int i,j;
    if(n > 0){
        copy_str(a[0],b[0]);
        i =j =1;
    }
    else{
        i = j=0;
    }
    while(i<n){
        if (!compare_str(a[i], a[i-1])){
            copy_str(a[i],b[j]);
            j++;
        }
        else{
            // skip
        }
        i++;
    }
    return j;
}