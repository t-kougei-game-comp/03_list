#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{
    struct list *next;
    int value;
}list;

int main(int argc, char *argv[]) 
{
    char str[6];
    list *header =  NULL;
    
    while(fgets(str, sizeof(str), stdin)){
        int n = atoi(str);
        if(n == 0){
            // リストを表示
            list *p = header;
            while(p){
                printf("%d", p->value);
                p = p->next;
                if(p){printf(",");}
            }
            printf("\n");
        }else if(n ==-1){
            // 先頭を削除
            list *p = header;
            if(p){
                printf("%d\n", p->value);
                header = p->next;
                free(p);
            }
        }else{
            // 要素を追加
            list *p = (list*)malloc(sizeof(list));
            if(p){
                p->next = header;
                p->value = n;
                header = p;
            }
        }
    }

    return 0;
}
