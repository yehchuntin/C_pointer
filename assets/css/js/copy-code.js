// 複製程式碼功能
document.addEventListener('DOMContentLoaded', function() {
    // 為每個程式碼區塊加入複製按鈕
    document.querySelectorAll('.highlight').forEach(function(block) {
        const button = document.createElement('button');
        button.className = 'copy-button';
        button.innerHTML = '📋 複製';
        button.setAttribute('aria-label', '複製程式碼');
        
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
        
        block.appendChild(button);
    });
    
    // 複製成功提示
    function showCopySuccess(button) {
        const originalText = button.innerHTML;
        button.innerHTML = '✅ 已複製';
        button.classList.add('copied');
        
        setTimeout(function() {
            button.innerHTML = originalText;
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
            button.innerHTML = '❌ 複製失敗';
            setTimeout(function() {
                button.innerHTML = '📋 複製';
            }, 2000);
        }
        
        document.body.removeChild(textarea);
    }
});