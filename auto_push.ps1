"[$(Get-Date)] Script started" | Out-File "D:\Desktop\CP\auto_push_log.txt" -Append

$status = git status --porcelain

if ($status) {
    git add .

    $timestamp = Get-Date -Format "yyyy-MM-dd_HH:mm:ss"
    git commit -m "Auto commit $timestamp"

    git push origin main
}
"[$(Get-Date)] Script finished" | Out-File "D:\Desktop\CP\auto_push_log.txt" -Append
