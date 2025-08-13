// 複製程式碼功能
document.addEventListener('DOMContentLoaded', function() {
    // 為每個程式碼區塊加入複製按鈕
    document.querySelectorAll('.highlight').forEach(function(block, index) {
        // 建立複製按鈕容器
        const buttonContainer = document.createElement('div');
        buttonContainer.className = 'code-header';
        
        // 建立語言標籤
        const languageLabel = document.createElement('span');
        languageLabel.className = 'language-label';
        languageLabel.textContent = 'C';
        
        // 建立複製按鈕
        const button = document.createElement('button');
        button.className = 'copy-button';
        button.innerHTML = `
            <svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                <rect x="9" y="9" width="13" height="13" rx="2" ry="2"></rect>
                <path d="M5 15H4a2 2 0 0 1-2-2V4a2 2 0 0 1 2-2h9a2 2 0 0 1 2 2v1"></path>
            </svg>
            <span>複製</span>
        `;
        button.setAttribute('aria-label', '複製程式碼');
        
        // 組合按鈕容器
        buttonContainer.appendChild(languageLabel);
        buttonContainer.appendChild(button);
        
        // 插入到程式碼區塊前面
        block.insertBefore(buttonContainer, block.firstChild);
        
        // 加入點擊事件
        button.addEventListener('click', function() {
            const code = block.querySelector('pre').textContent;
            
            // 使用 Clipboard API
            if (navigator.clipboard && window.isSecureContext) {
                navigator.clipboard.writeText(code).then(function() {
                    showCopySuccess(button);
                }).catch(function() {
                    fallbackCopy(code, button);
                });
            } else {
                fallbackCopy(code, button);
            }
        });
    });
    
    // 複製成功提示
    function showCopySuccess(button) {
        const originalHTML = button.innerHTML;
        button.innerHTML = `
            <svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                <polyline points="20,6 9,17 4,12"></polyline>
            </svg>
            <span>已複製</span>
        `;
        button.classList.add('copied');
        
        setTimeout(function() {
            button.innerHTML = originalHTML;
            button.classList.remove('copied');
        }, 2000);
    }
    
    // 備用複製方法
    function fallbackCopy(text, button) {
        const textarea = document.createElement('textarea');
        textarea.value = text;
        textarea.style.position = 'fixed';
        textarea.style.opacity = '0';
        document.body.appendChild(textarea);
        textarea.select();
        
        try {
            document.execCommand('copy');
            showCopySuccess(button);
        } catch (err) {
            console.error('複製失敗:', err);
            const originalHTML = button.innerHTML;
            button.innerHTML = `
                <svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                    <circle cx="12" cy="12" r="10"></circle>
                    <line x1="15" y1="9" x2="9" y2="15"></line>
                    <line x1="9" y1="9" x2="15" y2="15"></line>
                </svg>
                <span>複製失敗</span>
            `;
            setTimeout(function() {
                button.innerHTML = originalHTML;
            }, 2000);
        }
        
        document.body.removeChild(textarea);
    }
});