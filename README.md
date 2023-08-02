# 算法競賽代碼庫

## 代碼庫結構

代碼庫分爲兩級，將代碼文件保存在 `src/` 目錄下的子目錄中。
用 `codelib.yaml` 配置。

```
- category: 基本配置
  dir: config/
  docs:
    - title: 快速讀寫
      fname: fastio.cpp
      desc: 基於緩衝區的快速讀寫。
```

文件名或描述缺失時需要填寫爲 `null`。

## 代碼庫編譯

字體使用了霞鶩文楷和 Fira Code。
使用 typst 編譯即可。