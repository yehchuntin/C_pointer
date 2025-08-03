# C Pointers Notes

這個 repository 是針對 [Pointers in C/C++ (YouTube)](https://www.youtube.com/watch?v=zuegQmMdy8M) 影片所做的學習筆記。

---

## 1️⃣ 應用程式記憶體結構
![應用程式記憶體結構](images/application-memory.png)

### 記憶體區塊：
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

## 2️⃣ Call by Address (傳址呼叫)
![Call by Address](images/call-by-address.png)
![code](callByAdress.c)

## 2️⃣ Call by Value (傳值呼叫)
![Call by Value](images/call-by-value.png)
![code](callByValue.c)

