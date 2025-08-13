---
layout: post
title: "第1章：指標簡介"
date: 2024-01-01 10:00:00 +0800
categories: [C語言, 指標, 基礎]
tags: [pointer, introduction]
excerpt: 指標是 C 語言最重要的概念之一。本文將介紹什麼是指標。
---

# 📌 指標簡介

指標（Pointer）是一種儲存**另一個變數位址**的變數。

<!--more-->

## 基本概念

- `P`表示位址（address）
- `*P`表示該位址中的值（value at address）

## 範例程式碼

```c
#include <stdio.h>

int main() {
    int a = 5;      // 一般整數變數
    int *p = &a;    // 指向整數的指標

    printf("a的值: %d\n", a);
    printf("a的位址: %p\n", &a);
    printf("p指向的位址: %p\n", p);
    printf("p指向的值: %d\n", *p);

    return 0;
}
