#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struktur data mahasiswa
typedef struct {
    char nama[50];
    int nilaiUTS;
} Mahasiswa;

typedef struct Node {
    Mahasiswa data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} List;

// Prototipe fungsi
void CreateList(List *L);
bool isEmpty(List L);
void InsertSortedByNama(List *L, Mahasiswa data);
void PrintList(List L);
int HitungElement(List L);
void CopyAtas70(List *L2, List L1);
void RemoveDuplikat(List *L);
void DeleteList(List *L);
void Ascending(List *L, bool byNama);
void Descending(List *L, bool byNama);

#endif