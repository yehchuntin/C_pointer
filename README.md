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
  - [字串基本概念](#字串基本概念)
  - [字串與指標](#字串與指標)
  - [用字元指標將字串傳入函式](#用字元指標將字串傳入函式)
- [5. Character arrays and pointers - part 2](#5-character-arrays-and-pointers-part2)
  - [記憶體與Stack解析 ](#記憶體與Stack解析) 
  - [唯讀記憶體 (Read-Only Data Segment)](#唯讀記憶體-read-only-data-segment)
- [6. Pointers and 2-D arrays](#6-Pointers-and-2-D-arrays)
  - [2D 指標陣列的使用](#2d-指標陣列的使用) 
  - [2維陣列的存取等價式](#二維陣列的存取等價式)


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
   >用於動態記憶體配置（例如 `malloc`、`calloc`）。

   >由程式設計師手動分配與釋放，否則可能造成記憶體洩漏。

   >適合儲存大小未知或執行期間才決定的資料。

2. **Stack (堆疊區)**
   >儲存函式的區域變數與參數。

   >每次呼叫函式時，系統會建立一個新的「堆疊框架 (stack frame)」。

   >當函式結束時，該堆疊框架會被釋放，記憶體自動回收。

3. **Static / Global (靜態/全域區)**
   >儲存全域變數、靜態變數 (static)。

   >這些變數在程式執行期間全程存在，直到程式結束才被釋放。

4. **Code (Text) 區**
   >儲存程式的機器碼指令。

   >通常為唯讀，避免程式被意外修改。

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
```c
(1) 當陣列作為參數傳入函式時，會退化 (decay) 成指標。

(2) sizeof(A) 在 sum() 裡回傳的是指標大小（64 位元系統為 8 bytes），導致 size 錯誤。

(3) 實際上陣列有 5 個元素，但 size 會變成 8 / 4 = 2。
```
---

### ✅ 正確版本：陣列傳遞到函式（指標方式）
[查看程式碼 ➜](3.arrayAsFunctionArgument/correct-array-in-functions.c)

💡 重點筆記
```c
(1) 陣列在函式外： sizeof(A)  //會回傳整個陣列大小（例如 5 × 4 = 20 bytes）。

(2) 陣列在函式內： A 會退化成指標，sizeof(A) 變成指標大小（64 位元系統為 8 bytes）。

(3) 傳遞陣列時，必須額外傳遞「陣列大小」進入函式。

(4) *(A + i) 和 A[i] 兩者等效。
```
---

### Call Array by Address
[查看程式碼 ➜](3.arrayAsFunctionArgument/array-call-by-address.c)

💡 重點筆記:
```c
(1) int *A在函式參數中等同於 int A[]，陣列在傳遞時會退化為指標。

(2) pow(x, 2) 回傳 double，但在這裡會被自動轉型成 int 存回陣列。

(3) &A[0]取得陣列第一個元素的位址，用來傳遞給指標參數。

(4) sizeof(A) / sizeof(A[0])用於計算陣列長度，避免寫死長度。
```
---

## 4. Character Arrays and Pointers Part1
### 字串基本概念
[查看程式碼 ➜](4.characterArraysAndPointers/basicStringSkill.c)

<img src="images/basicCharacterArrayUsage.png" width="500">

💡 重點筆記：
```c
(1) char C[] = "Mia and Ting"; //會自動在字串末尾加上 '\0'（字串結束符號）。

(2) "Mia and Ting" 共 12 個字元 + '\0' → 共 13 bytes。

(3) sizeof(C) //回傳陣列所佔的總記憶體大小（包含 '\0'）。

此例：13 bytes。

(4) strlen(C) //回傳字串實際字元數量（不含 '\0'）。

此例：12。

(5) printf("%s\n", C); //%s 會從陣列開頭印到 '\0' 為止。
```
---
### 字串與指標
[查看程式碼 ➜](4.characterArraysAndPointers/stringAndPointer.c)

<img src="images/stringAndPointer.png" width="500">

💡 重點筆記：
```c
(1) char C[6] = "Hello"; //建立一個字元陣列（含 '\0'）。

(2) sizeof(c1) //c1 是指標 → 回傳指標大小（64-bit 環境通常為 8 bytes）。

(3) c1 = C;
// C 代表陣列的起始位址（等同 &C[0]）。
// 不能寫 c1 = &C;，因為 &C 型態是 char (*)[6]。

(4) c1[0] = 'A'; // 修改字串第一個字元，結果變為 "Aello"。

(5) *(c1+2) // →  C[2]
// * → 取值 → l。
```

---
### 用字元指標將字串傳入函式
[查看程式碼 ➜](4.characterArraysAndPointers/stringAsFunctionArgument.c)

<img src="images/stringAsFunctionArgument.png" width="500">

💡 重點筆記：
```c
(1) 陣列傳入函式時會自動轉換成指標：print(C) → print(char *C)。

(2) char *C //會指向傳入陣列的第一個元素 (C[0])。

(3) 透過指標可以直接存取或修改原陣列內容（不需回傳）。

(4) *(C+i) 等同於 C[i]，都是利用指標偏移取得字元。

(5) while(C[i] != '\0')：用 '\0' 判斷字串結尾。
```

## 5. Character Arrays and Pointers Part2
### 記憶體與Stack解析 
[查看程式碼 ➜](4.characterArraysAndPointers/stringAsFunctionArgument.c)

<img src="images/explanationOfMemoryAndStack.png" width="500">

💡 重點筆記
```c
(1) print(C) 
//陣列 C 自動轉換成指向 C[0] 的指標。
//在print()的stack frame 中，建立一個新的指標變數C，此指標指向main的陣列起始位置 100。

(2) 函式結束
//print()結束後，stack中print()的區域變數（包括C這個指標被釋放，但main裡的原本陣列 C[20] 仍存在。
```

---
### 唯讀記憶體 (Read-Only Data Segment)
[詳細筆記 (HackMD)](https://hackmd.io/@SSWinCCUEE/H1NE8wpyK)

[Wikipedia](https://en.wikipedia.org/wiki/Data_segment)

[維基百科](https://zh.wikipedia.org/zh-tw/%E5%94%AF%E8%AE%80%E8%A8%98%E6%86%B6%E9%AB%94)

1️⃣ 程式碼分析
```c
//char C[20] = "Hello"; // 字串被存放在 stack 區域的陣列
char *C = "Hello";      // 字串被存放在 .rodata (唯讀常量區)
C[0] = 'A';             // ❌ 這裡會導致 Segmentation Fault (嘗試修改唯讀記憶體)
```
>char C[20] = "Hello"; //配置 20 bytes 的陣列於 stack。

>char *C = "Hello"; //"Hello" 存放在程式的 唯讀記憶體 (read-only data segment)。

>C 是指向常量字串的指標 → 嘗試 C[0] = 'A'; 會造成 執行期錯誤 (Segmentation Fault)。


2️⃣ 主要錯誤
你不能修改 char *C = "Hello"; 指向的內容，因為這是一個編譯期常量。
正確的作法：
```c
char C[20] = "Hello"; // OK: 可以修改
C[0] = 'A';           // 合法
```
或者如果要使用指標：
```c
const char *C = "Hello"; // 指向常量，不能修改內容
// C[0] = 'A'; // ❌ 編譯錯誤（防止 runtime crash）
```

3️⃣ 💡 重點
```c
(1) 陣列宣告 (char C[]) → 可修改內容 (stack 變數)

(2) 指標指向字串常量 (char *C = "...") → **不可修改內容 (read-only segment)**

(3) 嘗試修改字串常量會導致 **Segmentation Fault**。
```
---

## 6. Pointers and 2-D Arrays
### 2D 指標陣列的使用
<img src="images/pointerAnd2dArray(1).png" width="500">

2-D陣列與指標陣列的宣告
```c
int B[2][3];  // 二維陣列，2 列 × 3 欄
int (*p)[3] = B;  // p 是指向含有 3 個 int 的陣列的指標
```
記憶體配置
```c
地址:  400  404  408  412  416  420
值:     2    3    6    4    5    8
       B[0][0] ... B[0][2] B[1][0] ... B[1][2]
```
int (*p)[3]
```c
(1) p 是一個「指向含有 3 個整數的陣列」的指標。

(2) 因為 B 是 int[2][3]，所以 p 可以直接指向 B。

(3)「其實只用到兩個元素（B[0], B[1]）」是對的，因為這個陣列只有兩列。
```
指標與位址
| 表達式            | 說明                               | 結果 |
|-------------------|------------------------------------|------|
| `B`               | 等同 `&B[0]`，第一列位址           | 400  |
| `*B`              | 等同 `B[0]`，第一列的起始位址      | 400  |
| `B+1`             | 等同 `&B[1]`，第二列位址           | 412  |
| `*(B+1)`          | 等同 `B[1]`，第二列起始位址        | 412  |
| `*(B+1)+2`        | 等同 `&B[1][2]`，第二列第 3 個元素 | 420  |
| `*(*B+1)`         | 取值 → `B[0][1]`                  | 3    |

重點
```c
(1) B //在大多數運算中會退化為「指向列的指標」。

(2) *B //代表第一列；B+1 代表第二列。

(3) *(*B+1) //是多層解參考，最後取得B[0][1]的值。
```

---
### 二維陣列的存取等價式
存取等價式
```c
B[i][j] = * (B[i] + j)
        = * ( * (B + i) + j )
```
- B[i] 代表第 i 列，是指向 int[3] 的指標。

- B[i] + j 將指標位移到第 j 個元素。

- 最外層 * 解參考，取得值。
---

## 7. Pointers and Multidimensional Arrays

## 8. Pointers and Dynamic Memory-Stack vs Heap

## 9. Dynamic Memory Allocation in C-malloc calloc realloc free

## 10. Pointers as Function Returns in C/C++

## 11. Function Pointers in C / C++

## 12. Function Pointers and Callbacks

## 13. Memory Leak in C/C++
