📋 **gloss 記述ガイドライン完全版 + 補助ファイル案**

---

### ✅ 1. gloss 定義ファイル（最新版）

**日本語版（nonLGR-abbreviations-ja.json）**

- 各 gloss 記号に日本語説明と使用例を記載。
- 例：

```json
{
  "CNTFCT": "反実仮想（counterfactual）：助動詞『まし』の現実に反する仮定・仮想の意味。例：見ましかば。",
  "POT": "可能（potential）：助動詞や接辞による可能性の意味。例：行ける、食べられる。"
}
```

**英語版（nonLGR-abbreviations-en.json）**

- 各 gloss 記号に英語説明と例を記載。
- 例：

```json
{
  "CNTFCT": "Counterfactual: auxiliary 'mashi' expressing hypothetical or counterfactual situations. Example: mimashikaba ('if I had seen').",
  "POT": "Potential: auxiliary or suffix expressing potentiality or possibility. Example: ikeru ('can go'), taberareru ('can eat')."
}
```

---

### ✅ 2. gloss ラベル一覧表（日本語・英語対照）

| 記号     | 日本語説明       | 英語説明            |
| -------- | ---------------- | ------------------- |
| CNTFCT   | 反実仮想         | Counterfactual      |
| POT      | 可能             | Potential           |
| NEG.BASE | 未然形           | Negation base       |
| ADV.F    | 連用形           | Adverbial form      |
| LEX.F    | 辞書形（終止形） | Lexical/finite form |
| AUX      | 助動詞           | Auxiliary           |
| Q        | 疑問             | Question particle   |

（必要に応じて全リストを詳細化します）

---

### ✅ 3. gloss 適用の自動整備スクリプト案

- 既存の gloss データを走査し、

  - 非標準記号を検出
  - 記号の一括置換（例：`counterfactual.AUX` → `CNTFCT`）
  - 記号漏れ（例：未記載の形態情報）の補完提案

Python/PHP スクリプト例を用意可能です。

---

### 📎 次のステップ

以下を指定していただければ、具体的なファイルやコードを作成します：
✅ 作成対象（例：日本語版定義ファイル / 英語版定義ファイル / 対照表 / スクリプト）
✅ 出力形式（例：JSON, Markdown, CSV, コードスニペット）

「この順でお願いします」または「まずは定義ファイルをください」など、指示をください！
すぐ準備します📂✨
