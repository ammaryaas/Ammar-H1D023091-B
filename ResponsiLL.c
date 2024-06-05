#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node *address;
typedef struct Mahasiswa {
    int NIM;
    char nama[50];
    float IPK;
} Mahasiswa;

typedef struct Node{
    Mahasiswa data;
    address next;
} Node;

address first = NULL;

address alokasi(int NIM, char* nama, float IPK){
    address newNode = (address)malloc(sizeof(Node));
    strcpy(newNode->data.nama, nama);
    newNode->data.NIM = NIM;
    newNode->data.IPK = IPK;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(address p){
    p->next = first;
    first = p;
}

void insertLast(address p){
    if(first == NULL){
        first = p;
    }else{
        address temp = first;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = p;
    }
}

void deleteFirst(){
    if(first != NULL){
        address temp = first;
        first=first->next;
        free(temp);
    }
}

void deleteLast(){
    if(first == NULL){
        printf("Kosong gabisa dihapus\n");
        return;
    }
    if(first->next == NULL){
        free(first);
        first = NULL;
        return;
    }
    address current = first;
    address prev = NULL;
    while(current->next != NULL){
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
}

void cetak(){
    address temp = first;
    while(temp != NULL){
        printf("NIM: %d, Nama: %s, IPK: %.2f\n", temp->data.NIM, temp->data.nama, temp->data.IPK);
        temp = temp->next;
    }
}

// void insertAscending(address p){

// }

void swapData(address node1, address node2){
    address hold;
    hold->data = node1->data;
    node1->data = node2->data;
    node2->data = hold->data;
}

void sortList(){
    address current = first->next;
    address prev = first;
    // address tmp = first;
    // while(tmp != NULL){  
        while(current != NULL){
            if(prev->data.NIM > current->data.NIM){
                swapData(current,prev);
            }
            prev = current;
            current = current->next;
        }
        // tmp = tmp->next;
    // }
}

void cetakBerdasarkanNIM(){
    sortList();
    address temp = first;
    while(temp != NULL){
        printf("NIM: %d, Nama: %s, IPK: %.2f\n", temp->data.NIM, temp->data.nama, temp->data.IPK);
        temp = temp->next;
    }
}

int main(){
    address current;
    current = alokasi(125,"Budi", 3.5);
    insertFirst(current);
    current = alokasi(128, "Siti", 3.7);
    insertLast(current);
    current = alokasi(126, "Andi", 3.8);
    insertLast(current);
    current = alokasi(130, "Desi", 3.2);
    insertFirst(current);
    current = alokasi(127, "Dedi", 3.9);
    insertLast(current);
    current = alokasi(129, "Saki", 3.4);
    insertLast(current);
    deleteLast();
    printf("Setelah dihapus satu dari belakang:\n");
    cetak();
    printf("\nSetelah data diurutkan berdasarkan NIM:\n");
    cetakBerdasarkanNIM();
    
    return 0;

}