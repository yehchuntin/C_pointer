---
layout: home
title: 首頁
---

# 歡迎來到 C 語言指標完全教學 🎯

這裡是最詳細、最易懂的 C 語言指標教學網站！

## 📚 關於這個教學

本教學將複雜的指標概念用簡單易懂的方式呈現，讓你從零基礎到完全掌握 C 語言指標。

## 🎯 學習目標

- 📌 理解指標的基本概念和記憶體模型
- 🔄 掌握指標與陣列、函式的關係
- 💾 學會動態記憶體管理
- 🚀 應用函式指標和回呼函式
- 🛡️ 避免常見的指標陷阱

## 💡 學習建議

1. **循序漸進**：按照文章順序學習
2. **動手實作**：每篇文章的程式碼都要親自執行
3. **理解原理**：不要死記語法，要理解背後的記憶體操作

---

## 📖 教學文章

{% for post in site.posts reversed %}
<div style="border: 1px solid #e1e4e8; border-radius: 6px; padding: 16px; margin: 16px 0; background-color: #f6f8fa;">
  <h3><a href="{{ post.url | relative_url }}" style="text-decoration: none; color: #0366d6;">{{ post.title }}</a></h3>
  <p style="color: #586069; font-size: 14px; margin: 8px 0;">{{ post.date | date: "%Y年%m月%d日" }}</p>
  <p style="margin: 8px 0;">{{ post.excerpt | strip_html | truncatewords: 30 }}</p>
  <a href="{{ post.url | relative_url }}" style="color: #0366d6; text-decoration: none; font-weight: 500;">閱讀全文 →</a>
</div>
{% endfor %}

開始你的指標學習之旅吧！ 🚀
