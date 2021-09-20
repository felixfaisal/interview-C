# Introduction to Pointers in C
- Memory allocation depends on compiler and architecture
`int - 4 bytes` 
`char - 1 byte` 
`float - 4 bytes`

**Pointers** - Variables that store address of another variable
```C++
    int a;
    int* p;
    p = &a;
    *p = 8;
    P = &a;
```

## Pointer Arithmetic 
```C++
    int * p = &a;
    p = p+1 
```
We can increment the pointer to the next address
This also quite dangerous

## Pointer Types, void pointer, pointer arithmetic
- Pointers are strongly typed

## Pointer to Pointer
```C 
    int **q;
    q = &p;
```

## Pointers as function arguments - Call by Reference 