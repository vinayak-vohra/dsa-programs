# [USICT](http://www.ipu.ac.in/usict) MCA(SE) 1st Semester

## Data Structures and Algorithms Lab IT 663

### Setting up
Let's start by configuring C environment for building and debugging c files.

#### Compiler ?
C is a compiled language meaning the source code must be compiled before it can be run.

To check if you have a compiler, use the following command: 

```
gcc --version 
```

If you do not have a compiler, follow these steps:

1. Firstly, install [MSYS2](https://github.com/msys2/msys2-installer/releases/download/2023-05-26/msys2-x86_64-20230526.exe). It will provide the latest builds for mingw-64.

2. Run the installer and follow the steps of the installation wizard.

3. Run these commands in the newly opened MSYS2 shell: 
```
pacman -S mingw-w64-x86_64-gcc
```
`gcc` i.e GNU Compiler Collection contains compiler for many languages such as C, C++, Ada, Go etc. as well as libraries for these languages.

```
pacman -S mingw-w64-x86_64-gdb
```
`gdb` i.e GNU Debugger is a portable debugger which, ofcourse, helps in debugging your code.

4. Almost done... don't forget to add the **mingw bin** folder as an environment variable. 
In most cases it will be `c:\msys2\mingw64\bin`.

5. Finally, confirm that everything is working properly by [checking for compiler](#compiler)
#### Compiling ...
This is the basic template to compile a C file: 
```
gcc <file-name>.c -o <file-name>
```
Let's quickly understand what is happening here:
1. `gcc` : Compiler command.
2. `<file-name>.c`: The file to be compiled.
3. `-o <file-name>`: Output file name (default: `a.out`). [see all flags](https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html)

#### Executing

- If there are some errors, then debug the errors before compiling again because sadly errors don't vanish by themselves.

- If there are no errors in your code, then an executable `.exe` file will be generated by the name you provided or by `a.out` if you were lazy to do so.

- Open a new terminal window (that much you should know how to do), and type the output executable file name. If on bash, add `./` before file name.

- Voila~ enjoy the output of your efforts.

### Programs List: 

1. Implement operations on an `array`:
    - Traverse
    - Insert
    - Delete
    - Linear search
    - Selection sort 

2. Implement operations on a  linked list and circular linked list:
    - Insertion & Deletion
        - at the beginning
        - at the specified location
        - at the end

3. Implement operations on a double linked list and circular double linked list:
    - Insertion & Deletion
        - at the beginning
        - at the specified location
        - at the end

4. Write a program to `count` the number of nodes & `reverse` the single linked list.

5. Implement operations `push` and `pop` on a stack using arrays. Check the status of the stack whether there is underflow or overflow.

6. Implement the `conversion` of infix notation to postfix notation

7. Implement `evaluation` of postfix notation using `stacks`.

8. Implement operations `enqueue` and `dequeue` on a queue using arrays. Check the status of the queue whether it is empty or full.

9. Implement a `circular queue` using arrays and linked list.

10. Implement `stacks` and `queues` using a linked list.

11. Implement `Sparse Array`.

12. Implement operations on `Binary Search Tree`:
    - Insertion
    - Deletion
    - Search
    - Traversals (using recursion)
        - Inorder
        - Preorder
        - Postorder

13. Implement traversals on `Binary Search Tree` (using stacks) 
    - Inorder
    - Preorder
    - Postorder

14. Implement `graph traversal`:
    - Depth-first Search (DFS).
    - Breadth-first Search (BFS).

15. Make a menu driven program to perform various `sorting` techniques
    - Insertion sort
    - Merge sort
    - Heap sort
    - Quick sort
    - Counting sort
    - Radix sort
    - Bucket sort

16. Implement `AVL tree`

17. Implement Kruskal’s and Prim’s `Minimum Spanning Tree` algorithms.

18. Make a menu driven program to perform various `shortest path algorithms `- Floyd Warshall, Bellman-Ford, Dijkstra.

19. Write a program to implement `Dynamic Programming Algorithms` - Matrix Chain Multiplication, Longest Common Subsequence.

20. Implement `Huffman Code Algorithm`.