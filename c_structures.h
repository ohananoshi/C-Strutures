/*  
    C-Structures:  Data structures implementation for C.

    Author: Guilherme Arruda

    Created in: 28/jul/24
    Last Updated: 08/oct/24
*/

//========================================== HEADERS ============================

#ifndef _C_STRUCTURES_HEADER_
#define _C_STRUCTURES_HEADER_

#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

//======================================== DATATYPES =============================


//char s_types[15][4] = {"u8","u16","u32","u64","i8","i16","i32","i64","f4","f8","f16","s","LST","DCT","NUL"};

typedef struct LIST_t{
    void *data;
    char element_type[4];
    struct LIST_t *next;
}LIST_t;

typedef struct DICT_t{
    void *key;
    void *value;
    struct DICT_t *next; 
    char* k_type;
    char* v_type;
}DICT_t;

//=============================== COMMON FUNCTIONS =================================    

uint8_t compare_value(void* a, void *b, const char* s_type){
    uint8_t size = 0;

    switch (s_type[0])
    {
    case 'i':
        sscanf(s_type,"d%hhu",&size);
        switch (size)
        {
        case 8:
            return (*(int8_t*)a == *(int8_t*)b) ? 1 : 0;
            break;

        case 16:
            return (*(int16_t*)a == *(int16_t*)b) ? 1 : 0;
            break;

        case 32:
            return (*(int32_t*)a == *(int32_t*)b) ? 1 : 0;
            break;

        case 64:
            return (*(int64_t*)a == *(int64_t*)b) ? 1 : 0;
            break;
        
        default:
            break;
        }
        break;

    case 'f':
        sscanf(s_type,"d%hhu",&size);
        switch (size)
        {
        case 8:
            return (*(double*)a == *(double*)b) ? 1 : 0;
            break;

        case 16:
            return (*(long double*)a == *(long double*)b) ? 1 : 0;
            break;

        case 4:
            return (*(float*)a == *(float*)b) ? 1 : 0;
            break;
        
        default:
            break;
        }
        break;

    case 'u':
        sscanf(s_type,"f%hhu",&size);
        switch (size)
        {
        case 8:
            return (*(uint8_t*)a == *(uint8_t*)b) ? 1 : 0;
            break;

        case 16:
            return (*(uint16_t*)a == *(uint16_t*)b) ? 1 : 0;
            break;

        case 32:
            return (*(uint32_t*)a == *(uint32_t*)b) ? 1 : 0;
            break;

        case 64:
            return (*(uint64_t*)a == *(uint64_t*)b) ? 1 : 0;
            break;
        
        default:
            break;
        }
        break;

    case 's':
        return (strcmp((char*)a,(char*)b) == 0) ? 1 : 0;
        break;

    case 'N':
        return (a == NULL && b == NULL) ? 1:0;
        break;
    
    case 'L':
        {
            LIST_t *tempa = (LIST_t*)a, *tempb = (LIST_t*)b;
            while(tempa != NULL){
            
                if(strcmp(tempa->element_type, tempb->element_type) != 0) return 0;
                if(compare_value(tempa->data, tempb->data, tempa->element_type) != 1) return 0;

                tempa = tempa->next;
                tempb = tempb->next;
            }
        }
        return 1;
        break;
    
    case 'D':
        {
            DICT_t *tempa = (DICT_t*)a, *tempb = (DICT_t*)b;
            while(tempa != NULL){
                if(strcmp(tempa->k_type, tempb->k_type) != 0 && strcmp(tempa->v_type, tempb->v_type) != 0) return 0;
                if(compare_value(tempa->key, tempb->key, tempa->k_type) != 1 && compare_value(tempa->value, tempb->value, tempa->v_type) != 1) return 0;

                tempa = tempa->next;
                tempb = tempb->next;
            }
        }
        return 1;
        break;
    
    default:
        break;
    }
}

void set_value(void** dest_var, const char* s_type, void* value){
    uint8_t size = 0;
    switch (s_type[0]){
        case 'u':
        sscanf(s_type,"%*[a-z]%hhu", &size);
            switch (size){
            case 8:
                (*dest_var) = malloc(sizeof(uint8_t));
                *(uint8_t*)(*dest_var) = *(uint8_t*)value;
                break;
            case 16:
                (*dest_var) = malloc(sizeof(uint16_t));
                *(uint16_t*)(*dest_var) = *(uint16_t*)value;
                break;
            case 32:
                (*dest_var) = malloc(sizeof(uint32_t));
                *(uint32_t*)(*dest_var) = *(uint32_t*)value;
                break;
            case 64:
                (*dest_var) = malloc(sizeof(uint64_t));
                *(uint64_t*)(*dest_var) = *(uint64_t*)value;
                break;
            
            default:
                break;
            }
        case 'i':
        sscanf(s_type,"%*[a-z]%hhu", &size);
            switch (size){
            case 8:
                (*dest_var) = malloc(sizeof(int8_t));
                *(int8_t*)(*dest_var) = *(int8_t*)value;
                break;
            case 16:
                (*dest_var) = malloc(sizeof(uint16_t));
                *(int16_t*)(*dest_var) = *(int16_t*)value;
                break;
            case 32:
                (*dest_var) = malloc(sizeof(int32_t));
                *(int32_t*)(*dest_var) = *(int32_t*)value;
                break;
            case 64:
                (*dest_var) = malloc(sizeof(int64_t));
                *(int64_t*)(*dest_var) = *(int64_t*)value;
                break;
            
            default:
                break;
            }
        case 'f':
        sscanf(s_type,"%*[a-z]%hhu", &size);
            switch (size){
            case 4:
                (*dest_var) = malloc(sizeof(float));
                *(float*)(*dest_var) = *(float*)value;
                break;
            case 8:
                (*dest_var) = malloc(sizeof(double));
                *(double*)(*dest_var) = *(double*)value;
                break;
            case 16:
                (*dest_var) = malloc(sizeof(long double));
                *(long double*)(*dest_var) = *(long double*)value;
                break;
            
            default:
                break;
            }
    
        case 's':
            (*dest_var) = malloc(strlen(s_type)*sizeof(uint8_t) + 1);
            strcpy((char*)(*dest_var), (char*)value);
            break;

        case 'L':
            (*dest_var) = malloc(sizeof(LIST_t*));
            (*dest_var) = (LIST_t*)value;
            break;

        case 'D':
            (*dest_var) = malloc(sizeof(DICT_t*));
            (*dest_var) = (DICT_t*)value;
            break;

        
        default:
            break;
    }
}

void list_print(LIST_t* src_list);

void print_value(void* value, const char* s_type){
    uint8_t size = 0;
    switch (s_type[0]){
        case 'u':
        sscanf(s_type,"%*[a-z]%hhu", &size);
            switch (size){
            case 8:
                printf("%hhu", *(uint8_t*)value);
                break;
            case 16:
                printf("%hu", *(uint16_t*)value);
                break;
            case 32:
                printf("%u", *(uint32_t*)value);
                break;
            case 64:
                printf("%lu", *(uint64_t*)value);
                break;
            
            default:
                break;
            }
        case 'i':
        sscanf(s_type,"%*[a-z]%hhu", &size);
            switch (size){
            case 8:
                printf("%hhd", *(uint8_t*)value);
                break;
            case 16:
                printf("%hd", *(uint16_t*)value);
                break;
            case 32:
                printf("%d", *(uint32_t*)value);
                break;
            case 64:
                printf("%ld", *(uint64_t*)value);
                break;
            
            default:
                break;
            }
        case 'f':
        sscanf(s_type,"%*[a-z]%hhu", &size);
            switch (size){
            case 4:
                printf("%f", *(float*)value);
                break;
            case 8:
                printf("%f", *(double*)value);
                break;
            case 16:
                printf("%Lf", *(long double*)value);
                break;
            
            default:
                break;
            }
    
        case 's':
            printf("%s", (char*)value);
            break;

        case 'L':
            list_print((LIST_t*)value);
            break;

        default:
            break;
    }
}

//======================================== LIST FUNCTIONS ==========================

LIST_t* list_create(){

    LIST_t *list = (LIST_t*)calloc(1, sizeof(LIST_t));
    strcpy(list->element_type, "");
    list->data = NULL;
    list->next = NULL;
    return list;
}

void list_print(LIST_t* src_list){
    printf("[");
    while(src_list != NULL){
        print_value(src_list->data, src_list->element_type);
        printf(",");
        src_list = src_list->next;
    }
    printf("\b]");
}

void list_free(LIST_t** list){

    if(list == NULL || *list == NULL) return;

    LIST_t *current, *next;
    current = *list;

    while(current != NULL){
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    *list = NULL;
}

void list_push(LIST_t** dest_list, const char* element_type, void* data){

    if((*dest_list) == NULL){
        set_value(&(*dest_list)->data, element_type, data);
        strcpy((*dest_list)->element_type, element_type);
        return;
    }

    if(strcmp((*dest_list)->element_type, "") == 0){
        set_value(&(*dest_list)->data, element_type, data);
        strcpy((*dest_list)->element_type, element_type);
        return;
    }

    LIST_t *new_node = list_create(element_type, data);
    strcpy(new_node->element_type, element_type);
    set_value(&new_node->data, element_type, data);
    new_node->next = *dest_list;
    *dest_list = new_node;
}

void list_append(LIST_t** dest_list, const char* element_type, void* data){

    if((*dest_list) == NULL){
        (*dest_list) = list_create();
        set_value(&(*dest_list)->data, element_type, data);
        strcpy((*dest_list)->element_type, element_type);
        return;
    }

    LIST_t *last = *dest_list;
    while(last->next != NULL) last = last->next;

    if(strcmp(last->element_type, "") == 0){
        set_value(&last->data, element_type, data);
        strcpy(last->element_type, element_type);
        return;
    }
    
    last->next = list_create();
    last = last->next;
    set_value(&last->data, element_type, data);
    strcpy(last->element_type, element_type);
}

uint8_t list_copy(LIST_t** dest_list, LIST_t* src_list){
    uint8_t count = 0;

    if(src_list == NULL){
        *dest_list = NULL;
        return count;
    }

    while(src_list != NULL){
        list_append(dest_list, src_list->element_type, src_list->data);
        src_list = src_list->next;
        count++;
    }

    return count;
}

uint8_t list_extend(LIST_t** dest_list, LIST_t* src_list){
    LIST_t *temp = *dest_list;
    uint8_t count = 0;

    while(temp->next != NULL) temp = temp->next;

    while (src_list != NULL){
        list_append(dest_list, src_list->element_type, src_list->data);
        src_list = src_list->next;
        count++;
    }

    return count;
}

void list_insert(LIST_t** dest_list, const char* element_type, void* data, uint8_t pos){
    LIST_t *temp = (*dest_list);
    uint8_t count = 0;

    if(*dest_list == NULL){
        //(*dest_list) = list_create();
        for(uint8_t i = 0; i < pos; i++){
            list_append(dest_list, "NUL", NULL);
        }
        list_append(dest_list, element_type, data);
        return;
    }

    if(pos == 0){
        list_push(dest_list, element_type, data);
        return;
    }

    while(temp->next != NULL && count <= pos - 2){
        count++;
        temp = temp->next;
    }

    if(count < pos - 1){
        while(count < pos - 1){
            list_append(dest_list, "NUL", NULL);
            count++;
        }

        list_append(dest_list, element_type, data);
        return;
    }

    if(count == pos - 1){

        list_push(&temp->next, element_type, data);
        return;
    }

}

void list_pop(LIST_t** src_list, LIST_t** dest, uint8_t pos){
    uint8_t count = 0;

    if(*src_list == NULL) return;

    if(pos == 0){
        list_append(dest, (*src_list)->element_type, (*src_list)->data);
        LIST_t* tmp = (*src_list);
        *src_list = (*src_list)->next;

        tmp->next = NULL;
        list_free(&tmp);
        return;
    }

    LIST_t* current = (*src_list), *previous = NULL;
    while(count < pos){
        previous = current;
        current = current->next;
        if(current == NULL && count < pos){
            perror("Out of range.");
            exit(EXIT_FAILURE);
        }
        count++;
    }

    list_append(dest, current->element_type, current->data);
    if(current->next == NULL){ //last pos
        list_free(&current);
        previous->next = NULL;
        return;
    }
    else{//midle pos
        previous->next = current->next;
        current->next = NULL;
        list_free(&current);
        return;
    }
}

uint8_t list_count(LIST_t* src_list, void* value){
    uint8_t count = 0;

    while(src_list != NULL){
        if(compare_value(src_list->data, value, src_list->element_type)) count++;
        src_list = src_list->next;
    }

    return count;
}

int8_t list_index(LIST_t* src_list, void* value){
    int8_t count = 0;

    while(src_list != NULL){
        if(compare_value(src_list->data, value, src_list->element_type)) return count;
        count++;
    }

    return -1;
}

uint8_t list_len(LIST_t* src_list){
    uint8_t count = 0;

    while(src_list != NULL){
        count++;
        src_list = src_list->next;
    }

    return count;
}
#endif //c_structures end