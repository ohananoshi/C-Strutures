### C-Structures
```Author: Guilherme Arruda```
```Last updated: 13/oct/24```

#### Set of common data structures implementation for C.

#### In development: Array suport.

- #### Header Flag 

    ```_C_STRUCTURES_HEADER_```

- #### Include
    - stdio
    - stdlib
    - stdint
    - string

- #### Datatypes

    - ```LIST_t```
    - ```DICT_t```

- #### s_types

    ```
    To generalize types support, this header use the below convention in functions passing the types using strings:
    
    i8 : int8_t      u8 : uint8_t     f32 : float         s : char*    
    i16: int16_t     u16: uint16_t    f64 : double        NUL: NULL
    i32: int32_t     u32: uint32_t    f128: long double   DCT: DICT_t*
    i64: int64_t     u64: uint64_t                        LST: LIST_t*

    ```

- #### common functions

    ```C
    uint8_t compare_value(void* a, void *b, const char* s_type)

    Compare if value a and b are equal.
    Note that the values must have the same type.

    Parameters:
        a     : first value
        b     : second value
        s_type: string of type

    Return:
        1 if is true.
        0 if is false.
    ```

    ```C
    void set_value(void** dest_var, const char* s_type, void* value)

    Assign a value with type s_type to dest_var.

    Parameters:
        dest_var : variable that will receive value (passed by reference)
        value    : value that will be assigned to dest_var
        s_type   : string of type

    Return:
        No return.
    ```

    ```C
    void print_value(void* value, const char* s_type)

    Print value according type.

    Parameters:
        value    : value that will be printed
        s_type   : string of type

    Return:
        No return.
    ```

- #### list functions

    ```C
    LIST_t* list_create()

    Create a empty list.
    ```

    ```C
    void list_free(LIST_t** list)

    Clear the list.
    ```

    ```C
    void list_push(LIST_t** dest_list, const char* element_type, void* data)

    Add a element at the start of list.

    Parameters:
        dest_list    : list that will receive the data (passed by reference)
        element_type : s_type string
        data         : value that will be added

    Return:
        No return.
    ```

    ```C
    void list_append(LIST_t** dest_list, const char* element_type, void* data)

    Add a element at the end of list.

    Parameters:
        dest_list    : list that will receive the data (passed by reference)
        element_type : s_type string
        data         : value that will be added

    Return:
        No return.
    ```

    ```C
    void list_insert(LIST_t** dest_list, const char* element_type, void* data, uint8_t pos)

    Add a element in the spcified position. (start with 0)

    Parameters:
        dest_list    : list that will receive the data (passed by reference)
        element_type : s_type string
        data         : value that will be added
        pos          : insertion position

    Return:
        No return.
    ```

    ```C
    void list_pop(LIST_t** src_list, LIST_t** dest, uint8_t pos)

    Remove a element in the spcified position and append it in dest list. (start with 0)

    Parameters:
        dest     : list that will receive the data (passed by reference)
        src_list : list that will loose the data (passed by reference)
        pos      : pop position

    Return:
        No return.
    ```

    ```C
    uint8_t list_copy(LIST_t** dest_list, LIST_t* src_list)

    Copy all src_list to dest_list.

    Parameters:
        dest_list : destination list (passed by reference)
        src_list  : origin list

    Return:
        Count of copied elements.
    ```

    ```C
    uint8_t list_extend(LIST_t** dest_list, LIST_t* src_list)

    Append all elements from src_list to dest_list.

    Parameters:
        dest_list : destination list (passed by reference)
        src_list  : origin list

    Return:
        Count of added elements.
    ```

    ```C
    uint8_t list_count(LIST_t* src_list, void* value)

    Count how many times value appears in the list.

    Parameters:
        value     : searched value
        src_list  : origin list

    Return:
        Count.
    ```

    ```C
    int8_t list_search(LIST_t* src_list, void* value)

    Find the position of a value in the list. (start with 0)

    Parameters:
        value     : searched value
        src_list  : origin list

    Return:
        Value position.
    ```

    ```C
    uint8_t list_len(LIST_t* src_list)

    Count the number of elements in a list.

    Parameters:
        src_list  : source list

    Return:
        Count.
    ```

    ```C
    void list_print(LIST_t* src_list)

    Print a list.

    Parameters:
        src_list  : source list

    Return:
        No return.
    ```

- #### dictionary functions

    ```C
    DICT_t* dict_create()

    Create a empty dictionary.
    ```

    ```C
    void dict_free(DICT_t** src_dict)

    Clear the dictionary.
    ```

    ```C
    void dict_print(DICT_t* src_dict)

    Print the dictionary.
    ```

    ```C
    void dict_update(DICT_t** dest_dict, const char* k_type, const char* v_type, void* key, void* value)

    If key already exists, the value will be updated. If not the key-value pair will be added. 

    Parameters:
        dest_dict : modifiable dictionary (passed by reference)
        k_type    : string of type
        v_type    : string of type
        key       : searched key
        value     : value that will be added

    Return:
        No return.
    ```

    ```C
    uint8_t dict_copy(DICT_t** dest_dict, DICT_t* src_dict)

    If src_dict have same keys of dest_dict, these key-value pairs will be updated. If not, the key-value pairs will be added.

    Parameters:
        dest_dict : modifiable dictionary (passed by reference)
        src_dict  : source dictionary

    Return:
        Count of modified values + added values.
    ```

    ```C
    uint8_t dict_get(DICT_t* src_dict, const char* k_type, void* key, void** dest_val)

    Search if especified key is in src_dict. If yes, copy the value to dest_val.

    Parameters:
        dest_val  : destination value (passed by reference)
        k_type    : string of type
        v_type    : string of type
        key       : searched key
        value     : value that will be added

    Return:
        Count of modified values + added values.
    ```

    ```C
    uint8_t dict_values(LIST_t** dest_list, DICT_t* src_dict)

    Append to dest_list all values from src_dict.

    Parameters:
        dest_list : Destination list (passed by reference)
        src_dict  : source dictionary

    Return:
        Count of values.
    ```

    ```C
    uint8_t dict_keys(LIST_t** dest_list, DICT_t* src_dict)

    Append to dest_list all keys from src_dict.

    Parameters:
        dest_dict : Destination list (passed by reference)
        src_dict  : source dictionary

    Return:
        Count of keys.
    ```

    ```C
    uint8_t dict_items(LIST_t** dest_list, DICT_t* src_dict)

    Append to dest_list all key-value pairs from src_dict.

    Parameters:
        dest_dict : Destination list (passed by reference)
        src_dict  : source dictionary

    Return:
        Count of items.
    ```

    ```C
    void dict_fromkeys(DICT_t** dest_dict, LIST_t* src_keys, void* value, const char* v_type)

    Add into dest_dict the src_keys with the same value. If any key in src_keys is the same in dest_dict, these will be updated.

    Parameters:
        dest_dict : modifiable dictionary (passed by reference)
        src_keys  : list with new keys
        v_type    : string of type
        value     : the value that will be assigned

    Return:
        No return.
    ```

    ```C
    void dict_popitem(LIST_t** dest_item, DICT_t** src_dict, char* k_type, void *key)

    If the searched key exists, copy the key-value pair to dest_item.

    Parameters:
        dest_item : destination list (passed by reference)
        src_dict  : source dict (passed by reference)
        k_type    : string of type
        key       : searched key

    Return:
        No return.
    ```