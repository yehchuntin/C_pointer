---
layout: post
title: "第2章：Work with Pointers"
date: 2024-01-02 10:00:00 +0800
categories: [C語言, 指標, 基礎]
tags: [pointer, operations]
excerpt: 學會如何宣告指標、讓指標指向不同變數，以及進行基本的指標運算。
---

# Work with Pointers

在上一章中，我們學習了指標的基本概念。現在讓我們來學習如何實際操作指標。

<!--more-->

## 1️⃣ 宣告指標並指向變數

```c
int a = 10;
int *p;     // 宣告指向 int 的指標
p = &a;     // p 儲存 a 的位址
p → 存放的是位址（address）
*p → 存放該位址的值（value at address）

2️⃣ 讀取指標與變數資訊
cprintf("p = %p\n", p);     // p 目前指向的位址
printf("*p = %d\n", *p);   // p 所指向的值
printf("&p = %p\n", &p);   // p 自己的位址
💡 p指向哪個變數，*p就代表該變數的值。
3️⃣ 讓指標指向不同變數
cint b = 20;
p = &b;    // 改為指向 b

改變 p 指向的位置不會影響 p 自己的位址（&p 不變）
*p 會隨指向的變數不同而改變值

4️⃣ 指標運算（Pointer Arithmetic）
cprintf("p      = %p\n", p);     // 當前位址
printf("p + 1  = %p\n", p + 1); // 位址向後偏移 1 個 int

如果 p 是 int*，那麼 p + 1 會跳過 4 bytes（因為 sizeof(int) = 4）
位址的變化與所指向型態的大小有關

💡 本章重點

指標可以重新指向不同的變數
指標本身也有位址
指標運算的步幅取決於所指向的資料型別


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
        第三章即將推出...
      </span>
    {% endif %}
  </div>
</div>
```
