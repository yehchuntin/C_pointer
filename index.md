---
layout: home
title: 首頁
---

<div class="hero-section">
  <h1>🎯 C 語言指標完全教學</h1>
  <p class="lead">深入淺出學會 C 語言指標，從基礎到進階的完整教學</p>
</div>

## 📚 關於這個教學

本教學將複雜的指標概念用簡單易懂的方式呈現，讓你從零基礎到完全掌握 C 語言指標。

## 🎯 學習目標

- **理解指標的基本概念**和記憶體模型
- **掌握指標與陣列**、函式的關係  
- **學會動態記憶體管理**
- **應用函式指標**和回呼函式
- **避免常見的指標陷阱**

## 💡 學習建議

1. **循序漸進**：按照文章順序學習
2. **動手實作**：每篇文章的程式碼都要親自執行
3. **理解原理**：不要死記語法，要理解背後的記憶體操作

---

## 📖 教學文章

{% for post in site.posts reversed %}
<article class="post-preview">
  <h3><a href="{{ post.url | relative_url }}">{{ post.title }}</a></h3>
  <p class="post-meta">{{ post.date | date: "%Y年%m月%d日" }}</p>
  <p>{{ post.excerpt | strip_html | truncatewords: 30 }}</p>
  <a href="{{ post.url | relative_url }}" class="nav-button">開始閱讀 →</a>
</article>
{% endfor %}

<div style="text-align: center; margin-top: 40px;">
  <p>🚀 <strong>準備好開始你的指標學習之旅了嗎？</strong></p>
</div>