---
layout: post
title: "第1章：Introduction to pointers in C/C++"
date: 2025-08-13 10:00:00 +0800
categories: [C語言, 指標, 基礎]
tags: [pointer, introduction, basic]
excerpt: 指標是 C 語言最重要的概念之一。本文將從最基礎的角度介紹什麼是指標，以及指標與記憶體位址的關係。
---

# 📌 指標簡介

指標（Pointer）是一種儲存**另一個變數位址**的變數。

- `P`表示位址（address）
- `*P`表示該位址中的值（value at address），也稱為**解參考（dereferencing）**

<!--more-->

## 範例程式碼

```c
#include <stdio.h>

int main() {
    int a;      // 一般整數變數
    int *p;     // 指向整數的指標

    p = &a;     // p 儲存 a 的位址
    a = 5;      // a 存放值 5

    printf("p      = %p\n", p);   // 輸出 a 的位址
    printf("&a     = %p\n", &a);  // 輸出 a 的位址
    printf("&p     = %p\n", &p);  // 輸出 p 自己的位址
    printf("*p     = %d\n", *p);  // 透過指標取得 a 的值（5）

    *p = 8;     // 透過指標修改 a 的值
    printf("a      = %d\n", a);   // 輸出 8

    return 0;
}
```

## 記憶體示意圖

```
位址   | 內容
-----------------
204    | a = 8
64     | p = 204
```

- `p`存放`a`的位址（204）
- `*p`取出該位址的內容（即`a`的值）

## 💡 重點提醒

1. **指標儲存的是位址**，不是值
2. **`&` 運算子**用來取得變數的位址  
3. **`*` 運算子**用來取得指標指向的值（解參考）
4. 指標本身也有自己的位址

---

## 📖 文章導覽

**上一篇：** [← 回到首頁]({{ '/' | relative_url }})  
**下一篇：** 第2章即將推出...