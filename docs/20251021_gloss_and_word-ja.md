## **Gloss記述方針ノート**

Last change: 2025/10/21-12:41:32.

Hilofumi Yamamoto, Ph.D.

### ■ 基本理念

Gloss（語釈注）は、文の**意味構造**と**形態構造**を二層に分けて記述する。これにより、文全体の流れ（semantic
flow）と、各語の文法的関係（morphological relation）を明確に区別する。

### ■ 階層構造

Glossは二層構造で記録する。

| 層                          | 対応要素                | 主な目的                       | 活用形の扱い                        |
| --------------------------- | ----------------------- | ------------------------------ | ----------------------------------- |
| **Phrase gloss（句gloss）** | `"phrase"` と `"gloss"` | 文・句の意味的流れを簡潔に示す | **活用形は書かない**                |
| **Word gloss（語gloss）**   | `"words"` 配列内の各語  | 形態素の文法的機能を明示       | **活用形を表す（.ADV, .ATTRなど）** |

### ■ 記述例

#### Phrase gloss

```json
{
  "phrase": "夜更けぬとにやありけむ、やがていにけり。",
  "gloss": "night be.late PERF QUOT COP Q exist PST, immediately leave PST"
}
```

#### Word gloss

```json
{
  "words": [
    { "word": "夜", "gloss": "night" },
    { "word": "更け", "gloss": "be.late.ADV" },
    { "word": "ぬ", "gloss": "PERF" },
    { "word": "と", "gloss": "QUOT" },
    { "word": "に", "gloss": "COP.CONJ" },
    { "word": "や", "gloss": "Q" },
    { "word": "あり", "gloss": "EXIST" },
    { "word": "けむ", "gloss": "PST.SUPP" },
    { "word": "やがて", "gloss": "immediately" },
    { "word": "いに", "gloss": "go.ADV" },
    { "word": "けり", "gloss": "PST" }
  ]
}
```

### ■ 表記規則

1. **活用形の表記**
   - 動詞・助動詞などの活用語が**連用形**の場合：`.ADV`
   - **連体形**の場合：`.ATTR`
   - **已然形**の場合：`.REAL`（rarely used）
   - **終止形**の場合は特に付記しない。

2. **助詞の gloss**
   - 接続助詞「て」など：**CONJ**
   - 格助詞：「を」「に」「が」など：**ACC, DAT, NOM**
   - 係助詞：「や」「か」など：**Q（疑問）**, **FOC（焦点）** など

3. **助動詞の gloss**
   - 「ぬ」（完了）：**PERF**
   - 「けり」（過去・詠嘆）：**PST**
   - 「けむ」（過去推量）：**PST.SUPP**
   - 「む」（推量）：**SUPP**
   - 「なり」（断定）：**COP**
   - 「たり」（存続・結果）：**RES** または **CONT**

4. **存在動詞・断定助動詞の区別**
   - 「あり」：**EXIST**
   - 「なり」（断定）：**COP**
   - 「に」（断定助動詞「なり」連用形）：**COP.CONJ**

### ■ 理論的背景

この二層構造は、Leipzig Glossing Rules (LGR) の「morphological
tier」と「translation tier」の区別に基づく。phrase gloss は「translation
tier」に相当し、word gloss は「morphological tier」に相当する。

あなたの方式では、LGRの原則を踏まえつつ、古典日本語の形態的特徴（活用・助動詞連鎖）をより精密に扱えるように拡張している。

### ■ 運用上の利点

1. **自動整列処理が容易**
   - phrase gloss と words
     gloss を分離することで、語ごとの対応表を自動生成しやすくなる。

2. **意味層と形態層の独立性**
   - 翻訳研究・構文研究・即時文法研究など、分析目的ごとに必要な層だけを参照可能。

3. **可読性の向上**
   - gloss の複雑化を防ぎ、AEAD・Tosa・Ise 各プロジェクトで統一した形式を維持できる。

### ■ 備考

- この方針は、2025年10月21日時点の AEAD・古典翻訳プロジェクト両方に適用される。
- 将来的に自動解析ツール（例：`k2g`）との連携を考慮し、構文解析結果との整合を取ることを前提とする。
