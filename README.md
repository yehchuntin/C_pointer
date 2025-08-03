# C Pointers Notes

這個 repository 是針對 [Pointers in C/C++ (YouTube)](https://www.youtube.com/watch?v=zuegQmMdy8M) 影片所做的學習筆記。

---

## 目錄
- [Call by Reference](#call-by-reference)
  - [記憶體區塊](#記憶體區塊)
  - [傳址呼叫 (Call by Address)](#傳址呼叫-call-by-address)
  - [傳值呼叫 (Call by Value)](#傳值呼叫-call-by-value)
- [Pointers and Arrays](#pointers-and-arrays)

---

## Call by Reference
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

[查看程式碼 ➜](callByAddress.c)

---

### 傳值呼叫 (Call by Value)
<img src="images/call-by-value.png" width="350">

[查看程式碼 ➜](callByValue.c)

---

## Pointers and Arrays
[查看程式碼 ➜](pointer-and-a<img src="images/pointers-and-arrays.png" width="500">
陣列記憶體配置
int → 4 bytes
int A[5] → 5 × 4 bytes = 20 bytes
A 代表陣列的基底位址（base address）rray.c)

透過指標存取
int A[5];
int *P;
P = A; // P 指向陣列 A 的基底位址

printf("%d\n", A);   // 印出 A (位址，例如 200)
printf("%d\n", *A);  // 印出 *A (A[0] 的值，例如 2)
printf("%d\n", A+1); // A+1 → 下一個元素的位址 (例如 204)
printf("%d\n", *(A+1)); // *(A+1) → A[1] 的值 (例如 4)

### 元素存取方式
> **位址 (Address)** → `&A[i]` 或 `(A + i)`  
> **值 (Value)** → `A[i]` 或 `*(A + i)`
