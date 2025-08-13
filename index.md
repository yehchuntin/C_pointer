---
layout: default
title: 首頁
---

<div class="home-container">
  <header class="hero">
    <div class="hero-icon">🎯</div>
    <h1>C 語言指標完全教學</h1>
    <p class="hero-subtitle">從零開始，深入淺出學會 C 語言指標</p>
  </header>

  <section class="learning-path">
    <div class="section-header">
      <h2>📖 學習路徑</h2>
      <p class="section-desc">按順序學習，循序漸進掌握指標概念</p>
    </div>
    
    <div class="chapters-grid">
      {% assign sorted_posts = site.posts | sort: 'date' %}
      {% for post in sorted_posts %}
      <div class="chapter-card">
        <div class="chapter-header">
          <span class="chapter-number">{{ forloop.index }}</span>
          <h3>
            <a href="{{ post.url | relative_url }}">{{ post.title | replace: '第1章：', '' | replace: '第2章：', '' | replace: '第3章：', '' }}</a>
          </h3>
        </div>
        <p class="chapter-desc">{{ post.excerpt | strip_html | truncatewords: 15 }}</p>
        <div class="chapter-meta">
          <span class="reading-time">⏱️ 約 5-10 分鐘</span>
        </div>
      </div>
      {% endfor %}
    </div>
  </section>

  <section class="intro">
    <div class="intro-header">
      <h2>💡 學習建議</h2>
    </div>
    <div class="tips-grid">
      <div class="tip-card">
        <div class="tip-icon">🎯</div>
        <h4>循序漸進</h4>
        <p>按照章節順序學習，每個概念環環相扣</p>
      </div>
      <div class="tip-card">
        <div class="tip-icon">⚡</div>
        <h4>動手實作</h4>
        <p>每個範例都要親自執行和驗證</p>
      </div>
      <div class="tip-card">
        <div class="tip-icon">🧠</div>
        <h4>理解原理</h4>
        <p>不要死記語法，要理解記憶體運作機制</p>
      </div>
    </div>
  </section>
</div>