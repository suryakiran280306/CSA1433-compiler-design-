#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100


typedef struct {
    char name[50];
    int value;      
} SymbolEntry;


typedef struct {
    SymbolEntry* entries[TABLE_SIZE]; 
} SymbolTable;


unsigned int hash(const char* name) {
    unsigned int hashValue = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        hashValue = hashValue * 31 + name[i];
    }
    return hashValue % TABLE_SIZE;
}


SymbolTable* createSymbolTable() {
    SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->entries[i] = NULL;
    }
    return table;
}


void insertSymbol(SymbolTable* table, const char* name, int value) {
    unsigned int index = hash(name);

    
    SymbolEntry* newEntry = (SymbolEntry*)malloc(sizeof(SymbolEntry));
    strcpy(newEntry->name, name);
    newEntry->value = value;

    
    table->entries[index] = newEntry;
    printf("Inserted: %s -> %d\n", name, value);
}


SymbolEntry* searchSymbol(SymbolTable* table, const char* name) {
    unsigned int index = hash(name);
    SymbolEntry* entry = table->entries[index];

    if (entry != NULL && strcmp(entry->name, name) == 0) {
        return entry;
    }
    return NULL; 
}


void deleteSymbol(SymbolTable* table, const char* name) {
    unsigned int index = hash(name);
    SymbolEntry* entry = table->entries[index];

    if (entry != NULL && strcmp(entry->name, name) == 0) {
        free(entry);
        table->entries[index] = NULL;
        printf("Deleted: %s\n", name);
    } else {
        printf("Symbol not found: %s\n", name);
    }
}

void displaySymbolTable(SymbolTable* table) {
    printf("Symbol Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        SymbolEntry* entry = table->entries[i];
        if (entry != NULL) {
            printf("%s -> %d\n", entry->name, entry->value);
        }
    }
}


int main() {
    SymbolTable* table = createSymbolTable();

    
    insertSymbol(table, "x", 10);
    insertSymbol(table, "y", 20);
    insertSymbol(table, "z", 30);

    
    SymbolEntry* entry = searchSymbol(table, "y");
    if (entry != NULL) {
        printf("Found: %s -> %d\n", entry->name, entry->value);
    } else {
        printf("Symbol not found.\n");
    }

    
    deleteSymbol(table, "y");

    
    displaySymbolTable(table);

    
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->entries[i] != NULL) {
            free(table->entries[i]);
        }
    }
    free(table);

    return 0;
}
