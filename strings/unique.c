/* IsUnique - Implement an algorithm to determine if a string has all unique characters, and not use any additional data structures */ 
/* PsuedoCode
START
    int isUnique(String string):
        int[128] arr; 
        for x in string: 
            if int[int(x)].exists():
                return -1 
            else: 
                int[int(x)] = 1 
        return 0
END 
Time Complexity: 0(N)
*/ 
// FIXME: Unable to iterate through the string properly 
#include<stdio.h>
int isUnique(char str_name[]){
    int alphabet_array[128] = {0};
    int len = sizeof(&str_name)/sizeof(char);
    for(int i=0; i<len;i++){
        printf("%d \n", str_name[i]);
        if (str_name[i] == 0){
            continue;
        }
        else if(alphabet_array[str_name[i]] == 1){
            return -1; 
        }
        else{
            alphabet_array[str_name[i]] = 1;
        }
    }
    return 0;
}
void main(){
    int size = 10; 
    char str_name[] = "faisal";
    int result = isUnique("abcde");
    printf("%d", result);
    // printf("Hello World %s %d",str_name,isUnique("Faisal"));
}
