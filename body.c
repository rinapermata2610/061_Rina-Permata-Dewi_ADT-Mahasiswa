#include "header.h"

void CreateList(List *L) {
    L->head = NULL;
}

bool isEmpty(List L) {
    return L.head == NULL;
}

void InsertSortedByNama(List *L, Mahasiswa data) {
    Node *baru = (Node *)malloc(sizeof(Node));
    baru->data = data;
    baru->next = NULL;

    if (isEmpty(*L) || strcmp(L->head->data.nama, data.nama) > 0) {
        baru->next = L->head;
        L->head = baru;
    } else {
        Node *temp = L->head;
        while (temp->next != NULL && strcmp(temp->next->data.nama, data.nama) < 0) {
            temp = temp->next;
        }
        baru->next = temp->next;
        temp->next = baru;
    }
}

void PrintList(List L) {
    if (isEmpty(L)) {
        printf("List kosong!\n");
        return;
    }
    Node *temp = L.head;
    while (temp != NULL) {
        printf("Nama: %s, Nilai UTS: %d\n", temp->data.nama, temp->data.nilaiUTS);
        temp = temp->next;
    }
}

int HitungElement(List L) {
    int count = 0;
    Node *temp = L.head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void CopyAtas70(List *L2, List L1) {
    Node *temp = L1.head;
    while (temp != NULL) {
        if (temp->data.nilaiUTS > 70) {
            InsertSortedByNama(L2, temp->data);
        }
        temp = temp->next;
    }
}

void RemoveDuplikat(List *L) {
    if (isEmpty(*L)) return;

    Node *curr = L->head;
    while (curr != NULL && curr->next != NULL) {
        if (strcmp(curr->data.nama, curr->next->data.nama) == 0) {
            Node *duplikat = curr->next;
            curr->next = curr->next->next;
            free(duplikat);
        } else {
            curr = curr->next;
        }
    }
}

void DeleteList(List *L) {
    Node *temp;
    while (L->head != NULL) {
        temp = L->head;
        L->head = L->head->next;
        free(temp);
    }
}

// Fungsi sorting berdasarkan Nama atau Nilai UTS
void Ascending(List *L, bool byNama) {
    if (isEmpty(*L) || L->head->next == NULL) return;
    
    for (Node *i = L->head; i->next != NULL; i = i->next) {
        for (Node *j = L->head; j->next != NULL; j = j->next) {
            bool condition = byNama 
                ? (strcmp(j->data.nama, j->next->data.nama) > 0) 
                : (j->data.nilaiUTS > j->next->data.nilaiUTS);
            if (condition) {
                Mahasiswa temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

void Descending(List *L, bool byNama) {
    if (isEmpty(*L) || L->head->next == NULL) return;
    
    for (Node *i = L->head; i->next != NULL; i = i->next) {
        for (Node *j = L->head; j->next != NULL; j = j->next) {
            bool condition = byNama 
                ? (strcmp(j->data.nama, j->next->data.nama) < 0) 
                : (j->data.nilaiUTS < j->next->data.nilaiUTS);
            if (condition) {
                Mahasiswa temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}