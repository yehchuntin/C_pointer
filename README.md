# C Pointers Notes

這個 repository 是針對 [Pointers in C/C++ (YouTube)](https://www.youtube.com/watch?v=zuegQmMdy8M) 影片所做的學習筆記。

---

## 目錄
- [1. Call by Reference](#1-call-by-reference)
  - [記憶體區塊](#記憶體區塊)
  - [傳址呼叫 (Call by Address)](#傳址呼叫-call-by-address)
  - [傳值呼叫 (Call by Value)](#傳值呼叫-call-by-value)
- [2. Pointers and Arrays](#2-pointers-and-arrays)
- [3. Array as function argument](#3-array-as-functions-argument)
- [4. Character arrays and pointers - part 1](#4-character-arrays-and-pointers-part1)
- [5. Character arrays and pointers - part 2](#5-character-arrays-and-pointers-part2)
- [6. Pointers and 2-D arrays](#6-Pointers-and-2-D-arrays)
- [7. Pointers and multidimensional arrays](#7-Pointers-and-multidimensional-arrays)
- [8. Pointers and dynamic memory - stack vs heap](#8-Pointers-and-dynamic-memory-stack-vs-heap)
- [9. Dynamic memory allocation in C - malloc calloc realloc free](#9-Dynamic-memory-allocation-in-C-malloc-calloc-realloc-free)
- [10. Pointers as Function Returns in C/C++](#10-pointers-as-function-returns-in-cc)
- [11. Function Pointers in C / C++](#11-function-pointers-in-c--c)
- [12. Function Pointers and Callbacks](#12-function-pointers-and-callbacks)
- [13. Memory Leak in C/C++](#13-memory-leak-in-cc)







---

## 1. Call by Reference
<img src="images/application-memory.png" width="350">

### 記憶體區塊
1. **Heap (堆積區)**
   - 用於動態記憶體配置（例如 `malloc`、`calloc`）。
   - 由程式設計師手動分配與釋放，否則可能造成記憶體洩漏。
   - 適合儲存大小未知或執行期間才決定的資料。

2. **Stack (堆疊區)**
   - 儲存函式的區域變數與參數。
   - 每次呼叫函式時，系統會建立一個新的「堆疊框架 (stack frame)」。
   - 當函式結束時，該堆疊框架會被釋放，記憶體自動回收。

3. **Static / Global (靜態/全域區)**
   - 儲存全域變數、靜態變數 (static)。
   - 這些變數在程式執行期間全程存在，直到程式結束才被釋放。

4. **Code (Text) 區**
   - 儲存程式的機器碼指令。
   - 通常為唯讀，避免程式被意外修改。

---

### 傳址呼叫 (Call by Address)
<img src="images/call-by-address.png" width="350">

[查看程式碼 ➜](1.callByReference/callByAddress.c)

---

### 傳值呼叫 (Call by Value)
<img src="images/call-by-value.png" width="350">

[查看程式碼 ➜](1.callByReference/callByValue.c)

---

## 2. Pointers and Arrays
<img src="images/pointers-and-arrays.png" width="500">

[查看程式碼 ➜](2.pointerAndArray/pointer-and-array.c)

---

### 陣列記憶體配置
```c
// int → 4 bytes
// int A[5] → 5 × 4 bytes = 20 bytes
// A 代表陣列的基底位址 (base address)
int A[5];
int *P;
P = A; // P 指向陣列 A 的基底位址

printf("%d\n", A);       // 印出 A (位址，例如 200)
printf("%d\n", *A);      // 印出 *A (A[0] 的值，例如 2)
printf("%d\n", A+1);     // A+1 → 下一個元素的位址 (例如 204)
printf("%d\n", *(A+1));  // *(A+1) → A[1] 的值 (例如 4)
```
### 元素存取方式
> **位址 (Address)** → &A[i] 或 (A + i)  
> **值 (Value)** → A[i] 或 *(A + i)

---

## 3. Array as Functions Argument

### ❌ 錯誤寫法
[查看程式碼 ➜](3.arrayAsFunctionArgument/wrong-array-in-functions.c)

⚠️ 錯誤原因：

>當陣列作為參數傳入函式時，會退化 (decay) 成指標。

>sizeof(A) 在 sum() 裡回傳的是指標大小（64 位元系統為 8 bytes），導致 size 錯誤。

>實際上陣列有 5 個元素，但 size 會變成 8 / 4 = 2。

---

### ✅ 正確版本：陣列傳遞到函式（指標方式）
[查看程式碼 ➜](3.arrayAsFunctionArgument/correct-array-in-functions.c)

💡 重點筆記
> **陣列在函式外**： sizeof(A) → 會回傳整個陣列大小（例如 5 × 4 = 20 bytes）。

> **陣列在函式內**： A 會退化成指標，sizeof(A) 變成指標大小（64 位元系統為 8 bytes）。

> **傳遞陣列時，必須額外傳遞「陣列大小」進入函式。**

> ***(A + i) 和 A[i] 兩者等效。**

---

### Call Array by Address
[查看程式碼 ➜](3.arrayAsFunctionArgument/array-call-by-address.c)

💡 重點筆記:

>**int *A**在函式參數中等同於 int A[]，陣列在傳遞時會退化為指標。

>**pow(x, 2)** 回傳 double，但在這裡會被自動轉型成 int 存回陣列。

>**&A[0]**取得陣列第一個元素的位址，用來傳遞給指標參數。

>**sizeof(A) / sizeof(A[0])** 用於計算陣列長度，避免寫死長度。


## 4. Character Arrays and Pointers Part1
<img src="images/basicCharacterArrayUsage.png" width="500">

[查看程式碼 ➜](4.characterArraysAndPointers/basicStringSkill.c)

💡 重點筆記：
```c
char C[] = "Mia and Ting"; //會自動在字串末尾加上 '\0'（字串結束符號）。

"Mia and Ting" 共 12 個字元 + '\0' → 共 13 bytes。

sizeof(C) //回傳陣列所佔的總記憶體大小（包含 '\0'）。

此例：13 bytes。

strlen(C) //回傳字串實際字元數量（不含 '\0'）。

此例：12。

printf("%s\n", C); //%s 會從陣列開頭印到 '\0' 為止。
```

>**💡補充說明：**

>**sizeof** → 編譯期運算，適合用來判斷陣列大小（含 '\0'）。

>**strlen** → 執行期運算，專門計算字串長度（不含 '\0'）。

## 5. Character Arrays and Pointers Part2

## 6. Pointers and 2-D Arrays

## 7. Pointers and Multidimensional Arrays

## 8. Pointers and Dynamic Memory-Stack vs Heap

## 9. Dynamic Memory Allocation in C-malloc calloc realloc free

## 10. Pointers as Function Returns in C/C++

## 11. Function Pointers in C / C++

## 12. Function Pointers and Callbacks

## 13. Memory Leak in C/C++
