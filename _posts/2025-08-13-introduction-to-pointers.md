---
layout: post
title: "第1章：Introduction to pointers in C/C++"
date: 2024-01-01 10:00:00 +0800
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

記憶體示意圖
位址   | 內容
-----------------
204    | a = 8
64     | p = 204

p存放a的位址（204）
*p取出該位址的內容（即a的值）

💡 重點提醒

指標儲存的是位址，不是值
& 運算子用來取得變數的位址
* 運算子用來取得指標指向的值（解參考）
指標本身也有自己的位址


導覽
<div style="display: flex; justify-content: space-between; margin-top: 40px; padding: 20px 0; border-top: 1px solid #eee;">
  <div>
    {% if page.previous %}
      <a href="{{ page.previous.url | relative_url }}" style="text-decoration: none; color: #0366d6;">
        ← {{ page.previous.title }}
      </a>
    {% else %}
      <a href="{{ '/' | relative_url }}" style="text-decoration: none; color: #0366d6;">
        ← 回到首頁
      </a>
    {% endif %}
  </div>
  <div style="text-align: right;">
    {% if page.next %}
      <a href="{{ page.next.url | relative_url }}" style="text-decoration: none; color: #0366d6;">
        {{ page.next.title }} →
      </a>
    {% else %}
      <span style="color: #999;">
        第二章即將推出...
      </span>
    {% endif %}
  </div>
</div>
```