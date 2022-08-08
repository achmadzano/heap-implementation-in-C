#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char drinkname[100];
    int quantity;
}drinks[100];

int heap[100];
int heapsize = 1;

void swap(int i, int j){
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void insertMaxHeap(int value){
    heap[heapsize] = value;
    int index = heapsize;
    while(index/2 > 0){
        if(heap[index] > heap[index/2]){
            swap(index, index/2);
        }
        index = index/2;
    }
    heapsize++;
}

void heapifyMax(int index){
    int leftIndex = index*2;
    int rightIndex = index*2+1;
    if(index*2 < heapsize){
        if(heap[leftIndex] > heap[index] || heap[rightIndex] > heap[index]){
            if(heap[leftIndex] > heap[rightIndex]){
                swap(leftIndex, index);
                heapifyMax(leftIndex);
            }
            else{
                swap(rightIndex, index);
                heapifyMax(rightIndex);
            }
        }
    }
}

int extractMax(){
    int max = heap[1];
    heap[1] = heap[heapsize-1];
    heapsize--;
    heapifyMax(1);
    return max;
}

void print(){
	puts("Top Sales:\n");
    for(int i = 1; i <=2; i++){
        if(drinks[1].quantity == heap[i]){
            printf("%d. %s %d\n", i, drinks[1].drinkname, drinks[1].quantity);
        }
        if(drinks[2].quantity == heap[i]){
            printf("%d. %s %d\n", i, drinks[2].drinkname, drinks[2].quantity);
        }
        if(drinks[3].quantity == heap[i]){
            printf("%d. %s %d\n", i, drinks[3].drinkname, drinks[3].quantity);
        }
        if(drinks[4].quantity == heap[i]){
            printf("%d. %s %d\n", i, drinks[4].drinkname, drinks[4].quantity);
        }
        if(drinks[5].quantity == heap[i]){
            printf("%d. %s %d\n", i, drinks[5].drinkname, drinks[5].quantity);
        }
        if(drinks[6].quantity == heap[i]){
            printf("%d. %s %d\n", i, drinks[6].drinkname, drinks[6].quantity);
        }
    }
}

int main(){
    int tc;
    int quantity;
    int bc = 0, mc = 0, pc = 0, bt = 0, cp = 0, cc = 0;
    char drinkcode[100];
    scanf("%d", &tc);
    for(int i = 0; i < tc; i++){
        scanf("%d", &quantity);
        scanf("%s", drinkcode);
        if(strcmp(drinkcode, "BC") == 0){
            bc+=quantity;
        }
        else if(strcmp(drinkcode, "MC") == 0){
            mc+=quantity;
        }
        else if(strcmp(drinkcode, "PC") == 0){
            pc+=quantity;
        }
        else if(strcmp(drinkcode, "BT") == 0){
            bt+=quantity;
        }
        else if(strcmp(drinkcode, "CP") == 0){
            cp+=quantity;
        }
        else if(strcmp(drinkcode, "CC") == 0){
            cc+=quantity;
        }
    }
    insertMaxHeap(bc);
    insertMaxHeap(mc);
    insertMaxHeap(pc);
    insertMaxHeap(bt);
    insertMaxHeap(cp);
    insertMaxHeap(cc);
    
    strcpy(drinks[1].drinkname, "Boba Coffee");
    drinks[1].quantity = bc;

    strcpy(drinks[2].drinkname, "Moccapucino");
    drinks[2].quantity = mc;

    strcpy(drinks[3].drinkname, "Pandan coffee");
    drinks[3].quantity = pc;

    strcpy(drinks[4].drinkname, "Boba Thai");
    drinks[4].quantity = bt;

    strcpy(drinks[5].drinkname, "Choco pandan");
    drinks[5].quantity = cp;

    strcpy(drinks[6].drinkname, "Cheese choco");
    drinks[6].quantity = cc;

    print();
}

