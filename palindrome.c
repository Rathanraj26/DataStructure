bool isPalindrome(int x){
    long int a=0;
    long int i=x;
    if(x<0)
    return false;
    else{
        while(x>0){
        a=a*10 + x%10;
        x=x/10;
        }
        if(a==i)
        return true;
        else
        return false;
    }
}
