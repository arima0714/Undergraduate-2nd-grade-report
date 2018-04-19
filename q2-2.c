#include <stdio.h>
#include <string.h>

char *findfirst(char*str, char*sub) {
    char *a, *b;
    if (*sub == 0) {
        return str;
    }
    for (; *str != 0; str += 1) {
        if (*str != *sub) {
            continue;
        }

        // add your code here
        // do not use any functions


        /*下記の3行は確認のためにプリントさせています(自分が書いたコードの最初)*/
        // printf("***ループが始まりました***\n");
        // printf("str = %s\n",str);
        // printf("sub = %s\n",sub);

        //printf("*str = %c\n",*str);
        //printf("*sub = %c\n",*sub);
        int answer;
        a = str;
        b = sub;
        for(; *b != 0; b++){
            //printf("for文開始\n");
            if((char)*a != (char)*b){
                // printf("b = %c\n",*b);
                // printf("a = %c\n",*a);
                //printf("@@break@@します\n");
                answer = 0;
                break;
            }else{
                // printf("@@breakしませんでした@@\n");
                // printf("b = %c\n",*b);
                // printf("a = %c\n",*a);
                answer = 1;
            }
            a++;
            //printf("for文終了\n");
        }
        
        /*ループが終了したかを確認しています(自分が書いたコードの最後)*/
        if(answer == 1){
            //printf("これが答えですよ〜　＝＞　");
            return str;
        }
        //printf("***一度ループが終了しました***\n");

    }
    return NULL;
}


int main(int argc, char *argv[]) {
    char *s1, *s2, *s;

    s1 = argv[1];
    s2 = argv[2];
    if((s=findfirst(s1, s2))) {
        printf("%s\n", s);
    }
    else {
        printf("\n");
    }
    return 0;
}
