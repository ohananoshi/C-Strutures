### C-Structures
```Author: Guilherme Arruda```
```Last updated: 08/oct/24```

#### Set of common data structures implementation for C.

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
    
    i8 : int8_t      u8 : uint8_t     f4 : float         s : char*    
    i16: int16_t     u16: uint16_t    f8 : double        NUL: NULL
    i32: int32_t     u32: uint32_t    f16: long double   DCT: DICT_t*
    i64: int64_t     u64: uint64_t                       LST: LIST_t*

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
