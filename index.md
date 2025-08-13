---
layout: default
title: 首頁
---

<div class="home-container">
  <header class="hero">
    <h1>🎯 C 語言指標完全教學</h1>
    <p class="hero-subtitle">從零開始，深入淺出學會 C 語言指標</p>
  </header>

  <section class="learning-path">
    <h2>📖 學習路徑</h2>
    <div class="chapters-grid">
      {% assign sorted_posts = site.posts | reverse %}
      {% for post in sorted_posts %}
      <div class="chapter-card">
        <h3>
          <a href="{{ post.url | relative_url }}">{{ post.title }}</a>
        </h3>
        <p>{{ post.excerpt | strip_html | truncatewords: 15 }}</p>
      </div>
      {% endfor %}
    </div>
  </section>

  <section class="intro">
    <h2>💡 學習建議</h2>
    <ul>
      <li><strong>循序漸進</strong>：按照章節順序學習</li>
      <li><strong>動手實作</strong>：每個範例都要親自執行</li>
      <li><strong>理解原理</strong>：不要死記語法，要理解記憶體運作</li>
    </ul>
  </section>
</div>